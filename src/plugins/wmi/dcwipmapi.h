/******************************************************************
  Copyright (c) 2008, Dell Inc
  All rights reserved.
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
																		    
  - Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution. 
  - Neither the name of Dell Inc nor the names of its contributors
    may be used to endorse or promote products derived from this software 
    without specific prior written permission. 
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. 
 
//
//  Environment:
//    Linux, NetWare, Windows NT/2000/2003
//
******************************************************************/

#ifndef __DCWIPMAPI_H_INCLUDED__
#define __DCWIPMAPI_H_INCLUDED__


//---------------------------------------------------------------------
// Include files this header is dependent on
//---------------------------------------------------------------------
#include <dcwipmdef.h>


//---------------------------------------------------------------------
// Includes end
//---------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

	
//---------------------------------------------------------------------
// Function Prototypes
//---------------------------------------------------------------------

//---------------------------------------------------------------------
/**
 * This function opens a WMI session to the OS IPMI driver interface
 * A new session will be opened and initialized or an already open
 * session (from a previous call) will be returned instead.
 *
 * @note use DCWIPMSessionClose to close the session handle
 *
 * @return a generic handled to the session
 *
 * @return NULL if a session could not be opened
 *
 * @sa DCWIPMSessionClose
 */
//---------------------------------------------------------------------
SMINTF void * DCWIPMSessionOpen(
				void
				);

//---------------------------------------------------------------------
/**
 * This function closes a WMI session to the OS IPMI driver interface
 * The opened session will perform cleanup and closed
 * session (from a previous call) will be returned instead.
 *
 * @param pSession [in] generic handle to the open session
 *
 * @sa DCWIPMSessionOpen
 */
//---------------------------------------------------------------------
SMINTF void DCWIPMSessionClose(
				_IN void *pSession
				);

//---------------------------------------------------------------------
// DCWIPMIPMBRequest
//---------------------------------------------------------------------
SMINTF s32 DCWIPMIPMBRequest(
				_IN void *pSession,
				_IN u8 rsSa, 
				_INOUT u8 *pNetFnLun, 
				_IN u8 RequestCommand, 
				_IN u16 RequestDataLength, 
				_IN u8 *pRequestData, 
				_OUT u8 *pResponse, 
				_OUT u16 *pResponseLength,
				_OUT u8 *pCompletionCode
				);

//---------------------------------------------------------------------
// DCWIPMRequest
//---------------------------------------------------------------------
SMINTF s32 DCWIPMRequest(
				_IN void *pSession,
				_INOUT u8 *pNetFnLun, 
				_IN u8 RequestCommand, 
				_IN u16 RequestDataLength, 
				_IN u8 *pRequestData, 
				_OUT u8 *pResponse, 
				_OUT u16 *pResponseLength,
				_OUT u8 *pCompletionCode
				);

//---------------------------------------------------------------------
// DCWIPMSMSMsgAttn
//---------------------------------------------------------------------
SMINTF s32 DCWIPMSMSMsgAttn(
				_IN void *pSession, 
				_OUT booln *SMS_ATNFlag
				);


//---------------------------------------------------------------------
// Header Code Ends
//---------------------------------------------------------------------


#ifdef __cplusplus
}
#endif


#endif // __DCWIPMAPI_H_INCLUDED__

