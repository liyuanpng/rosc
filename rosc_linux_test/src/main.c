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
 *  main.c created by Christian Holl
 */
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <rosc/msg/rosc_linux_test/testbuiltin.h>
#include <rosc/rosc.h>
#include <rosc/com/ros_handler.h>
#include <rosc/sebs_parse_fw/gen_modules/msg_gen_handler.h>


#include <rosc/string_res/msg_strings.h>
#include <rosc/com/msg_gen.h>

uint8_t peer0_0[] = {
0x27, 0x04, 0x00, 0x00, 0x8d, 0x03, 0x00, 0x00,
0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x5f,
0x64, 0x65, 0x66, 0x69, 0x6e, 0x69, 0x74, 0x69,
0x6f, 0x6e, 0x3d, 0x23, 0x49, 0x6e, 0x74, 0x65,
0x67, 0x65, 0x72, 0x0a, 0x69, 0x6e, 0x74, 0x38,
0x20, 0x74, 0x62, 0x69, 0x5f, 0x69, 0x6e, 0x74,
0x38, 0x0a, 0x69, 0x6e, 0x74, 0x31, 0x36, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x69, 0x6e, 0x74, 0x31,
0x36, 0x0a, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x69, 0x6e, 0x74, 0x33,
0x32, 0x0a, 0x69, 0x6e, 0x74, 0x36, 0x34, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x69, 0x6e, 0x74, 0x36,
0x34, 0x0a, 0x0a, 0x23, 0x55, 0x6e, 0x73, 0x69,
0x67, 0x6e, 0x65, 0x64, 0x20, 0x49, 0x6e, 0x74,
0x65, 0x67, 0x65, 0x72, 0x0a, 0x75, 0x69, 0x6e,
0x74, 0x38, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x75,
0x69, 0x6e, 0x74, 0x38, 0x0a, 0x75, 0x69, 0x6e,
0x74, 0x31, 0x36, 0x20, 0x74, 0x62, 0x69, 0x5f,
0x75, 0x69, 0x6e, 0x74, 0x31, 0x36, 0x0a, 0x75,
0x69, 0x6e, 0x74, 0x33, 0x32, 0x20, 0x74, 0x62,
0x69, 0x5f, 0x75, 0x69, 0x6e, 0x74, 0x33, 0x32,
0x0a, 0x75, 0x69, 0x6e, 0x74, 0x36, 0x34, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x75, 0x69, 0x6e, 0x74,
0x36, 0x34, 0x0a, 0x0a, 0x23, 0x46, 0x6c, 0x6f,
0x61, 0x74, 0x0a, 0x66, 0x6c, 0x6f, 0x61, 0x74,
0x33, 0x32, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x66,
0x6c, 0x6f, 0x61, 0x74, 0x33, 0x32, 0x0a, 0x66,
0x6c, 0x6f, 0x61, 0x74, 0x36, 0x34, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x66, 0x6c, 0x6f, 0x61, 0x74,
0x36, 0x34, 0x0a, 0x0a, 0x23, 0x42, 0x6f, 0x6f,
0x6c, 0x0a, 0x62, 0x6f, 0x6f, 0x6c, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x62, 0x6f, 0x6f, 0x6c, 0x0a,
0x0a, 0x23, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67,
0x0a, 0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x73, 0x74, 0x72, 0x69,
0x6e, 0x67, 0x0a, 0x0a, 0x23, 0x54, 0x69, 0x6d,
0x65, 0x0a, 0x74, 0x69, 0x6d, 0x65, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x74, 0x69, 0x6d, 0x65, 0x0a,
0x0a, 0x23, 0x44, 0x75, 0x72, 0x61, 0x74, 0x69,
0x6f, 0x6e, 0x0a, 0x64, 0x75, 0x72, 0x61, 0x74,
0x69, 0x6f, 0x6e, 0x20, 0x74, 0x62, 0x69, 0x5f,
0x64, 0x75, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e,
0x0a, 0x0a, 0x23, 0x49, 0x6e, 0x74, 0x65, 0x67,
0x65, 0x72, 0x0a, 0x69, 0x6e, 0x74, 0x38, 0x5b,
0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x69, 0x6e,
0x74, 0x38, 0x5f, 0x41, 0x0a, 0x69, 0x6e, 0x74,
0x31, 0x36, 0x5b, 0x32, 0x5d, 0x20, 0x74, 0x62,
0x69, 0x5f, 0x69, 0x6e, 0x74, 0x31, 0x36, 0x5f,
0x41, 0x0a, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x5b,
0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x69, 0x6e,
0x74, 0x33, 0x32, 0x5f, 0x41, 0x0a, 0x69, 0x6e,
0x74, 0x36, 0x34, 0x5b, 0x5d, 0x20, 0x74, 0x62,
0x69, 0x5f, 0x69, 0x6e, 0x74, 0x36, 0x34, 0x5f,
0x41, 0x0a, 0x0a, 0x23, 0x55, 0x6e, 0x73, 0x69,
0x67, 0x6e, 0x65, 0x64, 0x20, 0x49, 0x6e, 0x74,
0x65, 0x67, 0x65, 0x72, 0x0a, 0x75, 0x69, 0x6e,
0x74, 0x38, 0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69,
0x5f, 0x75, 0x69, 0x6e, 0x74, 0x38, 0x5f, 0x41,
0x0a, 0x75, 0x69, 0x6e, 0x74, 0x31, 0x36, 0x5b,
0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x75, 0x69,
0x6e, 0x74, 0x31, 0x36, 0x5f, 0x41, 0x0a, 0x75,
0x69, 0x6e, 0x74, 0x33, 0x32, 0x5b, 0x32, 0x5d,
0x20, 0x74, 0x62, 0x69, 0x5f, 0x75, 0x69, 0x6e,
0x74, 0x33, 0x32, 0x5f, 0x41, 0x0a, 0x75, 0x69,
0x6e, 0x74, 0x36, 0x34, 0x5b, 0x5d, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x75, 0x69, 0x6e, 0x74, 0x36,
0x34, 0x5f, 0x41, 0x0a, 0x0a, 0x23, 0x46, 0x6c,
0x6f, 0x61, 0x74, 0x0a, 0x66, 0x6c, 0x6f, 0x61,
0x74, 0x33, 0x32, 0x5b, 0x32, 0x5d, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x66, 0x6c, 0x6f, 0x61, 0x74,
0x33, 0x32, 0x5f, 0x41, 0x0a, 0x66, 0x6c, 0x6f,
0x61, 0x74, 0x36, 0x34, 0x5b, 0x5d, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x66, 0x6c, 0x6f, 0x61, 0x74,
0x36, 0x34, 0x5f, 0x41, 0x0a, 0x0a, 0x23, 0x42,
0x6f, 0x6f, 0x6c, 0x0a, 0x62, 0x6f, 0x6f, 0x6c,
0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x62,
0x6f, 0x6f, 0x6c, 0x5f, 0x41, 0x0a, 0x0a, 0x23,
0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x0a, 0x73,
0x74, 0x72, 0x69, 0x6e, 0x67, 0x5b, 0x5d, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x73, 0x74, 0x72, 0x69,
0x6e, 0x67, 0x5f, 0x41, 0x0a, 0x0a, 0x23, 0x54,
0x69, 0x6d, 0x65, 0x0a, 0x74, 0x69, 0x6d, 0x65,
0x5b, 0x32, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f,
0x74, 0x69, 0x6d, 0x65, 0x5f, 0x41, 0x0a, 0x20,
0x0a, 0x23, 0x44, 0x75, 0x72, 0x61, 0x74, 0x69,
0x6f, 0x6e, 0x0a, 0x64, 0x75, 0x72, 0x61, 0x74,
0x69, 0x6f, 0x6e, 0x5b, 0x5d, 0x20, 0x74, 0x62,
0x69, 0x5f, 0x64, 0x75, 0x72, 0x61, 0x74, 0x69,
0x6f, 0x6e, 0x5f, 0x41, 0x0a, 0x0a, 0x74, 0x65,
0x73, 0x74, 0x73, 0x75, 0x62, 0x6d, 0x65, 0x73,
0x73, 0x61, 0x67, 0x65, 0x20, 0x74, 0x5f, 0x6e,
0x62, 0x69, 0x5f, 0x73, 0x75, 0x62, 0x0a, 0x74,
0x65, 0x73, 0x74, 0x73, 0x75, 0x62, 0x6d, 0x65,
0x73, 0x73, 0x61, 0x67, 0x65, 0x5b, 0x32, 0x5d,
0x20, 0x74, 0x5f, 0x6e, 0x62, 0x69, 0x5f, 0x73,
0x75, 0x62, 0x5f, 0x41, 0x0a, 0x0a, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x0a, 0x4d,
0x53, 0x47, 0x3a, 0x20, 0x72, 0x6f, 0x73, 0x63,
0x5f, 0x6c, 0x69, 0x6e, 0x75, 0x78, 0x5f, 0x74,
0x65, 0x73, 0x74, 0x2f, 0x74, 0x65, 0x73, 0x74,
0x73, 0x75, 0x62, 0x6d, 0x65, 0x73, 0x73, 0x61,
0x67, 0x65, 0x0a, 0x62, 0x6f, 0x6f, 0x6c, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x74, 0x6d, 0x5f, 0x62,
0x6f, 0x6f, 0x6c, 0x0a, 0x69, 0x6e, 0x74, 0x38,
0x20, 0x74, 0x62, 0x69, 0x5f, 0x74, 0x6d, 0x5f,
0x69, 0x6e, 0x74, 0x38, 0x0a, 0x26, 0x00, 0x00,
0x00, 0x63, 0x61, 0x6c, 0x6c, 0x65, 0x72, 0x69,
0x64, 0x3d, 0x2f, 0x72, 0x6f, 0x73, 0x74, 0x6f,
0x70, 0x69, 0x63, 0x5f, 0x32, 0x35, 0x36, 0x31,
0x34, 0x5f, 0x31, 0x33, 0x37, 0x34, 0x31, 0x35,
0x30, 0x30, 0x36, 0x39, 0x37, 0x37, 0x36, 0x0a,
0x00, 0x00, 0x00, 0x6c, 0x61, 0x74, 0x63, 0x68,
0x69, 0x6e, 0x67, 0x3d, 0x31, 0x27, 0x00, 0x00,
0x00, 0x6d, 0x64, 0x35, 0x73, 0x75, 0x6d, 0x3d,
0x66, 0x30, 0x37, 0x61, 0x61, 0x63, 0x33, 0x65,
0x64, 0x61, 0x61, 0x61, 0x63, 0x66, 0x31, 0x31,
0x38, 0x64, 0x31, 0x30, 0x63, 0x63, 0x34, 0x61,
0x65, 0x66, 0x39, 0x61, 0x30, 0x32, 0x62, 0x37,
0x0b, 0x00, 0x00, 0x00, 0x74, 0x6f, 0x70, 0x69,
0x63, 0x3d, 0x2f, 0x74, 0x65, 0x73, 0x74, 0x20,
0x00, 0x00, 0x00, 0x74, 0x79, 0x70, 0x65, 0x3d,
0x72, 0x6f, 0x73, 0x63, 0x5f, 0x6c, 0x69, 0x6e,
0x75, 0x78, 0x5f, 0x74, 0x65, 0x73, 0x74, 0x2f,
0x74, 0x65, 0x73, 0x74, 0x62, 0x75, 0x69, 0x6c,
0x74, 0x69, 0x6e, 0x02, 0x01, 0x00, 0x00, 0x22,
0x7b, 0x00, 0xc8, 0x01, 0x00, 0x00, 0xd2, 0x1e,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x32,
0x00, 0x3c, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0,
0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x54,
0x40, 0x01, 0x10,
0x00, 0x00, 0x00, 0x41, 0x42, 0x43, 0x44, 0x45,
0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D,
0x4E, 0x4F, 0x50, 0x6a, 0x0d, 0x00, 0x00, 0x22,
0x00, 0x00, 0x00, 0xec, 0xdc, 0x00, 0x00, 0x38,
0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x22,
0x22, 0x22, 0x04, 0x00, 0x04, 0x00, 0x03, 0x00,
0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00,
0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00,
0x00, 0x00, 0x2b, 0x02, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x2b, 0x02, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xb3, 0x15, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2d, 0x0c,
0x22, 0x03, 0x00, 0x00, 0x00, 0x2f, 0x03, 0x21,
0x00, 0x2c, 0x00, 0xea, 0x00, 0x00, 0x00, 0x27,
0x86, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xaf,
0xad, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa4,
0x70, 0x45, 0x41, 0xb8, 0x1e, 0x63, 0x42, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x29,
0x8c, 0x67, 0x41, 0x03, 0x00, 0x00, 0x00, 0x01,
0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x07, 0x00,
0x00, 0x00, 0x73, 0x74, 0x72, 0x69, 0x6e, 0x67,
0x31, 0x07, 0x00, 0x00, 0x00, 0x73, 0x74, 0x72,
0x69, 0x6e, 0x67, 0x32, 0xbd, 0x01, 0x00, 0x00,
0x36, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00,
0xea, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
0x2d, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00,
0x01, 0x22, 0x01, 0x06, 0x01, 0x05 };

