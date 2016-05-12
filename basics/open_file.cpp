#include <fstream>

#include "open_file.h"

using namespace std;

Reader::Reader(string f){
	line = 0;
	fname = f;
}

const string Reader::get_filename(){
	return fname;
}

void Reader::read_file_by_line(){
	ifstream ifs {fname, ifstream::in};
	if (ifs.good()){
		string a {};
		while (getline(ifs, a)){	;
			cout << "Got line: " << a << endl;
		}
	} else {
		cerr << "Error opening file: " << fname << endl;
		throw 20;
	}

	ifs.close();

}

vector<char> Reader::read_file_by_char(){
	ifstream ifs {fname, ifstream::in};
	vector<char> chars {};
	if (ifs.good()){
		while (!ifs.eof()){
			char c = ifs.get();
			chars.push_back(c);
			cout << "Got char: " << c << endl;
		}
	} else {
		cerr << "Error opening file: " << fname << endl;
		throw 20;
	}

	ifs.close();

	return chars;

}

BetterReader::BetterReader() : Reader("") {}

BetterReader::BetterReader(string fname) : Reader(fname){}

void BetterReader::better_method(){
	cout << "Better method from better reader " << endl;
	cout << "fname: " << fname << endl;
}

/**
This function reads it one token at a time using whitespace as a delimeter
Doesn't read one line at a time, only called that to play around with function overriding.
*/
void BetterReader::read_file_by_line(){
	ifstream ifs {fname, ifstream::in};

	if (ifs.good()){
		cout << "outputing read data...\n";
		while (!ifs.eof()){
			string a {};
			
			ifs >> a;
			cout << a << endl;
		}
	} else {
		cerr << "Error opening file: " << fname << endl;
		throw 20;
	}

	ifs.close();
	cout << "Does better reading method " << endl;

}



