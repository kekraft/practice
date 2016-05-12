#include <iostream>
#include "open_file.h"


using namespace std;

int main(int argc, char* argv[]){
	cout << "Starting basics driver " << endl;
	cout << "num args: " << argc << endl;

	for (unsigned int i = 0; i < argc; i++){
		cout << "n: " << argv[i] << endl;
	}

	string fname;
	cout << "\nInput file name: ";
	// cin >> fname;
	fname = "ex_txt.txt";
	cout << fname;

	Reader r {fname};
	r.read_file_by_line();
	r.read_file_by_char();

	BetterReader br {fname};
	br.better_method();
	cout << "BR1's fn: " << br.get_filename() << endl;
	br.read_file_by_line();

	BetterReader br2 {};
	br2.better_method();
	cout << "BR2's fn: " << br2.get_filename() << endl;
	br2.read_file_by_line();

	return 0;

}