ROSC_STATIC_MSG_BUILDUP__rosc_linux_test__testbuiltin();


ROSC_STATIC_MSG_USER_DEF__rosc_linux_test__testbuiltin(test,15,2,2,2,2,2,2,2,2,2,30,3);


ROSC_STATIC_SYSTEM_MESSAGE_TYPE_LIST_BEGIN
	ROSC_SIZE_LIST_ENTRY__rosc_linux_test__testbuiltin(test)
ROSC_STATIC_SYSTEM_MESSAGE_TYPE_LIST_END


ROSC_STATIC_CALLBACK_HEAD__rosc_linux_test__testbuiltin__(test,mycallback)
	/*Callback Function stuff here*/

/*
rostopic pub /test rosc_linux_test/testbuiltin "tbi_int8: 34
tbi_int16: 123
tbi_int32: 456
tbi_int64: 7890
tbi_uint8: 30
tbi_uint16: 50
tbi_uint32: 60
tbi_uint64: 70
tbi_float32: 80.0
tbi_float64: 80.0
tbi_bool: true
tbi_string: 'ABCDEFGHIJKLMNOP'
tbi_time: {secs: 3434, nsecs: 34}
tbi_duration: {secs: 56556, nsecs: 56}
tbi_int8_A: [34,34,34]
tbi_int16_A: [4, 4]
tbi_int32_A: [3,4,4]
tbi_int64_A: [555,555,5555]
tbi_uint8_A: [45,12,34]
tbi_uint16_A: [815,33,44]
tbi_uint32_A: [234, 34343]
tbi_uint64_A: [3452335]
tbi_float32_A: [12.34, 56.78]
tbi_float64_A: [12345678]
tbi_bool_A: [true,false,true]
tbi_string_A: ['string1','string2']
tbi_time_A:
- {secs: 445, nsecs: 54}
- {secs: 34, nsecs: 234}
tbi_duration_A:
- {secs: 45, nsecs: 53}
t_nbi_sub: {tbi_tm_bool: true, tbi_tm_int8: 34}
t_nbi_sub_A:
- {tbi_tm_bool: true, tbi_tm_int8: 6}
- {tbi_tm_bool: true, tbi_tm_int8: 5}"
*/
int i;

