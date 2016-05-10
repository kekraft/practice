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

// void Tree::set_root(std::shared_ptr<Node> root){
// 	this->root = root;
// 	num_nodes = 1;
// }

const std::shared_ptr<Node> Tree::get_root(void){
	return this->root;
};

/**
Inserts the node in the tree, as a child of the parent node.
If the tree is empty AND if the parent is null, then the the node becomes the root of the tree
Not set to handle cases where node ptr is null, nor where there is a root and parent node ptr is null
*/
void Tree::insert_node(std::shared_ptr<Node> node_ptr, std::shared_ptr<Node> parent_node_ptr){
	if (this->root == nullptr && parent_node_ptr == nullptr){
		this->root = node_ptr;

	} else {
		parent_node_ptr->add_child(node_ptr);
		node_ptr->set_parent(parent_node_ptr);
	}

	this->num_nodes += 1;
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

	this->depth_first_traversal(true);
};

std::shared_ptr<Node> Tree::get_node(Point goal_point , float equiv_thresh = 0.001){
	
	// queue for holding nodes to expand
	std::shared_ptr<Node> cur;
	std::queue<std::shared_ptr<Node>> q;
	q.push(this->root);

	while (!q.empty()){
		cur = q.front();
		q.pop();

		// if (cur == nullptr){
		//  std::cout << "Tree error!.\n"; // Tree error	
		//  sys.exit(-1);
		// }

		Point node_point = cur->get_point();
		if (std::abs(node_point - goal_point) < equiv_thresh){
			return cur;
		} else {
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

	}

	// the goal point/node isn't found
	return nullptr;


}

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
	while (!q.empty() && ++i){
		cur = q.front();
		q.pop();

		if (cur == goal_node || cur == nullptr){
			return true;
		}

		if (output) {
		  //std::cout << "At node " << i << " : ";
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

std::shared_ptr<Node> Tree::get_closest_node(Point p){
	// cycle through all nodes in the tree and get dist
	float min_dist = 99999;
	std::shared_ptr<Node> closest = nullptr;

	for (std::shared_ptr<Node> n: this->get_nodes()){
		float dist = p - n->get_point();

		if (dist < min_dist){
			min_dist = dist;
			closest = n;
		}
	}

	return closest;
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