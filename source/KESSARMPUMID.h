//========================================================================================
//  
//  $File: $
//  
//  Owner: 
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================


#ifndef __KESSARMPUMID_h__
#define __KESSARMPUMID_h__

#include "SDKDef.h"

// Company:
#define kKESSARMPUMCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kKESSARMPUMCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kKESSARMPUMPluginName	"KohakuExtendScriptShiftAndRightMousePopUpMenu"			// Name of this plug-in.
#define kKESSARMPUMPrefixNumber	0x204673 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kKESSARMPUMVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kKESSARMPUMAuthor		""					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kKESSARMPUMPrefixNumber above to modify the prefix.)
#define kKESSARMPUMPrefix		RezLong(kKESSARMPUMPrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kKESSARMPUMStringPrefix	SDK_DEF_STRINGIZE(kKESSARMPUMPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kKESSARMPUMMissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kKESSARMPUMMissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kKESSARMPUMPluginID, kKESSARMPUMPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kKESSARMPUMScriptProviderBoss, kKESSARMPUMPrefix + 3)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 4)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 5)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 6)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 7)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 8)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 9)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 10)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 11)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 12)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 13)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 14)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 15)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 16)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 17)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 18)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 19)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 20)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 21)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 22)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 23)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 24)
//DECLARE_PMID(kClassIDSpace, kKESSARMPUMBoss, kKESSARMPUMPrefix + 25)


// InterfaceIDs:
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 0)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 1)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 2)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 3)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 4)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 5)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 6)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 7)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 8)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 9)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 10)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 11)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 12)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 13)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 14)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 15)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 16)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 17)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 18)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 19)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 20)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 21)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 22)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 23)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 24)
//DECLARE_PMID(kInterfaceIDSpace, IID_IKESSARMPUMINTERFACE, kKESSARMPUMPrefix + 25)


// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMScriptProviderImpl, kKESSARMPUMPrefix + 0 )
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 1)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 2)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 3)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 4)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 5)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 6)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 7)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 8)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 9)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 10)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 11)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 12)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 13)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 14)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 15)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 16)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 17)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 18)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 19)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 20)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 21)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 22)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 23)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 24)
//DECLARE_PMID(kImplementationIDSpace, kKESSARMPUMImpl, kKESSARMPUMPrefix + 25)


// ActionIDs:
DECLARE_PMID(kActionIDSpace, kKESSARMPUMAboutActionID, kKESSARMPUMPrefix + 0)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 5)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 6)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 7)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 8)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 9)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 10)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 11)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 12)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 13)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 14)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 15)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 16)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 17)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 18)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 19)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 20)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 21)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 22)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 23)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 24)
//DECLARE_PMID(kActionIDSpace, kKESSARMPUMActionID, kKESSARMPUMPrefix + 25)


// WidgetIDs:
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 2)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 3)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 4)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 5)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 6)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 7)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 8)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 9)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 10)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 11)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 12)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 13)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 14)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 15)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 16)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 17)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 18)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 19)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 20)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 21)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 22)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 23)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 24)
//DECLARE_PMID(kWidgetIDSpace, kKESSARMPUMWidgetID, kKESSARMPUMPrefix + 25)

//Script Element IDs

DECLARE_PMID(kScriptInfoIDSpace, kKESSARMPUMMethodScriptElement, kKESSARMPUMPrefix + 1)
DECLARE_PMID(kScriptInfoIDSpace, kKESSARMPUMPropertyScriptElement, kKESSARMPUMPrefix + 2)


// "About Plug-ins" sub-menu:
#define kKESSARMPUMAboutMenuKey			kKESSARMPUMStringPrefix "kKESSARMPUMAboutMenuKey"
#define kKESSARMPUMAboutMenuPath		kSDKDefStandardAboutMenuPath kKESSARMPUMCompanyKey

// "Plug-ins" sub-menu:
#define kKESSARMPUMPluginsMenuKey 		kKESSARMPUMStringPrefix "kKESSARMPUMPluginsMenuKey"
#define kKESSARMPUMPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kKESSARMPUMCompanyKey kSDKDefDelimitMenuPath kKESSARMPUMPluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kKESSARMPUMAboutBoxStringKey	kKESSARMPUMStringPrefix "kKESSARMPUMAboutBoxStringKey"
#define kKESSARMPUMTargetMenuPath kKESSARMPUMPluginsMenuPath

// Menu item positions:


// Initial data format version numbers
#define kKESSARMPUMFirstMajorFormatNumber  RezLong(1)
#define kKESSARMPUMFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kKESSARMPUMCurrentMajorFormatNumber kKESSARMPUMFirstMajorFormatNumber
#define kKESSARMPUMCurrentMinorFormatNumber kKESSARMPUMFirstMinorFormatNumber

#endif // __KESSARMPUMID_h__