printf("\n\n______________________________________________\n");
printf("____________________CALLBACK!_________________\n");
printf("______________________________________________\n");
printf("tbi_int8: %i\n",msg->tbi_int8);
printf("tbi_int16: %i\n",msg->tbi_int16);
printf("tbi_int32: %i\n",msg->tbi_int32);
printf("tbi_int64: %lu\n",msg->tbi_int64);
printf("tbi_uint8: %i\n",msg->tbi_uint8);
printf("tbi_uint16: %i\n",msg->tbi_uint16);
printf("tbi_uint32: %i\n",msg->tbi_uint32);
printf("tbi_uint64: %lu\n",msg->tbi_uint64);
printf("tbi_float32: %f\n",msg->tbi_float32);
printf("tbi_float64: %f\n",msg->tbi_float64);
printf("tbi_bool: %i\n",msg->tbi_bool);
printf("tbi_string:\n");
printf("\t size: %i\n",msg->tbi_string.size);
printf("\t oversize: %i\n",msg->tbi_string.oversize);
printf("\t data: %s\n",msg->tbi_string.str_data);
printf("tbi_time:\n");
printf("secs: %i\n",msg->tbi_time.sec);
printf("nsecs: %i\n",msg->tbi_time.nsec);
printf("tbi_duration:\n");
printf("secs: %i\n",msg->tbi_duration.sec);
printf("nsecs: %i\n",msg->tbi_duration.nsec);


