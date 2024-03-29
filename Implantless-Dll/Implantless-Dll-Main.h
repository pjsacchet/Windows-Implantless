#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files
#include <windows.h>
#include <WinSock2.h>

#define SUCCESS 1
#define FAILURE 0

// Have a struct for each auth type we support
typedef struct NTLMAuthInfo
{
	UINT8* password;
	UINT8* domain;
}PNTLMAuthInfo;

typedef struct AuthInfo
{
	NTLMAuthInfo NTLMAuth;
};

// Define our own 'handle' we'll be passing around this tool and updating as needed
typedef struct ImplantlessHandle
{
	UINT8* ipAddress; // IP address of our target
	UINT8* userName;
	AuthInfo auth;
	SOCKET port135Sock; // Our baseline 135 connection; will reuse for creating new objects
	SOCKET highPortSock; // Our highport connection to use for newly created/accessed object use
}PImplantlessHandle;