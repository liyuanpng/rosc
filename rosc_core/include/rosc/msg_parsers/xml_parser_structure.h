/*
 *	Copyright (c) 2013, Synapticon GmbH
 *	All rights reserved.
 *
 *	Redistribution and use in source and binary forms, with or without
 *	modification, are permitted provided that the following conditions are met:
 *
 *	1. Redistributions of source code must retain the above copyright notice, this
 *	   list of conditions and the following disclaimer.
 *	2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 *	ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *	The views and conclusions contained in the software and documentation are those
 *	of the authors and should not be interpreted as representing official policies,
 *	either expressed or implied, of the FreeBSD Project.
 *
 *  xml_parser_structure.h created by Christian Holl
 */


#ifndef PARSER_STRUCTURE_H_
#define PARSER_STRUCTURE_H_

#include <rosc/string_res/msg_strings.h>
#include <rosc/system/eth.h>
#include <rosc/system/ports.h>
#include <rosc/rosc.h>
#include <rosc/system/types.h>
#include <rosc/msg_parsers/sub/subs.h>

#define __XML_MAX_DEPTH__ 20

typedef bool(*parser_submode_function_t)(char **buf_ptr, int32_t *len_ptr, void *data);


/**
 * This enum contains the state for the xml parsing
 */
typedef enum
{
	PARSE_XML_INIT,
	PARSE_XML_ROOT,
	PARSE_XML_INNER,
	PARSE_XML_TAG_START,
	PARSE_XML_TAG,
	PARSE_XML_CLOSE_TAG_START,
	PARSE_XML_EXPECT_SELFCLOSE_TAG_END,
	PARSE_XML_CDATA,
	PARSE_XML_CDATA_START,
	PARSE_XML_CDATA_EXPECT_OPEN_BRACKET,
	PARSE_XML_CDATA_FIRST_CLOSE_BRACKET,
	PARSE_XML_CDATA_SECOND_CLOSE_BRACKET,
	PARSE_XML_QMTAG_EXPECT_CLOSE,
	PARSE_XML_COMMENT_START_1ST_DASH,
	PARSE_XML_COMMENT,
	PARSE_XML_COMMENT_END_1ST_DASH,
	PARSE_XML_COMMENT_END_2ND_DASH,
	PARSE_XML_ATTRIBUTE_WAIT_EQUAL,
	PARSE_XML_ATTRIBUTE_WAIT_VAL_BOUND,
	PARSE_XML_ATTRIBUTE_INSIDE_APOSTROPHE_ATTRIB,
	PARSE_XML_ATTRIBUTE_INSIDE_QUOTES_ATTRIB,
	PARSE_XML_INNER_CONTENT,
}parse_xml_state_t;

typedef enum
{
	PARSE_XML_SUB_STATE_NONE,
	PARSE_XML_SUB_TAG_ID,
	PARSE_XML_SUB_ATTRIBUTE_ID,
	PARSE_XML_SUB_COMMENT_END_1ST_DASH,
	PARSE_XML_SUB_COMMENT_END_2ND_DASH,
	PARSE_XML_SUB_CDATA_TAG_STRING,
}parse_xml_sub_state_t;

/**
 * This enum contains the number for each known tag
 */
typedef enum
{
	XML_TAG_UNKNOWN=-2,
	XML_TAG_NONE=-1,
	__RPC_XML_TAG_STRINGS(XML) //!< imports all string numbers from autogenerated file
}parse_xml_tags_t;

/**
 * XML Attributes
 */
typedef enum
{
	XML_ATTRIBUTE_UNKNOWN=-2,
	XML_ATTRIBUTE_NONE=-1,
	__RPC_XML_ATTRIBUTE_STRINGS(XML)
}parse_xml_attrib_t;



typedef enum
{
	XML_TAG_TYPE_NORMAL,
	XML_TAG_TYPE_CLOSE,
	XML_TAG_TYPE_QUESTION_MARK,
	XML_TAG_TYPE_EXCLAMATION_MARK,
	XML_TAG_TYPE_COMMENT,
	XML_TAG_TYPE_CDATA,
}
parse_xml_tag_type_t;


/**
 * Contains events for the handler for it to know what currently happened
 */
