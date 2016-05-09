#include <cstdlib>
#include <iostream>
#include <string>


// Reverses string in place
void reverse_string(std::string& s){
	for (unsigned i = 0, j = s.length() - 1; i < s.length() / 2; i++, j--){
		char tmp, front, back;
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;

		std::cout << "i: " << i << "   j:  " << j << std::endl;
	}
}


int main(){

	// quick and dirty hello world
	std::string msg = "Hello World!";
	std::cout << msg << std::endl;
	
	// reversing the string
	reverse_string(msg);
	std::cout << msg << std::endl;
	
	return 0;
}