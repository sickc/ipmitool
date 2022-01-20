/*
 * Copyright (c) 2003 Sun Microsystems, Inc.  All Rights Reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * Redistribution of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 
 * Redistribution in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of Sun Microsystems, Inc. or the names of
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * 
 * This software is provided "AS IS," without a warranty of any kind.
 * ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED.
 * SUN MICROSYSTEMS, INC. ("SUN") AND ITS LICENSORS SHALL NOT BE LIABLE
 * FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, MODIFYING
 * OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.  IN NO EVENT WILL
 * SUN OR ITS LICENSORS BE LIABLE FOR ANY LOST REVENUE, PROFIT OR DATA,
 * OR FOR DIRECT, INDIRECT, SPECIAL, CONSEQUENTIAL, INCIDENTAL OR
 * PUNITIVE DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF
 * LIABILITY, ARISING OUT OF THE USE OF OR INABILITY TO USE THIS SOFTWARE,
 * EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <ipmitool/ipmi.h>
#include <ipmitool/ipmi_intf.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif


#define SYSTEM_TYPE_LINUX
#define SYSTEM_TYPE_CYGWIN

#include "dcossdk.h"
#include "dcdetypes.h"
#include "dcwipmapi.h"
#include "dcwipmdef.h"

#include "wmi.h"


    FPROCDCWIPMSESSIONOPEN fpDCWIPMSessionOpen;
	FPROCDCWIPMSESSIONCLOSE fpDCWIPMSessionClose;
	FPROCDCWIPMIPMBREQUEST fpDCWIPMIPMBRequest;
	FPROCDCWIPMREQUEST fpDCWIPMRequest;
	FPROCDCWIPMSMSMSGATTN fpDCWIPMSMSMsgAttn;


struct ipmi_intf ipmi_wmi_intf = {
	name:		"wmi",
	desc:		"Windows IPMI Interface",
	open:		ipmi_wmi_open,
	close:		ipmi_wmi_close,
	sendrecv:	ipmi_wmi_send_cmd,
};
DCWIPMLibObj session = {0};

static int
ipmi_wmi_open(struct ipmi_intf * intf)
{
	void * ret;
	char * dllFileName = "dcwipm32.dll";
	
	ret = dlopen(dllFileName, RTLD_NOW);
	if (ret == NULL) {
		printf("Error, cannot load file %s Error: %s\n", dllFileName, dlerror() );
	} else {
	}
	
	fpDCWIPMSessionOpen = dlsym( ret, FSTRDCWIPMSESSIONOPEN );
	if (fpDCWIPMSessionOpen == NULL) {
		printf("Failure to get open function\n");
	}
	else {
	}

    if (intf->opened == 0) {
	   intf->pWinSession = fpDCWIPMSessionOpen();
       if (intf->pWinSession == NULL) {
	      printf("error opening session\n");
       } else {
       }
	}
	intf->opened = 1;
}

static void ipmi_wmi_close(struct ipmi_intf * intf)
{
    if (intf->opened == 1) {
	   fpDCWIPMSessionClose(intf->pWinSession);
       if (intf->pWinSession == NULL) {
	      printf("error closing session\n");
       } else {
       }
	}
	intf->opened = 0;
}

static struct ipmi_rs * ipmi_wmi_send_cmd(struct ipmi_intf * intf, struct ipmi_rq * req)
{
	static struct ipmi_rs rsp;
	int rc;
	uint8_t netfnlun;
	DWORD error;
	void * ret;
	uint8_t msgcmd;
	uint16_t msgdatalen;
	uint8_t msgdata[IPMI_BUF_SIZE];
	int i;
	
	netfnlun = (req->msg.netfn << 2) | req->msg.lun;

	char * dllFileName = "dcwipm32.dll";

	ret = dlopen(dllFileName, RTLD_NOW);

	if (ret == NULL) {
		printf("Error, cannot load file %s, Error: %s\n", dllFileName, dlerror() );
		printf("Please make sure Windows IPMI Driver is installed and running. \n");
		return NULL;
	} else {
	}

	fpDCWIPMSessionOpen = dlsym( ret, FSTRDCWIPMSESSIONOPEN );
	if (fpDCWIPMSessionOpen == NULL) {
		printf("Failure to get open function\n");
		return NULL;
	}
	else {
	}

    fpDCWIPMRequest = dlsym( ret, FSTRDCWIPMREQUEST );
	if (fpDCWIPMRequest == NULL) {
		printf("Failure to get request function\n");
		return NULL;
	}
	else {
	}

    const char *dlsym_error = dlerror(); 

    intf->pWinSession = fpDCWIPMSessionOpen();
    if (intf->pWinSession == NULL) {
	   printf("error opening session\n");
	   return NULL;
    } else {
    }

    msgcmd = req->msg.cmd;
    msgdatalen = req->msg.data_len;
    for (i=0; i<msgdatalen; i++) {
	   msgdata[i] = req->msg.data[i];
    }

    rsp.data_len = IPMI_BUF_SIZE;
 
    rc = fpDCWIPMRequest(   intf->pWinSession,
							&netfnlun,
							msgcmd,
							msgdatalen,
							msgdata,
							rsp.data,
							&rsp.data_len,
							&rsp.ccode);

	if (rc != 0) {
	   printf("Error sending WMI request, status=%x ccode=%x\n", rc, rsp.ccode);
	}
	return &rsp;
}
