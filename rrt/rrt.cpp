#include <iostream>
#include <string>

/** Simple structure for defining a 3D point and its value */
struct Point{
	float x;
	float y;
	float z;
	float val;

	void print(){
		std::cout << "Point: (" << x << ", " << y << ", " << z << ")\n";
	}
};

void rrt_search(Point start, Point goal, float search_dist = 0.2){
	// Search tree...
	// search_tree = 

}


