#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include <boost/lockfree/spsc_queue.hpp>
#include <queue>

#include "node.h"


class Tree {
	int num_nodes;
	std::shared_ptr<Node> root;
	std::vector<std::shared_ptr<Node>> nodes;

public:
	Tree();
	Tree(std::shared_ptr<Node>);
	//~Tree();

	const std::shared_ptr<Node> get_root();
	void insert_node(std::shared_ptr<Node> node);
	// void remove_node(const Node* node);
	int get_num_nodes();
	const std::vector<std::shared_ptr<Node>> get_nodes();

	void print();

	bool depth_first_search(std::shared_ptr<Node> goal_node, bool output);
	void depth_first_traversal(bool output);

	// iterator through tree

	// new root to reorder tree would be a 
	//  nice method for some algs

	// void in_tree(Node* node);
};

class RrtTree : public Tree{

public:
	RrtTree();
	~RrtTree();	
};
