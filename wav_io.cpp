#include "wav_io.h"

wav_input::wav_input(std::string file_name) : _file_name(file_name)
{
	std::ifstream fin(_file_name, std::ios::binary);
	fin.read((char*)&_header, sizeof(WAVHEADER));
	_position = fin.tellg();
	fin.close();
}

sample wav_input::read_sample(unsigned long number)
{
	sample res = 0;
	std::ifstream fin(_file_name, std::ios::in | std::ios::binary);
	//fin.clear();
	fin.seekg(_position, std::ios::beg);
	fin.read((char*)&res, sizeof(sample));
	fin.close();
	_position = fin.tellg();
	return res;
}

wav_output::wav_output(std::string file_name, WAVHEADER header) : _file_name(file_name)
{
	std::ofstream fout(_file_name, std::ios::binary);
	fout.write((char*)&header, sizeof(WAVHEADER));
	_position = fout.tellp();
	fout.close();
}

void wav_output::write_sample(sample sample, unsigned long number)
{
	std::ofstream fout(_file_name, std::ofstream::binary);
	auto test = fout.tellp();
	fout.seekp(_position, std::ios::beg);
	auto test2 = fout.tellp();
	fout.write((char*)&sample, sizeof(sample));
	_position = fout.tellp();
	fout.close();
}