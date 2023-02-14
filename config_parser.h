#ifndef CONFIG_PARSER_76
#define CONFIG_PARSER_76

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "converters.h"

struct command
{
	std::string name;
	int p1, p2;
};

class config_parser
{
private:
	std::string _file_name;
	std::vector<command> _commands;
public:
	int _command_number;
	config_parser(std::string file_name);
	command pop_command(); //возвращает комманду
};

#endif /*CONFIG_PARSER_76*/