printf("tbi_int8_A:\n");
printf("\t size: %i\n",msg->tbi_int8_A.size);
printf("\t oversize: %i\n",msg->tbi_int8_A.oversize);
printf("\t data: ");
for(i=0;i<msg->tbi_int8_A.size;i++)
	printf("%i ",msg->tbi_int8_A.data[i]);
printf("\n");

printf("tbi_int16_A:\n");
printf("\t size: %i\n",msg->tbi_int16_A.size);
printf("\t data: ");
for(i=0;i<msg->tbi_int16_A.size;i++)
	printf("%i ",msg->tbi_int16_A.data[i]);
printf("\n");

printf("tbi_int32_A:\n");
printf("\t size: %i\n",msg->tbi_int32_A.size);
printf("\t oversize: %i\n",msg->tbi_int32_A.oversize);
printf("\t data: ");
for(i=0;i<msg->tbi_int32_A.size;i++)
	printf("%i ",msg->tbi_int32_A.data[i]);
printf("\n");


printf("tbi_int64_A:\n");
printf("\t size: %i\n",msg->tbi_int64_A.size);
printf("\t oversize: %i\n",msg->tbi_int64_A.oversize);
printf("\t data: ");
for(i=0;i<msg->tbi_int64_A.size;i++)
	printf("%lu ",msg->tbi_int64_A.data[i]);
