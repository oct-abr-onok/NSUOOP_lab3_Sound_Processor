#include "main.h"
#include "wav_io.h"
#include "config_parser.h"
#include "converters.h"

void command_apply(converter_factory* cf, int p1, int p2,std::string inp_copy, std::vector<std::string> input_files, std::string output_file)
{
	converter* converter = cf->create();
	converter->work(p1, p2, inp_copy,input_files, output_file);
}

void copy_wav(std::string f1)
{
	wav_input inp(f1);
	wav_output outp("inp_copy.wav", inp._header);
	
	for (unsigned long i = 0; (inp._header.subchunk2Size / 4); i++)
	{
			sample mem = inp.read_sample(i);
			outp.write_sample(mem, i);
	}
}

void move_wav(std::string f1, std::string f2)
{
	wav_input inp(f1);
	wav_output outp(f2, inp._header);

	for (unsigned long i = 0; (inp._header.subchunk2Size / 4); i++)
	{
		sample mem = inp.read_sample(i);
		outp.write_sample(mem, i);
	}
}

int main(int argc, char* argv[])
{
	//парсер команд
	bool helper = false;
	std::string config_file, output_file, inp_copy = "inp_copy.wav";
	std::vector<std::string> input_files;

	std::string buffer;
	bool is_c = false;
	for (int i = 1; i < argc; i++)
	{
		buffer = std::string(argv[i]);
		if (buffer == "-c")
		{
			config_file = std::string(argv[++i]);
			output_file = std::string(argv[++i]);
			input_files.push_back(std::string(argv[++i]));
			is_c = true;
			continue;
		}
		else if (buffer == "-h")
		{
			helper = true;
			continue;
		}
			if (is_c)
		{
			input_files.push_back(std::string(argv[i]));
			continue;
		}
	}

	config_parser c_p(config_file);

	wav_input inp(input_files[0]);
	wav_output outp(output_file, inp._header);

	//тест
	for (unsigned long i = 0; i < 1000/*(inp._header.subchunk2Size / 4)*/; i++)
	{
		sample mem = inp.read_sample(i);
		outp.write_sample(mem, i);
	}

	copy_wav(input_files[0]);
	for (int i = 0; i < c_p._command_number; i++)
	{
		converter_factory* cf;
		command buf = c_p.pop_command();
		if (buf.name == "mute")
		{
			cf = new mute_factory;
		}
		else if (buf.name == "mix")
		{
			cf = new mix_factory;
		}
		else if (buf.name == "replace")
		{
			cf = new replace_factory;
		}
		command_apply(cf, buf.p1, buf.p2, inp_copy, input_files, output_file);
		move_wav(output_file, inp_copy);
	}

	return 0;
}