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



//Testdata for message testbuiltin
//no duration and no time array!
char peer0_0[] = {
0x2c, 0x04, 0x00, 0x00, 0x8f, 0x03, 0x00, 0x00,
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
0x6f, 0x6e, 0x0a, 0x23, 0x64, 0x75, 0x72, 0x61,
0x74, 0x69, 0x6f, 0x6e, 0x20, 0x74, 0x62, 0x69,
0x5f, 0x64, 0x75, 0x72, 0x61, 0x74, 0x69, 0x6f,
0x6e, 0x0a, 0x0a, 0x23, 0x49, 0x6e, 0x74, 0x65,
0x67, 0x65, 0x72, 0x0a, 0x69, 0x6e, 0x74, 0x38,
0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x69,
0x6e, 0x74, 0x38, 0x5f, 0x41, 0x0a, 0x69, 0x6e,
0x74, 0x31, 0x36, 0x5b, 0x32, 0x5d, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x69, 0x6e, 0x74, 0x31, 0x36,
0x5f, 0x41, 0x0a, 0x69, 0x6e, 0x74, 0x33, 0x32,
0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x69,
0x6e, 0x74, 0x33, 0x32, 0x5f, 0x41, 0x0a, 0x69,
0x6e, 0x74, 0x36, 0x34, 0x5b, 0x5d, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x69, 0x6e, 0x74, 0x36, 0x34,
0x5f, 0x41, 0x0a, 0x0a, 0x23, 0x55, 0x6e, 0x73,
0x69, 0x67, 0x6e, 0x65, 0x64, 0x20, 0x49, 0x6e,
0x74, 0x65, 0x67, 0x65, 0x72, 0x0a, 0x75, 0x69,
0x6e, 0x74, 0x38, 0x5b, 0x5d, 0x20, 0x74, 0x62,
0x69, 0x5f, 0x75, 0x69, 0x6e, 0x74, 0x38, 0x5f,
0x41, 0x0a, 0x75, 0x69, 0x6e, 0x74, 0x31, 0x36,
0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x75,
0x69, 0x6e, 0x74, 0x31, 0x36, 0x5f, 0x41, 0x0a,
0x75, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x5b, 0x32,
0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x75, 0x69,
0x6e, 0x74, 0x33, 0x32, 0x5f, 0x41, 0x0a, 0x75,
0x69, 0x6e, 0x74, 0x36, 0x34, 0x5b, 0x5d, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x75, 0x69, 0x6e, 0x74,
0x36, 0x34, 0x5f, 0x41, 0x0a, 0x0a, 0x23, 0x46,
0x6c, 0x6f, 0x61, 0x74, 0x0a, 0x66, 0x6c, 0x6f,
0x61, 0x74, 0x33, 0x32, 0x5b, 0x32, 0x5d, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x66, 0x6c, 0x6f, 0x61,
0x74, 0x33, 0x32, 0x5f, 0x41, 0x0a, 0x66, 0x6c,
0x6f, 0x61, 0x74, 0x36, 0x34, 0x5b, 0x5d, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x66, 0x6c, 0x6f, 0x61,
0x74, 0x36, 0x34, 0x5f, 0x41, 0x0a, 0x0a, 0x23,
0x42, 0x6f, 0x6f, 0x6c, 0x0a, 0x62, 0x6f, 0x6f,
0x6c, 0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f,
0x62, 0x6f, 0x6f, 0x6c, 0x5f, 0x41, 0x0a, 0x0a,
0x23, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x0a,
0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x5b, 0x5d,
0x20, 0x74, 0x62, 0x69, 0x5f, 0x73, 0x74, 0x72,
0x69, 0x6e, 0x67, 0x5f, 0x41, 0x0a, 0x0a, 0x23,
0x54, 0x69, 0x6d, 0x65, 0x0a, 0x23, 0x74, 0x69,
0x6d, 0x65, 0x5b, 0x32, 0x5d, 0x20, 0x74, 0x62,
0x69, 0x5f, 0x74, 0x69, 0x6d, 0x65, 0x5f, 0x41,
0x0a, 0x0a, 0x23, 0x44, 0x75, 0x72, 0x61, 0x74,
0x69, 0x6f, 0x6e, 0x0a, 0x23, 0x64, 0x75, 0x72,
0x61, 0x74, 0x69, 0x6f, 0x6e, 0x5b, 0x5d, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x64, 0x75, 0x72, 0x61,
0x74, 0x69, 0x6f, 0x6e, 0x5f, 0x41, 0x0a, 0x0a,
0x74, 0x65, 0x73, 0x74, 0x73, 0x75, 0x62, 0x6d,
0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x20, 0x74,
0x5f, 0x6e, 0x62, 0x69, 0x5f, 0x73, 0x75, 0x62,
0x0a, 0x74, 0x65, 0x73, 0x74, 0x73, 0x75, 0x62,
0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x5b,
0x32, 0x5d, 0x20, 0x74, 0x5f, 0x6e, 0x62, 0x69,
0x5f, 0x73, 0x75, 0x62, 0x5f, 0x41, 0x0a, 0x0a,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x0a, 0x4d, 0x53, 0x47, 0x3a, 0x20, 0x72, 0x6f,
0x73, 0x63, 0x5f, 0x6c, 0x69, 0x6e, 0x75, 0x78,
0x5f, 0x74, 0x65, 0x73, 0x74, 0x2f, 0x74, 0x65,
0x73, 0x74, 0x73, 0x75, 0x62, 0x6d, 0x65, 0x73,
0x73, 0x61, 0x67, 0x65, 0x0a, 0x62, 0x6f, 0x6f,
0x6c, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x74, 0x6d,
0x5f, 0x62, 0x6f, 0x6f, 0x6c, 0x0a, 0x69, 0x6e,
0x74, 0x38, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x74,
0x6d, 0x5f, 0x69, 0x6e, 0x74, 0x38, 0x0a, 0x26,
0x00, 0x00, 0x00, 0x63, 0x61, 0x6c, 0x6c, 0x65,
0x72, 0x69, 0x64, 0x3d, 0x2f, 0x72, 0x6f, 0x73,
0x74, 0x6f, 0x70, 0x69, 0x63, 0x5f, 0x33, 0x32,
0x30, 0x34, 0x30, 0x5f, 0x31, 0x33, 0x37, 0x33,
0x36, 0x33, 0x35, 0x33, 0x33, 0x31, 0x36, 0x31,
0x32, 0x0d, 0x00, 0x00, 0x00, 0x74, 0x63, 0x70,
0x5f, 0x6e, 0x6f, 0x64, 0x65, 0x6c, 0x61, 0x79,
0x3d, 0x30, 0x27, 0x00, 0x00, 0x00, 0x6d, 0x64,
0x35, 0x73, 0x75, 0x6d, 0x3d, 0x36, 0x38, 0x34,
0x38, 0x61, 0x62, 0x65, 0x31, 0x37, 0x39, 0x37,
0x35, 0x64, 0x33, 0x34, 0x35, 0x63, 0x65, 0x33,
0x37, 0x32, 0x37, 0x36, 0x31, 0x63, 0x36, 0x30,
0x32, 0x35, 0x62, 0x38, 0x64, 0x0b, 0x00, 0x00 };
char peer0_1[] = {
0x00, 0x74, 0x6f, 0x70, 0x69, 0x63, 0x3d, 0x2f,
0x74, 0x65, 0x73, 0x74, 0x20, 0x00, 0x00, 0x00,
0x74, 0x79, 0x70, 0x65, 0x3d, 0x72, 0x6f, 0x73,
0x63, 0x5f, 0x6c, 0x69, 0x6e, 0x75, 0x78, 0x5f,
0x74, 0x65, 0x73, 0x74, 0x2f, 0x74, 0x65, 0x73,
0x74, 0x62, 0x75, 0x69, 0x6c, 0x74, 0x69, 0x6e };
char peer1_0[] = {
0x29, 0x04, 0x00, 0x00, 0x8f, 0x03, 0x00, 0x00,
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
0x6f, 0x6e, 0x0a, 0x23, 0x64, 0x75, 0x72, 0x61,
0x74, 0x69, 0x6f, 0x6e, 0x20, 0x74, 0x62, 0x69,
0x5f, 0x64, 0x75, 0x72, 0x61, 0x74, 0x69, 0x6f,
0x6e, 0x0a, 0x0a, 0x23, 0x49, 0x6e, 0x74, 0x65,
0x67, 0x65, 0x72, 0x0a, 0x69, 0x6e, 0x74, 0x38,
0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x69,
0x6e, 0x74, 0x38, 0x5f, 0x41, 0x0a, 0x69, 0x6e,
0x74, 0x31, 0x36, 0x5b, 0x32, 0x5d, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x69, 0x6e, 0x74, 0x31, 0x36,
0x5f, 0x41, 0x0a, 0x69, 0x6e, 0x74, 0x33, 0x32,
0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x69,
0x6e, 0x74, 0x33, 0x32, 0x5f, 0x41, 0x0a, 0x69,
0x6e, 0x74, 0x36, 0x34, 0x5b, 0x5d, 0x20, 0x74,
0x62, 0x69, 0x5f, 0x69, 0x6e, 0x74, 0x36, 0x34,
0x5f, 0x41, 0x0a, 0x0a, 0x23, 0x55, 0x6e, 0x73,
0x69, 0x67, 0x6e, 0x65, 0x64, 0x20, 0x49, 0x6e,
0x74, 0x65, 0x67, 0x65, 0x72, 0x0a, 0x75, 0x69,
0x6e, 0x74, 0x38, 0x5b, 0x5d, 0x20, 0x74, 0x62,
0x69, 0x5f, 0x75, 0x69, 0x6e, 0x74, 0x38, 0x5f,
0x41, 0x0a, 0x75, 0x69, 0x6e, 0x74, 0x31, 0x36,
0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x75,
0x69, 0x6e, 0x74, 0x31, 0x36, 0x5f, 0x41, 0x0a,
0x75, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x5b, 0x32,
0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x75, 0x69,
0x6e, 0x74, 0x33, 0x32, 0x5f, 0x41, 0x0a, 0x75,
0x69, 0x6e, 0x74, 0x36, 0x34, 0x5b, 0x5d, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x75, 0x69, 0x6e, 0x74,
0x36, 0x34, 0x5f, 0x41, 0x0a, 0x0a, 0x23, 0x46,
0x6c, 0x6f, 0x61, 0x74, 0x0a, 0x66, 0x6c, 0x6f,
0x61, 0x74, 0x33, 0x32, 0x5b, 0x32, 0x5d, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x66, 0x6c, 0x6f, 0x61,
0x74, 0x33, 0x32, 0x5f, 0x41, 0x0a, 0x66, 0x6c,
0x6f, 0x61, 0x74, 0x36, 0x34, 0x5b, 0x5d, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x66, 0x6c, 0x6f, 0x61,
0x74, 0x36, 0x34, 0x5f, 0x41, 0x0a, 0x0a, 0x23,
0x42, 0x6f, 0x6f, 0x6c, 0x0a, 0x62, 0x6f, 0x6f,
0x6c, 0x5b, 0x5d, 0x20, 0x74, 0x62, 0x69, 0x5f,
0x62, 0x6f, 0x6f, 0x6c, 0x5f, 0x41, 0x0a, 0x0a,
0x23, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x0a,
0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x5b, 0x5d,
0x20, 0x74, 0x62, 0x69, 0x5f, 0x73, 0x74, 0x72,
0x69, 0x6e, 0x67, 0x5f, 0x41, 0x0a, 0x0a, 0x23,
0x54, 0x69, 0x6d, 0x65, 0x0a, 0x23, 0x74, 0x69,
0x6d, 0x65, 0x5b, 0x32, 0x5d, 0x20, 0x74, 0x62,
0x69, 0x5f, 0x74, 0x69, 0x6d, 0x65, 0x5f, 0x41,
0x0a, 0x0a, 0x23, 0x44, 0x75, 0x72, 0x61, 0x74,
0x69, 0x6f, 0x6e, 0x0a, 0x23, 0x64, 0x75, 0x72,
0x61, 0x74, 0x69, 0x6f, 0x6e, 0x5b, 0x5d, 0x20,
0x74, 0x62, 0x69, 0x5f, 0x64, 0x75, 0x72, 0x61,
0x74, 0x69, 0x6f, 0x6e, 0x5f, 0x41, 0x0a, 0x0a,
0x74, 0x65, 0x73, 0x74, 0x73, 0x75, 0x62, 0x6d,
0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x20, 0x74,
0x5f, 0x6e, 0x62, 0x69, 0x5f, 0x73, 0x75, 0x62,
0x0a, 0x74, 0x65, 0x73, 0x74, 0x73, 0x75, 0x62,
0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x5b,
0x32, 0x5d, 0x20, 0x74, 0x5f, 0x6e, 0x62, 0x69,
0x5f, 0x73, 0x75, 0x62, 0x5f, 0x41, 0x0a, 0x0a,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
0x0a, 0x4d, 0x53, 0x47, 0x3a, 0x20, 0x72, 0x6f,
0x73, 0x63, 0x5f, 0x6c, 0x69, 0x6e, 0x75, 0x78,
0x5f, 0x74, 0x65, 0x73, 0x74, 0x2f, 0x74, 0x65,
0x73, 0x74, 0x73, 0x75, 0x62, 0x6d, 0x65, 0x73,
0x73, 0x61, 0x67, 0x65, 0x0a, 0x62, 0x6f, 0x6f,
0x6c, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x74, 0x6d,
0x5f, 0x62, 0x6f, 0x6f, 0x6c, 0x0a, 0x69, 0x6e,
0x74, 0x38, 0x20, 0x74, 0x62, 0x69, 0x5f, 0x74,
0x6d, 0x5f, 0x69, 0x6e, 0x74, 0x38, 0x0a, 0x26,
0x00, 0x00, 0x00, 0x63, 0x61, 0x6c, 0x6c, 0x65,
0x72, 0x69, 0x64, 0x3d, 0x2f, 0x72, 0x6f, 0x73,
0x74, 0x6f, 0x70, 0x69, 0x63, 0x5f, 0x33, 0x31,
0x38, 0x36, 0x39, 0x5f, 0x31, 0x33, 0x37, 0x33,
0x36, 0x33, 0x35, 0x33, 0x31, 0x38, 0x33, 0x36,
0x30, 0x0a, 0x00, 0x00, 0x00, 0x6c, 0x61, 0x74,
0x63, 0x68, 0x69, 0x6e, 0x67, 0x3d, 0x31, 0x27,
0x00, 0x00, 0x00, 0x6d, 0x64, 0x35, 0x73, 0x75,
0x6d, 0x3d, 0x36, 0x38, 0x34, 0x38, 0x61, 0x62,
0x65, 0x31, 0x37, 0x39, 0x37, 0x35, 0x64, 0x33,
0x34, 0x35, 0x63, 0x65, 0x33, 0x37, 0x32, 0x37,
0x36, 0x31, 0x63, 0x36, 0x30, 0x32, 0x35, 0x62,
0x38, 0x64, 0x0b, 0x00, 0x00, 0x00, 0x74, 0x6f };
char peer1_1[] = {
0x70, 0x69, 0x63, 0x3d, 0x2f, 0x74, 0x65, 0x73,
0x74, 0x20, 0x00, 0x00, 0x00, 0x74, 0x79, 0x70,
0x65, 0x3d, 0x72, 0x6f, 0x73, 0x63, 0x5f, 0x6c,
0x69, 0x6e, 0x75, 0x78, 0x5f, 0x74, 0x65, 0x73,
0x74, 0x2f, 0x74, 0x65, 0x73, 0x74, 0x62, 0x75,
0x69, 0x6c, 0x74, 0x69, 0x6e };
char peer1_2[] = {
0xf8, 0x00, 0x00, 0x00, 0x2d, 0xc8, 0xff, 0xea,
0xff, 0xff, 0xff, 0xde, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0x05, 0x03, 0x00, 0x04, 0x00,
0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x66, 0x66, 0x36, 0x42, 0x33, 0x33,
0x33, 0x33, 0x33, 0x33, 0x41, 0x40, 0x01, 0x1a,
0x00, 0x00, 0x00, 0x54, 0x68, 0x69, 0x73, 0x20,
0x69, 0x73, 0x20, 0x61, 0x20, 0x64, 0x61, 0x6d,
0x6e, 0x20, 0x74, 0x65, 0x73, 0x74, 0x20, 0x73,
0x74, 0x72, 0x69, 0x6e, 0x67, 0x2d, 0x00, 0x00,
0x00, 0x2d, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
0x00, 0x2d, 0x22, 0x00, 0x2d, 0x00, 0x02, 0x00,
0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x43, 0x00,
0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xea, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x86,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00,
0x00, 0x00, 0x63, 0x68, 0x61, 0x72, 0x61, 0x72,
0x72, 0x61, 0x79, 0x01, 0x00, 0x00, 0x00, 0x9a,
0x02, 0xbc, 0x01, 0x00, 0x00, 0x2b, 0x02, 0x00,
0x00, 0x03, 0x00, 0x00, 0x00, 0x7a, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xfa, 0x92, 0x03,
0x00, 0x00, 0x00, 0x00, 0x00, 0xea, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x9a, 0x99, 0x99,
0x3e, 0x00, 0x00, 0x00, 0x40, 0x03, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xf0, 0x9b, 0x56, 0x76,
0x41, 0x00, 0x00, 0x00, 0xf0, 0x9b, 0x56, 0x76,
0x41, 0x00, 0x00, 0x00, 0xf4, 0x42, 0xec, 0xab,
0x41, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01,
0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
0x73, 0x64, 0x73, 0x64, 0x06, 0x00, 0x00, 0x00,
0x73, 0x64, 0x66, 0x73, 0x64, 0x66, 0x01, 0x06,
0x00, 0x05, 0x00, 0x02 };