typedef enum
{
	PARSE_EVENT_ERROR_HTTP_CONTENT_LENGTH_TOO_LONG=-100,//!< means the content exceeds the specified max lenght
	PARSE_EVENT_ERROR_HTTP_CONTENT_LENGTH,              //!< means that the content length is now available
	PARSE_EVENT_ERROR_HTTP_NOT_FOUND,                   //!< means that the target/action/url was not found in the string array (code: 404)
	PARSE_EVENT_ERROR_HTTP_VERSION_NOT_SUPPORTED,       //!< means that the HTTP version is not supported (code: 505)
	PARSE_EVENT_ERROR_HTTP_BAD_REQUEST,                 //!< means that something is wrong inside the http header
	PARSE_EVENT_ERROR_HTTP_LENGTH_REQUIRED,             //!< means that now length was given in the http header
	PARSE_EVENT_ERROR_HTTP_METHOD_NOT_ALLOWED,          //!< means that the given method string did not match any of those in the string array
	PARSE_EVENT_ERROR_HTTP_CONTENT_TYPE,                //!< means that the content type given in http header is not supported
	PARSE_EVENT_ERROR_HTTP_CONTENT_ENCODING,            //!< means that the content encoding is set (which is not supported by a stream parser -> cause of compression...)
	PARSE_EVENT_ERROR_HTTP_BAD_RESPONSE,                //!< means that something is wrong in the received response
	PARSE_EVENT_ERROR_XML_DEPTH,                        //!< means that the depth of the current xml document is too depth to be handled
	PARSE_EVENT_ERROR_XML_MALFORMED,                    //!< means that something inside the xml document is wrong


	PARSE_EVENT_NONE=0,                                 //!< means that there is no event atm.

	PARSE_EVENT_HANDLER_INIT,                           //!< can be used to initialize the handlers data storage
	PARSE_EVENT_HTTP_METHOD_PARSED,                     //!< means that the method string of the http header was parsed
	PARSE_EVENT_HTTP_ACTION_PARSED,                     //!< means that the action (url, uri string) was parsed

	PARSE_EVENT_HTTP_HEADER_FIELD_CONTENT,              //!< means that the http parser reached content inside a http field
	PARSE_EVENT_HTTP_RESPONSE_CODE,                     //!< means that the response code is now available (client)

	//XML
	PARSE_EVENT_XML_TAG,                                //!< means that a xml tag is found and the parser is now after the tag string
	PARSE_EVENT_XML_INSIDE_TAG,                         //!< means that the parser entered the tag and is now after the '>'
	PARSE_EVENT_XML_HANDLER_CALLED_SUBMODE_FINISHED,    //!< means that the submode called from the handler is finished
	PARSE_EVENT_XML_CONTENT_START,                      //!< means that the parser found content inside a tag and now is at its beginning
}parse_event_t;





/**
 * This enum contains the number of each known http method
 */
typedef enum
{
	__HTTP_METHODS(ENUM) //!< imports all string numbers from autogenerated file
}parse_http_methods_t;


/**
 * Contains the header descriptors
 */
typedef enum
{
	__HTTP_HEADER_DESCRIPTORS(PARSE_HTTP)//!< __HTTP_HEADER_DESCRIPTORS inserts auto generated list of header descriptors
}parse_http_desc_t;

/**
 * Substates for handling the results of called submodes in http parser
 */
typedef enum
{
	/*Special states for parsing a request (server)*/
	PARSE_HTTP_STATE_REQUEST_METHOD,          //!< in this state the parser expects the method string of a request
	PARSE_HTTP_STATE_REQUEST_ACTION,          //!< in this state the parser expects the action string of a request
	PARSE_HTTP_STATE_REQUEST_HTTP_VER,        //!< in this state the parser expects the http version of a request

	/*Special states for parsing a response (client)*/
	PARSE_HTTP_STATE_RESPONSE_HTTP_VER,       //!< in this state the parser expects the http version of a response
	PARSE_HTTP_STATE_RESPONSE_CODE,           //!< in this state the parser expects the http response code
	PARSE_HTTP_STATE_RESPONSE_STRING,         //!< in this state the parser waits for a line feed

	/*Common states*/
	PARSE_HTTP_STATE_HEADLINE_WAIT_END,       //!< in this state the parser waits for a line feed at the end of a requests headline
	PARSE_HTTP_STATE_DESCRIPTOR_OR_HEADER_END,//!< in this state the parser expects the start of a new field or a linefeed for the header end
	PARSE_HTTP_STATE_DESCRIPTOR_FIELD_SEPARATOR,    //!< in this state the parser waits for a double point and only accepts spaces
	PARSE_HTTP_STATE_FIELD,                   //!< this state is reached after the parser finds a double point after the field name
	PARSE_HTTP_STATE_FIELD_CONTENT,           //!< this state is entered by the parser if it finds content inside a header field
}parse_http_state_t;

/**
 * This
 */
