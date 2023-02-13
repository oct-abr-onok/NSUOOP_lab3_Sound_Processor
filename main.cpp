#include "main.h"

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




	return 0;
}