#ifndef CONVERTERS_17
#define CONVERTERS_17

#include <vector>
#include <string>
#include "wav_io.h"

//конвертеры

class converter
{
protected:
public:
	virtual void work(int p1, int p2, std::string inp_copy, std::vector<std::string> input_files, std::string output_file);
};

class mute_conv : public converter
{
public:
	void work(int p1, int p2, std::string inp_copy, std::vector<std::string> input_files, std::string output_file);
};

class mix_conv : public converter
{
public:
	void work(int p1, int p2, std::string inp_copy, std::vector<std::string> input_files, std::string output_file);
};

class replace_conv : public converter
{
public:
	void work(int p1, int p2, std::string inp_copy, std::vector<std::string> input_files, std::string output_file);
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