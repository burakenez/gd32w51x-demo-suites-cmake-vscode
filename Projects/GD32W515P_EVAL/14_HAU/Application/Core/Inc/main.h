/*!
    \file    main.h
    \brief   the header of main

    \version 2025-02-19, V1.4.0, demo for GD32W51x
*/

/*
    Copyright (c) 2025, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#include "gd32w51x.h"
#include "stdio.h"

#ifndef MAIN_H
#define MAIN_H

#define HASH_MODE               "HASH"
#define HMAC_MODE               "HMAC"
#define SHA1                    "SHA1"
#define SHA224                  "SHA224"
#define SHA256                  "SHA256"
#define MD5                     "MD5"

#define ALGORITHM_USE_SHA1      0x01
#define ALGORITHM_USE_SHA224    0x02
#define ALGORITHM_USE_SHA256    0x04
#define ALGORITHM_USE_MD5       0x08
#define MODE_USE_HASH           0x10
#define MODE_USE_HMAC           0x20

/* message to be hashed */
const uint8_t message_input[] =  
              {0x54,0x68,0x65,0x20,0x68,0x61,0x73,0x68,
               0x20,0x70,0x72,0x6f,0x63,0x65,0x73,0x73,
               0x6f,0x72,0x20,0x69,0x73,0x20,0x61,0x20,
               0x66,0x75,0x6c,0x6c,0x79,0x20,0x63,0x6f,
               0x6d,0x70,0x6c,0x69,0x61,0x6e,0x74,0x20,
               0x69,0x6d,0x70,0x6c,0x65,0x6d,0x65,0x6e,
               0x74,0x61,0x74,0x69,0x6f,0x6e,0x20,0x6f,
               0x66,0x20,0x74,0x68,0x65,0x20,0x73,0x65,
               0x63,0x75,0x72,0x65,0x20,0x68,0x61,0x73,
               0x68,0x20,0x61,0x6c,0x67,0x6f,0x72,0x69,
               0x74,0x68,0x6d,0x20,0x28,0x53,0x48,0x41,
               0x2d,0x31,0x29,0x2c,0x20,0x74,0x68,0x65,
               0x20,0x4d,0x44,0x35,0x20,0x28,0x6d,0x65,
               0x73,0x73,0x61,0x67,0x65,0x2d,0x64,0x69,
               0x67,0x65,0x73,0x74,0x20,0x61,0x6c,0x67,
               0x6f,0x72,0x69,0x74,0x68,0x6d,0x20,0x35,
               0x29,0x20,0x68,0x61,0x73,0x68,0x20,0x61,
               0x6c,0x67,0x6f,0x72,0x69,0x74,0x68,0x6d,
               0x20,0x61,0x6e,0x64,0x20,0x74,0x68,0x65,
               0x20,0x48,0x4d,0x41,0x43,0x20,0x28,0x6b,
               0x65,0x79,0x65,0x64,0x2d,0x68,0x61,0x73,
               0x68,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,
               0x65,0x20,0x61,0x75,0x74,0x68,0x65,0x6e,
               0x74,0x69,0x63,0x61,0x74,0x69,0x6f,0x6e,
               0x20,0x63,0x6f,0x64,0x65,0x29,0x20,0x61,
               0x6c,0x67,0x6f,0x72,0x69,0x74,0x68,0x6d,
               0x20,0x73,0x75,0x69,0x74,0x61,0x62,0x6c,
               0x65,0x20,0x66,0x6f,0x72,0x20,0x61,0x20,
               0x76,0x61,0x72,0x69,0x65,0x74,0x79,0x20,
               0x6f,0x66,0x20,0x61,0x70,0x70,0x6c,0x69,
               0x63,0x61,0x74,0x69,0x6f,0x6e,0x73,0x2e,
               };

/* key for HMAC mode */
const uint8_t key[] =  
              {0x54,0x68,0x65,0x20,0x68,0x61,0x73,0x68,
               0x20,0x70,0x72,0x6f,0x63,0x65,0x73,0x73,
               0x6f,0x72,0x20,0x69,0x73,0x20,0x61,0x20,
               0x66,0x75,0x6c,0x6c,0x79,0x20,0x63,0x6f,
               0x6d,0x70,0x6c,0x69,0x61,0x6e,0x74,0x20,
               0x69,0x6d,0x70,0x6c,0x65,0x6d,0x65,0x6e,
               0x74,0x61,0x74,0x69,0x6f,0x6e,0x20,0x6f,
               0x66,0x20,0x74,0x68,0x65,0x20,0x73,0x65,
               0x63,0x75,0x72,0x65,0x20,0x68,0x61,0x73,
               0x68,0x20,0x61,0x6c,0x67,0x6f,0x72,0x69,
               0x74,0x68,0x6d,0x20,0x28,0x53,0x48,0x41,
               0x2d,0x31,0x29,0x2c,0x20,0x74,0x68,0x65,
               0x20,0x4d,0x44,0x35,0x20,0x28,0x6d,0x65,
               0x73,0x73,0x61,0x67,0x65,0x2d,0x64,0x69,
               0x67,0x65,0x73,0x74,0x20,0x61,0x6c,0x67,
               0x6f,0x72,0x69,0x74,0x68,0x6d,0x20,0x35,
               0x29,0x20,0x68,0x61,0x73,0x68,0x20,0x61,
               0x6c,0x67,0x6f,0x72,0x69,0x74,0x68,0x6d,
               0x20,0x61,0x6e,0x64,0x20,0x74,0x68,0x65,
               0x20,0x48,0x4d,0x41,0x43,0x20,0x28,0x6b,
               0x65,0x79,0x65,0x64,0x2d,0x68,0x61,0x73,
               0x68,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,
               0x65,0x20,0x61,0x75,0x74,0x68,0x65,0x6e,
               0x74,0x69,0x63,0x61,0x74,0x69,0x6f,0x6e,
               0x20,0x63,0x6f,0x64,0x65,0x29,0x20,0x61,
               0x6c,0x67,0x6f,0x72,0x69,0x74,0x68,0x6d,
               0x20,0x73,0x75,0x69,0x74,0x61,0x62,0x6c,
               0x65,0x20,0x66,0x6f,0x72,0x20,0x61,0x20,
               0x76,0x61,0x72,0x69,0x65,0x74,0x79,0x20,
               0x6f,0x66,0x20,0x61,0x70,0x70,0x6c,0x69,
               0x63,0x61,0x74,0x69,0x6f,0x6e,0x73,0x2e,
               };

#endif /* MAIN_H */
