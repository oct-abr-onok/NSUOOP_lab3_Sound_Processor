#include "config_parser.h"

config_parser::config_parser(std::string file_name) : _file_name(file_name)
{
	int commandNumber = 0;
	std::string buffer;
	std::ifstream fin(_file_name);
	command mem;

	while (std::getline(fin, buffer))
	{
		if (buffer[0] == '#')
		{
			continue;
		}
		else
		{
			char separator = ' ';
			int flag = 0;

			for (int i = 0;; i++)
			{
				std::string s;

				while (buffer[i] != separator && buffer[i] != '\0')
				{
					s.push_back(buffer[i]);
					i++;
				}
				// запись команды
				if (flag == 0)
				{
					mem.name = s;
					flag++;
				}
				else if (flag == 1)
				{
					// избаление'$'
					if (s[0] == '$')
						s.erase(s.begin());

					mem.p1 = stoi(s);
					flag++;
				}
				else if (flag == 2)
				{
					// избавление от '$'
					if (s[0] == '$')
						s.erase(s.begin());

					mem.p2 = stoi(s);
					flag = 0;
					_commands.push_back(mem);
					commandNumber++;
				}
				if (buffer[i] == '\0')
				{
					break;
				}
			}
		}
	}
	_command_number = commandNumber;
}

command config_parser::pop_command()
{
	command command = _commands.front();
	_commands.erase(_commands.begin());
	return command;
}