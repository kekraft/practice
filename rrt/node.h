#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>


/** Simple structure for defining a 3D point and its value */
struct Point{
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	float val = 0.0;

	Point(){;};

	Point(float p_x, float p_y, float p_z){
		x = p_x;
		y = p_y;
		z = p_z;
		float val = 0.0;
	};

	void print(){
		std::cout << "Point: (" << x << ", " << y << ", " << z << ")\n";
	}

	friend float operator-(const Point &p1, const Point &p2){
		return std::sqrt( std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2) + std::pow(p1.z - p1.z,2) );
	};

	static Point get_random_point(float x_min, float x_max, float y_min, float y_max, float z_min, float z_max){
		Point p = Point();

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> x_dis(x_min, x_max);
		p.x = x_dis(gen);

		std::uniform_real_distribution<> y_dis(y_min, y_max);
		p.y = y_dis(gen);

		std::uniform_real_distribution<> z_dis(z_min, z_max);
		p.z = z_dis(gen);
	}


	static Point get_random_point(float min, float max){
		return Point::get_random_point(min, max, min, max, min, max);
	}

};

class Node {
	std::vector<std::shared_ptr<Node>> children;
	std::shared_ptr<Node> parent = nullptr;
	int num_children = 0;
	int max_children = 5;
	Point point = Point();

public:
	Node(){;};
	Node(float x, float y, float z) : Node(){
		Point p;
		p.x = x;
		p.y = y;
		p.z = z;
		this->point = p;
	};
	//~Node();

	const std::vector<std::shared_ptr<Node>> get_children();
	const std::shared_ptr<Node> get_parent();
	void set_parent(std::shared_ptr<Node>);
	bool add_child(std::shared_ptr<Node>);
	void remove_child(std::shared_ptr<Node>);
	bool has_children();
	void set_point(Point p);
	void set_point(float x, float y, float z);
	Point get_point();
	void set_max_children(int);

	void print();

	friend std::ostream& operator<<(std::ostream& os, const Node& node);


};