ROSC_STATIC_MSG_BUILDUP__rosc_linux_test__testbuiltin();

ROSC_STATIC_MSG_USER_DEF__rosc_linux_test__testbuiltin(test,3,3,3,3,3,3,3,3,3,3,3,3);


ROSC_STATIC_SYSTEM_MESSAGE_TYPE_LIST_BEGIN
	ROSC_SIZE_LIST_ENTRY__rosc_linux_test__testbuiltin(test)
ROSC_STATIC_SYSTEM_MESSAGE_TYPE_LIST_END


ROSC_STATIC_CALLBACK_HEAD__rosc_linux_test__testbuiltin__(test,cb)
	/*Callback Function stuff here*/
}


ros_handler_init_t init_test={ROS_HANDLER_TYPE_TOPIC_SUBSCRIBER,
							rosc_static_msg_buildup__rosc_linux_test__testbuiltin,
							rosc_static_msg_submessage_size_list__rosc_linux_test__testbuiltin__test,
							rosc_static_msg_array_size_list__rosc_linux_test__testbuiltin__test,
							rosc_static_msg_memory_offsets__rosc_linux_test__testbuiltin__test};

iface_t sub={
		     false,
		     "/topicName",
		     &ros_handler,
		     &init_test,
};
//				"/test",
//				IFACE_STATE_UNREGISTERED,
//				(ros_msg_buildup_t *)rosc_static_msg_buildup__rosc_linux_test__testbuiltin,
//				(size_t *)rosc_static_msg_submessage_size_list__rosc_linux_test__testbuiltin__test,
//				(size_t *)rosc_static_msg_array_size_list__rosc_linux_test__testbuiltin__test,
//				(size_t *)rosc_static_msg_memory_offsets__rosc_linux_test__testbuiltin__test,
//				IFACE_TYPE_TOPIC_SUBSCRIBER,
//				&ros_handler};

int main()
{
	rosc_init();
	register_interface(&sub);
	rosc_open_port(&sub,0);
	rosc_receive_by_socketid(1,peer0_0,sizeof(peer0_0));

//	int i=ROS_MSG_BUILDUP_TYPE_STRING;
//	for (i = 1; i <= rosc_static_msg_memory_offsets__rosc_linux_test__testbuiltin__test[0]; ++i) {
//
//		printf("%i, ",(int) rosc_static_msg_memory_offsets__rosc_linux_test__testbuiltin__test[i]);
//	}
	printf("\n---END---\n");
}
