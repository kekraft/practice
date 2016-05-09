#include <random>
#include "rrt.cpp"
#include "rrt_tree.h"

#include <fstream>
#include <sstream>


#define USER_INPUT false
#define TEST 

bool test_point(){
	Point test;
	test.print();

	test.x = 1.0;
	test.y = 1.1;
	test.z = 2.3;
	test.val = 2.4;
	std::cout << "Hardcoded point:\n";
	test.print();

	// random value assignment
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-10,10);
	test.x = dis(gen);
	test.y = dis(gen);
	test.z = dis(gen);
	test.val = dis(gen);
	std::cout << "Randomly generated pt: \n";
	test.print();

	return true;

}

bool test_node(){
	std::cout << "Testing node...\n";
	// Test empty node
	Node n = Node();
	n.print();

	n.set_data(10.2);
	n.print();

	Node n2 = Node();
	n2.set_data(2.0202);
	// n2.set_parent()

	std::cout << "Done testing node.\n";
	return true;

}

bool test_tree(){
	std::string fstring = "tree_data_1.txt";

	std::cout << "Testing tree...\n";
	Tree tree = Tree();
	float dist_thresh = 0.001;

	/** Reads in the file with the test tree data.
	  This expects the first line of the file to be a comment line.
	  The other lines are expected to be two integers seperated by a space.
	  The first int is the node data, the second is the nodes parent data.
	  At this point, the tree is assumed to have unique data entries.
	  If an integer is -999, then this is considered to be null and is set as the root
	  */
	std::cout << "Reading file " << fstring;

	std::ifstream f;
	f.open(fstring);
	std::string line;
	std::getline(f, line); // Eat the comment line
	while (!f.eof()){
		std::getline(f, line);
		// std::cout << std::endl << line << std::endl;
		std::istringstream iss(line);
		int a,b;
		iss >> a >> b; 
		// iss >> b;
		std::cout << std::endl << "A: " << a << "  B: " << b << std::endl;

		Node n = Node();
		n.set_data(a);
		std::shared_ptr<Node> n_ptr = std::make_shared<Node>(n);

		std::shared_ptr<Node> p_ptr;
		if (b == -999) {
			p_ptr = nullptr;
			
		} else {
			p_ptr = tree.get_node(b, dist_thresh);
		}
		
		tree.insert_node(n_ptr, p_ptr);
		n.print();

	}

	tree.print();



}


int main(int argc, char const *argv[]){
	std::cout << "Starting program" << std::endl;

	#ifdef TEST
	  // test_point();
	  // test_node();
	  test_tree();
	#endif

	Point start_point, goal_point;

	start_point.print();
	
	#if USER_INPUT == true
		std::cout << "Enter x val for starting point\n";
		std::cin >> start_point.x;
		std::cout << "Enter y val for starting point\n";
		std::cin >> start_point.y;
		std::cout << "Enter z val for starting point\n";
		std::cin >> start_point.z;
		start_point.val = 0.0;

		std::cout << "Enter x val for goal point\n";
		std::cin >> goal_point.x;
		std::cout << "Enter y val for goal point\n";
		std::cin >> goal_point.y;
		std::cout << "Enter z val for goal point\n";
		std::cin >> goal_point.z;
		goal_point.val = 0.0;
	#endif

	start_point.print();

	// rrt_search(start_point, goal_point);



	return 0;
}