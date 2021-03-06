/******************************************************************************
 * @file     platform.h
 * @author   Vadim Demchik <vadimdi@yahoo.com>
 * @author   Natalia Kolomoyets <rknv7@mail.ru>
 * @version  1.0
 *
 * @brief    [QCDGPU]
 *           External dependecies corresponding to user's operating system
 *
 * @section  LICENSE
 *
 * Copyright (c) 2013, Vadim Demchik, Natalia Kolomoyets
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *    Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 *****************************************************************************/


#ifndef platform_H
#define platform_H

#include <stdio.h>

#ifdef _WIN32
  #include <windows.h>
  #include <conio.h>
  #include <direct.h>
  #define GetCurrentDir(ptr,size)   (_getcwd(ptr,size))
  static const char slash[]="\\"; 
  #define snprintf(b,size,fmt,...) _snprintf_s((b),(size),_TRUNCATE,(fmt),##__VA_ARGS__)
#else
  #include <string.h>
  #include <cstdlib>
  #include <unistd.h>
  #define GetCurrentDir(ptr,size)   (getcwd(ptr,size))
  static const char slash[]="/";
  
  #define	sprintf_s(b,size,fmt,...) sprintf((b),(fmt),##__VA_ARGS__)
  #define	fopen_s(stream, buffer, mode) (*stream = fopen(buffer, mode))
  #define	sscanf_s(buffer, format, value) (sscanf(buffer, format, value))
  #define	_getch() (getchar())
  #define	ctime_s(timebuf,timez,ltime) (timebuf=ctime(ltime))
  #define	_strnset_s(Replace,replength,ch,replength2) (memset(Replace, ch, replength2))
  #define	strncpy_s(newtext, replength, resorc, lenz) (strlen(resorc)-snprintf(newtext, replength, "%s", resorc))
  #define	strncat_s(newtext, replength, resorc, lenz) (snprintf(newtext, lenz, "%s%s", newtext, resorc))
  #define   _snprintf_s(newtext, replength, flag, format, val1, val2 ) snprintf(newtext,replength, format, val1, val2)
  #define	strcpy_s(newtext, replength, resorc) (strcpy(newtext, resorc))
  #define	memcpy_s(destination, destination_length, source, len) (memcpy(destination, source, len))
  #define	strcat_s(newtext, replength, resorc, lenz) (strcat(newtext, resorc))
  #define	Sleep(tm) (sleep(1))
#endif

#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <time.h>
#include <malloc.h>

#define strlen_s(str)       ((str) ? strlen(str) : 0)
#define _MIN(x,y)           ( ((x)<(y)) ? (x) : (y) )
#define _MAX(x,y)           ( ((x)>(y)) ? (x) : (y) )
#define FREE(ptr)           {free((void*)ptr); ptr=NULL;}
#define FNAME_MAX_LENGTH    FILENAME_MAX  // FILENAME_MAX is definned by <stdio.h>

#define HGPU_MAX_STRINGLEN  384 ///< default length of constant char arrays
#define HGPU_MAX_LINELEN    8192

#define HGPU_CHAR_SPACE     ' ' ///< char: space

#define HGPU_ERROR_CODE(error_code,error_msg)    {case error_code: error_message = error_msg; break;}


#endif