typedef enum
{
	PARSE_HTTP_SUB_STATE_NONE,             //!< PARSE_HTTP_SUB_STATE_NONE
	PARSE_HTTP_SUB_CHECK_METHOD,           //!< PARSE_HTTP_SUB_CHECK_METHOD
	PARSE_HTTP_SUB_CHECK_ACTION,           //!< PARSE_HTTP_SUB_CHECK_ACTION
	PARSE_HTTP_SUB_CHECK_REQUEST_HTTP_VER, //!< PARSE_HTTP_SUB_CHECK_REQUEST_HTTP_VER
	PARSE_HTTP_SUB_CHECK_DESCRIPTOR_ID,    //!< PARSE_HTTP_SUB_CHECK_DESCRIPTOR_ID
	PARSE_HTTP_SUB_CHECK_CONTENT_LENGTH,   //!< PARSE_HTTP_SUB_CHECK_CONTENT_LENGTH
	PARSE_HTTP_SUB_CHECK_CONTENT_TYPE,     //!< PARSE_HTTP_SUB_CHECK_CONTENT_TYPE
	PARSE_HTTP_SUB_CHECK_RESPONSE_HTTP_VER,//!< PARSE_HTTP_SUB_CHECK_RESPONSE_HTTP_VER
	PARSE_HTTP_SUB_CHECK_RESPONSE_CODE,    //!< PARSE_HTTP_SUB_CHECK_RESPONSE_CODE
	PARSE_HTTP_SUB_CHECK_RESPONSE_STATE,   //!< PARSE_HTTP_SUB_CHECK_RESPONSE_STATE
}parse_http_sub_state_t;


/**
 * This enum contains the two main modes of the parser
 */
typedef enum
{
	PARSE_MODE_HEADER,//!< PARSE_MODE_HEADER is when parsing the header
	PARSE_MODE_XML,   //!< PARSE_MODE_XML is when parsing the xml
}parse_mode_t;


//*
// * This enum contains the states for the current submode
// */
//typedef enum
//{
//	PARSE_SUBMODE_NONE,            //!< means that no submode is active
//	PARSE_SUBMODE_SEEKSTRING,      //!< means that the parser currently seeks a string inside an array
//	PARSE_SUBMODE_NUMBERPARSE,     //!< means that currently the number parser is in operation
//	PARSE_SUBMODE_COPY2BUFFER,     //!< means that currently a string is copied into another location
//	PARSE_SUBMODE_SKIPUNTILCHAR,   //!< means that currently everything is skipped till a specified char is received
//	PARSE_SUBMODE_SKIPWHOLEMESSAGE,//!< means that the parser is currently skipping the whole message
//}submode_t;


/**
 * Values for the state of the current submode
 */
typedef enum
{
	PARSE_SUBMODE_INIT,    //!< means it was not initialized yet
	PARSE_SUBMODE_RUNNING, //!< means that the submode is running
	PARSE_SUBMODE_FINISHED,//!< means that the submode has finshed
}parse_submode_state_t;





/**
 * Definition for handler function type
 */
typedef struct parse_act_t
{

	struct port_t* port; //!< This contains the port ID of the port the server/client is connected to

	void (*handler_fkt)(void *); //!< This function handles the parser events
	void *handler_data_storage;	//!< This is a pointer for different handlers data storage
	int32_t content_length; //!< xml_length stores the length parsed from the http header

	uint32_t content_curChr; //!< xml_curChr keeps the current xml char number
	parse_mode_t mode; //!< mode saves contains the current main mode, xml or http header parsing
	parser_submode_function_t submode;

	parse_submode_state_t submode_state; //!< is one when submode is finished
	int16_t submode_result;	//!< contains the result code from each submode when finished
	bool submode_by_handler; //!< needs to be set when the submode is started by the handler function
	parse_event_t event; //!< tells the handler function what currently has happened.


	/**
	 * The mode_data union stores the http and the xml data inside the same memory location.
	 * This is used for saving memory space, because the variables are not used the same time.
	 */
	union
	{
		struct
		{
			parse_http_state_t state; //!< state contains the current state of the http parser
			parse_http_sub_state_t sub_state; //!< contains the substate of the http parser (analyzing results of submodes)
			parse_http_desc_t descriptor; //!< descriptor contains the current known descriptor
			uint8_t content_type_text_xml_found; //!< checks if the text/xml content type was found.

		}http;

		struct
		{
			uint16_t depth;	//!< depth stores the depth of the current location of the parser
			uint32_t processed_bytes; //!< currently processed bytes of the xml part (updated after each chunk)
			parse_xml_tags_t current_tag; //!< current_tag contains the current known xml tag
			parse_xml_tag_type_t tag_type; //!< normal, ! or ? tag.
			parse_xml_attrib_t attribute; //!< shows the attribute if inside an attribute otherwise XML_ATTRIBUTE_NONE
			parse_xml_state_t state; //!< contains the current state of the xml parser
			parse_xml_sub_state_t sub_state; //!< gives additional state information
			parse_xml_tags_t tags[__XML_MAX_DEPTH__]; //!< array for checking tag validity
		}xml;
	}mode_data;

	/**
	 * submode_data contains the data for the different submodes
	 */
	union
	{
		seekstring_data_t  seekstring;
		numberparse_data_t numberparse;
		copy2buffer_data_t copy2buffer;
		parseurl_data_t    parseurl;
	}submode_data;

}parse_act_t;


/**
 * Definition for handler function type
 */
typedef void (*parse_handler_fct)(parse_act_t *pact);
typedef void (*parse_handler_fct_cast)(void *pact);




#endif /* PARSER_STRUCTURE_H_ */
