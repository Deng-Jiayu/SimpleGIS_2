#include "HelpPlugin.h"

HelpPlugin::HelpPlugin()
{
}

extern "C" {
	MainInterface* Init() {
		return new HelpPlugin;
	}
}