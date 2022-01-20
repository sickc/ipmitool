/****************************************************************************
  Copyright (c) 2006 - 2010, Dell Inc
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
 
 
*****************************************************************************/
#include "ipmitool/cssipmi.h"
#include "ipmitool/cssapi.h"
#include "ipmitool/csssupt.h"

/****************************************************************************
    Variables
****************************************************************************/

/* StatusTable */
char * g_StatusTable[] =
{
  "Unknown",
  "Informational",
  "Normal",
  "Warning",
  "Critical",
  "Non-Recoverable"
};
unsigned int g_StatusTableSize = sizeof(g_StatusTable)/sizeof(g_StatusTable[0]);

/* Sensor Type String Table */
char  g_FanReduntant[] = "Fan Redundancy";
char  g_PSReduntant[]  = "PS Redundancy";

char* g_SensorTypesTable[] =
{
  "Unknown","Temperature","Voltage","Current","Fan","Intrusion", 
  "Secure Mode","Processor","Power Supply","Power Unit","Cooling Unit",
  "Other Units","Memory","Drive Slot","Memory Resize","Post","Event Log",
  "Watchdog","System Event","Critical Event","Button","Module",
  "Micro Controller","Add-in Card","Chassis","Chip Set","Other FRU","Cable",
  "Terminator","System Boot","Boot Error","OS Event","OS Stop","Slot ",
  "ACPI","Watchdog","Platform","Presence","ASIC Monitor","LAN","Health", 
  "Battery","Session Audit","Version Change","FRU"
};
unsigned int g_SensorTypesTableSize = sizeof(g_SensorTypesTable)/sizeof(g_SensorTypesTable[0]);

char* g_EntityTable[] =
{
  "unspecified","other","unspecified","processor","disk area","peripheral bay", 
  "system management module","system board","memory module","processor module","power supply",
  "add-in card","front panel","back panel","power system","drive backplane","internal expansion",
  "other system board","processor board","power unit","power module","power management",
  "chassis back panel","chassis","sub-chassis","chassis board","disk drive bay","peripheral bay",
  "device bay","fan","cooling unit","cable","memory device","system management software",
  "system firmware","operating system","system bus","group","out-of-band","external environment","battery", 
  "server","connectivity switch","processor/memory module","I/O module","processor I/O module",
  "management controller firmware","IPMI channel","PCI bus","PCIe bus","SCSI bus","SATA/SAS bus","processor bus",
  "real time clock","system firmware","air inlet","reserved","reserved","reserved","reserved","reserved","reserved","reserved","reserved",
  "air inlet","processor","baseboard"
};
unsigned int g_EntityTableSize = sizeof(g_EntityTable)/sizeof(g_EntityTable[0]);

char g_defaultPostError[]     = "POST fatal error detected.";
PostCodeType g_PostMessages[] =
{
  {0x00, "No POST Code",                              CSS_SEVERITY_NORMAL, NULL},
  {0x01, "System Power On",                           CSS_SEVERITY_NORMAL, NULL}, 
  {0x02, "CPU Microcode load",                        CSS_SEVERITY_NORMAL, NULL},
  {0x03, "Chipset Initialization",                    CSS_SEVERITY_NORMAL, NULL},
  {0x04, "Memory Configuration",                      CSS_SEVERITY_NORMAL, NULL},
  {0x05, "Shadow BIOS",                               CSS_SEVERITY_NORMAL, NULL},
  {0x06, "Multiprocessor Initialization",             CSS_SEVERITY_NORMAL, NULL},
  {0x07, "POST processing start",                     CSS_SEVERITY_NORMAL, NULL},
  {0x08, "SMM Mode Initialization",                   CSS_SEVERITY_NORMAL, NULL},
  {0x09, "PCI Bus Enumeration & Video initialization",CSS_SEVERITY_NORMAL, NULL},
  {0x0A, "BMC is ready",                              CSS_SEVERITY_NORMAL, NULL},
  {0x0B, "Extended Memory test started",              CSS_SEVERITY_NORMAL, NULL},
  {0x0C, "Extended Memory test running \\",           CSS_SEVERITY_NORMAL, NULL},
  {0x0D, "Extended Memory test running /",            CSS_SEVERITY_NORMAL, NULL},
  {0x0E, "Extended Memory test completed",            CSS_SEVERITY_NORMAL, NULL},
  {0x40, "Display sign-on",                           CSS_SEVERITY_NORMAL, NULL},
  {0x41, "PCI Configuration",                         CSS_SEVERITY_NORMAL, NULL},
  {0x7F, "Given control to OS",                       CSS_SEVERITY_NORMAL, NULL},
  {0x80, "No memory is detected.",                    CSS_SEVERITY_CRITICAL, "PST0128"},
  {0x81, "Memory is detected but is not configurable.",   CSS_SEVERITY_CRITICAL, "PST0129"},
  {0x82, "Memory is configured but not usable.",       CSS_SEVERITY_CRITICAL, "PST0130"},
  {0x83, "System BIOS shadow failed.",                 CSS_SEVERITY_CRITICAL, "PST0131"},
  {0x84, "CMOS failed.",                               CSS_SEVERITY_CRITICAL, "PST0132"},
  {0x85, "DMA controller failed.",                     CSS_SEVERITY_CRITICAL, "PST0133"},
  {0x86, "Interrupt controller failed.",               CSS_SEVERITY_CRITICAL, "PST0134"},
  {0x87, "Timer refresh failed.",                      CSS_SEVERITY_CRITICAL, "PST0135"},
  {0x88, "Programmable interval timer error.",         CSS_SEVERITY_CRITICAL, "PST0136"},
  {0x89, "Parity error.",                              CSS_SEVERITY_CRITICAL, "PST0137"},
  {0x8A, "SIO failed.",                                CSS_SEVERITY_CRITICAL, "PST0138"},
  {0x8B, "Keyboard controller failed.",                CSS_SEVERITY_CRITICAL, "PST0139"},
  {0x8C, "System management interrupt initialization failed.",CSS_SEVERITY_CRITICAL, "PST0140"},
  {0xC0, "Shutdown test failed.",                      CSS_SEVERITY_CRITICAL, "PST0192"},
  {0xC1, "BIOS POST memory test failed",              CSS_SEVERITY_CRITICAL, "PST0193"},
  {0xC2, "Remote access controller configuration failed.",CSS_SEVERITY_CRITICAL, "PST0194"},
  {0xC3, "CPU configuration failed.",                  CSS_SEVERITY_CRITICAL, "PST0195"},
  {0xC4, "Incorrect memory configuration.",            CSS_SEVERITY_CRITICAL, "PST0196"},
  {0xFE, "General failure after video.",               CSS_SEVERITY_CRITICAL, "PST0254"}
};
unsigned char g_PostMessagesSize = sizeof(g_PostMessages)/sizeof(g_PostMessages[0]);
