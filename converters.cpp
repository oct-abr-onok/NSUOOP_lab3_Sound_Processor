#include "converters.h"

//конвертеры
void converter::work(int p1, int p2, std::string inp_copy, std::vector<std::string> input_files, std::string output_file)
{
	;
}

void mute_conv::work(int p1, int p2, std::string inp_copy, std::vector<std::string> input_files, std::string output_file)
{
	wav_input inp(inp_copy);
	wav_output outp(output_file, inp._header);

	for (unsigned long i = 0; (inp._header.subchunk2Size / 4); i++)
	{
		if (i > p1 * 44100 && i < p2 * 44100)
		{
			outp.write_sample(0, i);
		}
		else
		{
			sample mem = inp.read_sample(i);
			outp.write_sample(mem, i);
		}
	}
}

void mix_conv::work(int p1, int p2, std::string inp_copy, std::vector<std::string> input_files, std::string output_file)
{
	wav_input inp(inp_copy);
	wav_input inp2(input_files[p1]);
	wav_output outp(output_file, inp._header);

	for (unsigned long i = 0; (inp._header.subchunk2Size / 4); i++)
	{
		if (i > p2 * 44100)
		{
			sample mem = (inp.read_sample(i) + inp2.read_sample(i)) / 2;
			outp.write_sample(mem, i);
		}
		else
		{
			sample mem = inp.read_sample(i);
			outp.write_sample(mem, i);
		}
	}
}

void replace_conv::work(int p1, int p2, std::string inp_copy,std::vector<std::string> input_files, std::string output_file)
{
	wav_input inp(inp_copy);
	wav_input inp2(input_files[p1]);
	wav_output outp(output_file, inp._header);

	for (unsigned long i = 0; (inp._header.subchunk2Size / 4); i++)
	{
		if (i > p2 * 44100)
		{
			sample mem = inp2.read_sample(i);
			outp.write_sample(mem, i);
		}
		else
		{
			sample mem = inp.read_sample(i);
			outp.write_sample(mem, i);
		}
	}

	
}

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
