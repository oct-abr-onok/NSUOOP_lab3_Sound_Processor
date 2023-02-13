#include "config_parser.h"

config_parser::config_parser(std::string file_name) : _file_name(file_name)
{
	std::string buffer;

	std::ifstream fin(_file_name);
	while (true)
	{
		std::getline(fin, buffer);
		if (buffer[0] == '#')
		{
			continue;
		}
		else
		{

		}
	}
}

command config_parser::pop_command()
{
	command command = _commands.front();
	_commands.erase(_commands.begin());
	return command;
}