printf("\n");

printf("tbi_uint8_A:\n");
printf("\t size: %i\n",msg->tbi_uint8_A.size);
printf("\t oversize: %i\n",msg->tbi_uint8_A.oversize);
printf("\t data: ");
for(i=0;i<msg->tbi_uint8_A.size;i++)
	printf("%i ",msg->tbi_uint8_A.data[i]);
printf("\n");

printf("tbi_uint16_A:\n");
printf("\t size: %i\n",msg->tbi_uint16_A.size);
printf("\t oversize: %i\n",msg->tbi_uint16_A.oversize);
printf("\t data: ");
for(i=0;i<msg->tbi_uint16_A.size;i++)
	printf("%i ",msg->tbi_uint16_A.data[i]);
printf("\n");

printf("tbi_uint32_A:\n");
printf("\t size: %i\n",msg->tbi_uint32_A.size);
printf("\t data: ");
for(i=0;i<msg->tbi_uint32_A.size;i++)
	printf("%i ",msg->tbi_uint32_A.data[i]);
printf("\n");

printf("tbi_uint64_A:\n");
printf("\t size: %i\n",msg->tbi_uint64_A.size);
printf("\t data: ");
for(i=0;i<msg->tbi_uint64_A.size;i++)
	printf("%lu ",msg->tbi_uint64_A.data[i]);
printf("\n");

printf("tbi_float32_A:\n");
printf("\t size: %i\n",msg->tbi_float32_A.size);
printf("\t data: ");
for(i=0;i<msg->tbi_float32_A.size;i++)
	printf("%f ",msg->tbi_float32_A.data[i]);
printf("\n");


printf("tbi_float64_A:\n");
printf("\t size: %i\n",msg->tbi_float64_A.size);
printf("\t oversize: %i\n",msg->tbi_float64_A.oversize);
printf("\t data: ");
for(i=0;i<msg->tbi_float64_A.size;i++)
	printf("%f ",msg->tbi_float64_A.data[i]);
printf("\n");

printf("tbi_bool_A:\n");
printf("\t size: %i\n",msg->tbi_bool_A.size);
printf("\t oversize: %i\n",msg->tbi_bool_A.oversize);
printf("\t data: ");
for(i=0;i<msg->tbi_bool_A.size;i++)
	printf("%i ",msg->tbi_bool_A.data[i]);
printf("\n");


printf("tbi_string_A:\n");
printf("\t size: %i\n",msg->tbi_string_A.size);
printf("\t oversize: %i\n",msg->tbi_string_A.oversize);
for (i = 0; i < msg->tbi_string_A.size; ++i)
{
	printf("Item %i: \n",i);
	printf("\t size: %i\n",msg->tbi_string_A.data[i].size);
	printf("\t oversize: %i\n",msg->tbi_string_A.data[i].oversize);
	printf("\t str_data: %s\n",msg->tbi_string_A.data[i].str_data);
}

printf("tbi_time_A:\n");
printf("\t size: %i\n",msg->tbi_time_A.size);
for (i = 0; i < msg->tbi_time_A.size; ++i)
{
	printf("Item %i: \n",i);
	printf("\t nsec: %i\n",msg->tbi_time_A.data[i].sec);
	printf("\t nsec: %i\n",msg->tbi_time_A.data[i].nsec);
}


