#include "FirstPlugin.h"

FirstPlugin::FirstPlugin()
{
}

extern "C" {
	MainInterface* Init()
	{
		return new FirstPlugin;
	}
}