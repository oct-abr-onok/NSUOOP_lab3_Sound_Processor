#ifndef CONVERTERS_17
#define CONVERTERS_17

//конвертеры

class converter
{
protected:
public:
};

class mute_conv : public converter
{

};

class mix_conv : public converter
{

};

class replace_conv : public converter
{

};

//фабрики

class converter_factory
{
public:
	virtual converter* create();
};

class mute_factory : public converter_factory
{
	converter* create();
};

class mix_factory : public converter_factory
{
	converter* create();
};

class replace_factory : public converter_factory
{
	converter* create();
};

#endif /*CONVERTERS_17*/