#pragma once

// Interface includes:
#include "IScript.h"
#include "IScriptRequestData.h"

// General includes:
#include "CScriptProvider.h"

// Project includes:
#include "KESSARMPUMID.h"

class KESSARMPUMScriptProvider : public CScriptProvider
{
public:

	KESSARMPUMScriptProvider(IPMUnknown* boss);

	virtual ErrorCode HandleMethod(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

	//virtual ErrorCode AccessProperty(ScriptID propID, IScriptRequestData* data, IScript* parent);

private:

	virtual ErrorCode Test(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);
};