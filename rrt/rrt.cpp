#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <sstream>

#include "rrt_tree.h"


int main(int argc, char const *argv[]){

	float start_x, start_y, start_z;
	float goal_x, goal_y, goal_z;

	std::cout << "\nInput start x: ";
	std::cin >> start_x;
	std::cout << "\nInput start y: ";
	std::cin >> start_y;
	std::cout << "\nInput start z: ";
	std::cin >> start_z;

	std::cout << "\n\nInput goal x: ";
	std::cin >> goal_x;
	std::cout << "\nInput goal y: ";
	std::cin >> goal_y;
	std::cout << "\nInput goal z: ";
	std::cin >> goal_z;

	unsigned int max_pts;
	std::cout << "\n\nMax pts: ";
	std::cin >> max_pts;

	float delta;
	std::cout << "\n\nDelta dist: ";
	std::cin >> delta;

	float min_space, max_space;
	std::cout << "\n\nMin space pt (for box): ";
	std::cin >> min_space;
	std::cout << "Max space pt (for box): ";
	std::cin >> max_space;

	Point start = Point(start_x, start_y, start_z);
	Point goal = Point(goal_x, goal_y, goal_z);

	std::cout << "\n\n\n";
	start.print();
	goal.print();

	Tree t = Tree();
	std::shared_ptr<Node> null_shared_ptr;
	t.insert_node(start, null_shared_ptr);

	for (unsigned int i = 0; i < max_pts; i++){
		// get random pt in search space
		Point rand_pt = Point::get_random_point(min_space, max_space);

		// pick closest pt in tree
		Node n = t.get_closest_node(rand_pt);
	}

	return 0;
}




