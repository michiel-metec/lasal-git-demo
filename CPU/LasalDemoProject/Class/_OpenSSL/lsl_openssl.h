#ifndef _LSL_OPENSSL_H
	#pragma once
	#define _LSL_OPENSSL_H

	#include "DefineCompiler.h"

	// Interface
	#define INTERFACE_OPENSSL      "OPENSSL"

	#define NID_subject_alt_name			85
	#define NID_basic_constraints			87
	#define NID_netscape_comment			78
	#define NID_subject_key_identifier		82
	#define NID_authority_key_identifier	90
	#define NID_key_usage					83
	#define NID_ext_key_usage				126
	#define NID_commonName					13
	#define NID_sha1						64
	#define NID_undef						0
	#define NID_sha512						674

	// avoid ST compiler error because of name collision between define SSLeay_version and homonymous struct member and method
	// while retaining compatibility with OpenSSL C header files 
	#ifdef cCompile
		#define SSLEAY_VERSION		0
	#else 
		#define SSLEAY_VER      	0
	#endif
	#define SSLEAY_CFLAGS		2
	#define SSLEAY_BUILT_ON		3
	#define SSLEAY_PLATFORM		4
	#define SSLEAY_DIR		5

	#define RSA_PKCS1_PADDING	1
	#define RSA_SSLV23_PADDING	2
	#define RSA_NO_PADDING		3
	#define RSA_PKCS1_OAEP_PADDING	4
	#define RSA_X931_PADDING	5
	#define RSA_PKCS1_PSS_PADDING	6
	#define RSA_PKCS1_PADDING_SIZE	11

// reserved return value - this error value will be returned from every method of the _OpenSSL
// class, if no _OpenSSL interface is available.
// Starting the application without the _OpenSSL is possible
  #define OpenSSL_ERR_NO_INTERFACE      -1015  // error, no _OpenSSL Interface available

  #define OpenSSL_OK							      0


	//Types

TYPE
#pragma pack(push, 1)
	
  ASN1_TIME : STRUCT
    length  : DINT;
    xtype   : DINT;
    data    : ^CHAR;   
    flags   : DINT;
	END_STRUCT;

#pragma pack(pop)
END_TYPE

#ifndef cCompile
  #define OS_OPENSSL_VERSION                                      lsl_openssl->version
  #define OS_OPENSSL_SIZE                                         lsl_openssl->size
#endif

	#ifdef cCompile
		#include "lsl_c_openssl.h"
  #endif // cCompile
#endif // _LSL_OPENSSL_H
