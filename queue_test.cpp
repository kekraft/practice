#include <boost/lockfree/spsc_queue.hpp>
#include <iostream>


void queue_test(){
	std::cout << "queue_test in progress...\n"; 

	boost::lockfree::spsc_queue<unsigned> q{100};
	std::cout << "queue_test in progress...2\n"; 

	for (unsigned int i = 0; i<100; i++){
		q.push(i);
		std::cout << "Pushed: " << i << std::endl;
	} 

	std::cout << "queue_test in progress...3\n"; 

	// for (unsigned i = 0; i<100; i++){
	// 	unsigned j = q.pop();
		
	// }

	unsigned j;
	while (q.pop(j)){
		std::cout << "Popped: " << j << std::endl;
	}

	std::cout << "queue_test in progress...4\n"; 
}


int main(){
	queue_test();
	return 0;
}