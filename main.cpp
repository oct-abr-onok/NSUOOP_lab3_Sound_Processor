#include "main.h"
#include "wav_io.h"
#include "config_parser.h"

int main(int argc, char* argv[])
{
	//парсер команд
	bool helper = false;
	std::string config_file, output_file;
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

	return 0;
}