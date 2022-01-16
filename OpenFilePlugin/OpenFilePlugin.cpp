#include "OpenFilePlugin.h"

OpenFilePlugin::OpenFilePlugin()
{
}

extern "C" {
	MainInterface* Init() {
		return new OpenFilePlugin;
	}
}