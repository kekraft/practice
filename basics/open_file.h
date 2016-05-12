#include <iostream>
#include <string>
#include <vector>


#ifndef READER
#define READER

class Reader{

private:
	// std::string fname;
	unsigned int line;

protected:
	std::string fname;

public:
	Reader(std::string fname);
	void read_file_by_line();
	std::vector<char> read_file_by_char();
	const std::string get_filename();

};

class BetterReader : public Reader {

public:
	BetterReader();
	BetterReader(std::string fname);
	void better_method();
	void read_file_by_line();

};

#endif

