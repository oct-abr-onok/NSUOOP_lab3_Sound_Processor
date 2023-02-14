#include "wav_io.h"

wav_input::wav_input(std::string file_name) : _file_name(file_name)
{
	std::ifstream fin(_file_name, std::ios::binary);
	fin.read((char*)&_header, sizeof(WAVHEADER));
	fin.close();
}

sample wav_input::read_sample(int number)
{
	sample res;
	std::ifstream fin(_file_name, std::ios::binary);
	//fin.read((char*)&res, );
	fin.close();
	return 32;
}

wav_output::wav_output(std::string file_name, WAVHEADER header) : _file_name(file_name)
{
	std::ofstream fout(_file_name, std::ios::binary);
	fout.write((char*)&header, sizeof(WAVHEADER));
	fout.close();
}

void wav_output::write_sample(sample sample, int number)
{
}