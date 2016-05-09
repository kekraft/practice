/**
RRT-specific search tree.

Would be nice to make this a template.
*/

#include "rrt_tree.h"

//class RrtTree()

// #define MAIN
	
Tree::Tree(){
	num_nodes = 0;
	root = nullptr;
};

Tree::Tree(std::shared_ptr<Node> n){
	num_nodes = 1;
	root = n;
};

//	~Tree();

const std::shared_ptr<Node> Tree::get_root(void){
	return this->root;
};

void Tree::insert_node(std::shared_ptr<Node> node_ptr){
	this->nodes.push_back(node_ptr);
}

/**
Remove the node ptr from the list of children, not same as deleting

Have to rewire tree...implement later
*/
// void Tree::remove_node(const Node* node_ptr){
// 	this->children.erase(std::remove(this->children.begin(), this->children.end(), node_ptr), this->children.end());

// 	// Erase parents pointer to this node

// 	// Rewire children....
// };


int Tree::get_num_nodes(void){
	return this->num_nodes;
};

const std::vector<std::shared_ptr<Node>> Tree::get_nodes(){
	return this->nodes;
};

void Tree::print(void){
	std::cout << "Root: " << this->root << std::endl;
	std::cout << "Num nodes: " << this->num_nodes << std::endl;

};

// Depth first search.
// Returns true if found.
// Returns false otherwise.
// Does an entire tree traversal if the goal node is nullptr
bool Tree::depth_first_search(std::shared_ptr<Node> goal_node, bool output){
	
	bool entire_traversal = false;

	if (goal_node == nullptr) {
		// do an entire tree traversal
		entire_traversal = true;
	}

	// queue for holding nodes to expand
	std::shared_ptr<Node> cur;
	// boost::lockfree::spsc_queue<std::shared_ptr<Node>> q;
	std::queue<std::shared_ptr<Node>> q;
	q.push(this->root);
	unsigned i = 0;

	// while (q.pop(cur) && ++i){
	while (!q.empty()){
		cur = q.front();
		q.pop();

		if (cur == goal_node || cur == nullptr){
			return true;
		}

		if (output) {
		  std::cout << "At node " << i << " : ";
		  cur->print();
		  std::cout << std::endl;	
		} 

		// Get the children of current node and add them to the end of the queue
		// maybe const
		std::vector<std::shared_ptr<Node>> children = cur->get_children();
		for (std::shared_ptr<Node> n : children){
			// Add to queue if not null
			if (n != nullptr) {
				q.push(n);
			}
		}

	}

	return true; 
}

void Tree::depth_first_traversal(bool output){
	this->depth_first_search(nullptr, output);
}

#ifdef MAIN
int main(){
	while (true){
		Tree* t = new Tree();
		t->print();
		delete t;
	}

	return 0;
}
#endif