printf("tbi_duration_A:\n");
printf("\t size: %i\n",msg->tbi_duration_A.size);
printf("\t oversize: %i\n",msg->tbi_duration_A.oversize);
for (i = 0; i < msg->tbi_duration_A.size; ++i)
{
	printf("Item %i: \n",i);
	printf("\t nsec: %i\n",msg->tbi_duration_A.data[i].sec);
	printf("\t nsec: %i\n",msg->tbi_duration_A.data[i].nsec);
}

printf("t_nbi_sub: \n");
printf("tbi_tm_bool: %i\n",msg->t_nbi_sub.tbi_tm_bool);
printf("tbi_tm_int8: %i\n",msg->t_nbi_sub.tbi_tm_int8);


printf("t_nbi_sub_A: \n");
printf("size: %i\n",msg->t_nbi_sub_A.size);
for (i = 0; i < msg->t_nbi_sub_A.size; ++i) {
printf("tbi_tm_bool: %i\n",msg->t_nbi_sub_A.data[i].tbi_tm_bool);
//printf("tbi_tm_bool_addr: %lu\n",(unsigned long)&msg->t_nbi_sub_A.data[i].tbi_tm_bool);

printf("tbi_tm_int8: %i\n",msg->t_nbi_sub_A.data[i].tbi_tm_int8);
}

}

char topic[]="/test";

ros_msg_init_t init_test={	topic,
							ROS_HANDLER_TYPE_TOPIC_SUBSCRIBER,
							rosc_static_msg_buildup__rosc_linux_test__testbuiltin,
							rosc_static_msg_submessage_size_list__rosc_linux_test__testbuiltin__test,
							rosc_static_msg_array_size_list__rosc_linux_test__testbuiltin__test,
							rosc_static_msg_memory_offsets__rosc_linux_test__testbuiltin__test,
							rosc_static_msg_message_definition__rosc_linux_test__testbuiltin,
							rosc_static_msg_md5sum__rosc_linux_test__testbuiltin,
							ROSC_STATIC_SUBMESSAGE_STATES_MEMORY_OFFSET__rosc_linux_test__testbuiltin(test),
							&mycallback
							};

iface_t sub={false,
		     &ros_handler,
		     &init_test};



int main()
{

	enum
	{
		ROS_FIELD_STRINGS(GEN_RPC)
	};


	bool tcpNoDelay=0;
	msg_gen_command_t message[]=
	{
			{MSG_GEN_TYPE_WHOLE_LEN_BIN},

			{MSG_GEN_TYPE_ROSRPC_FIELD,(void *)ros_field_strings[GEN_RPC_ROS_FIELD_MESSAGE_DEFINITION],0},
			{MSG_GEN_TYPE_STRING,(void *)init_test.message_definition,1},

			{MSG_GEN_TYPE_ROSRPC_FIELD,(void *)ros_field_strings[GEN_RPC_ROS_FIELD_CALLERID],0},
			{MSG_GEN_TYPE_STRING,(void *)"narf",1},

			{MSG_GEN_TYPE_ROSRPC_FIELD,(void *)ros_field_strings[GEN_RPC_ROS_FIELD_TCP_NODELAY],0},
			{MSG_GEN_TYPE_BOOL,&tcpNoDelay,1},

			{MSG_GEN_TYPE_ROSRPC_FIELD,(void *)ros_field_strings[GEN_RPC_ROS_FIELD_MD5SUM],0},
			{MSG_GEN_TYPE_STRING,(void *)init_test.md5sum,1},

			{MSG_GEN_TYPE_ROSRPC_FIELD,(void *)ros_field_strings[GEN_RPC_ROS_FIELD_TOPIC],0},
			{MSG_GEN_TYPE_STRING,(void *)init_test.iface_name,1},

			{MSG_GEN_TYPE_END}
	};



	__rosc_static_port_mem[0];

	rosc_init();
	register_interface(&sub);
	rosc_open_port(&sub,0);
	rosc_receive_by_socketid(1,peer0_0,sizeof(peer0_0));



	char buffer[100];
	uint32_t size=100;
	sebs_parser_data_t pdata;
	msg_gen_handler_data_t h;
	msg_gen_handler_init_t i={message};
	h.message_definition=message;
	pdata.handler_data=(void *)&h;
	pdata.init_data=(void *)&i;
	pdata.handler_init=true;
	pdata.handler_function=&msg_gen_handler;
	sebs_parser_frame(buffer,size,&pdata);

	printf("\n---END---\n");
}
