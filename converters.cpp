#include "converters.h"

//фабрики

converter* converter_factory::create()
{
	return new converter;
}

converter* mute_factory::create()
{
	return new mute_conv;
}

converter* mix_factory::create()
{
	return new mix_conv;
}

converter* replace_factory::create()
{
	return new replace_conv;
}
