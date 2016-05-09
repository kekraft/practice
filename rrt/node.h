#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

class Node {
	std::vector<std::shared_ptr<Node>> children;
	std::shared_ptr<Node> parent = nullptr;
	int num_children = 0;
	int max_children = 2;
	float data = 0.0;

public:
	//Node();
	//~Node();

	const std::vector<std::shared_ptr<Node>> get_children();
	const std::shared_ptr<Node> get_parent();
	void set_parent(std::shared_ptr<Node>);
	bool add_child(std::shared_ptr<Node>);
	void remove_child(std::shared_ptr<Node>);
	bool has_children();
	void set_data(float);
	float get_data();
	void set_max_children(int);

	void print();


};