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
 *  ros_parser.h created by Christian Holl
 */

#ifndef ROS_PARSER_H_
#define ROS_PARSER_H_

#include <rosc/string_res/msg_strings.h>
#include <rosc/system/eth.h>
#include <rosc/system/ports.h>
#include <rosc/rosc.h>

/**
 * Specifies the type of the tcpros parser for
 * the initialization.
 */
typedef enum
{
	ROS_TYPE_TOPIC_PUBLISHER, //!< TOPIC_PUBLISHER
	ROS_TYPE_TOPIC_SUBSCRIBER,//!< TOPIC_SUBSCRIBER
	ROS_TYPE_SERVICE_CLIENT,  //!< SERVICE_CLIENT
	ROS_TYPE_SERVICE_SERVER,  //!< SERVICE_SERVER
	ROS_TYPE_ROSRPC_SERVER,   //!< ROSRPC_SERVER
	ROS_TYPE_ROSRPC_CLIENT,   //!< ROSRPC_CLIENT
}ros_type_t;

typedef struct
{

	void (*submode_function)(char **buf_ptr, uint32_t *len_ptr, void *submode_data_storage);
}ros_parse_act_t;

void ros_parse_act_init(ros_parse_act_t *pact, ros_type_t type, void * handler_data_storage);

void ros_parse(char *buf, uint32_t len, ros_parse_act_t* pact);

#endif /* TCPROS_PARSER_H_ */