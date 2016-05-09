#include "node.h"

// #define MAIN

const std::shared_ptr<Node> Node::get_parent(){
	return this->parent;
};

void Node::set_parent(std::shared_ptr<Node> parent_node){
	this->parent = parent_node;
};

/**
Adds child to node.
If the node has max children, the node wont be added.
If child added, true is returned. False o.w.
*/
bool Node::add_child(std::shared_ptr<Node> child_node_ptr){
	if (this->num_children == this->max_children) {
		return false;	
	}
	this->children.push_back(child_node_ptr);
	return true;
};

void Node::remove_child(std::shared_ptr<Node> child_node_ptr){
	this->children.erase(std::remove(this->children.begin(), this->children.end(), child_node_ptr), this->children.end());;

};

const std::vector<std::shared_ptr<Node>> Node::get_children(){
	return this->children;
};

bool Node::has_children(){
  return (num_children > 0) ? true : false;
};

float Node::get_data(){
	return this->data;
};

void Node::set_data(float new_data){
	this->data = new_data;
};

void Node::set_max_children(int max_children){
	this->max_children = max_children;
}

void Node::print(){
	std::cout << "Node data: " << this->data << "\n";
	if (this->parent != nullptr) {
		std::cout << "Parent: " << this->parent->data << "\n";	
	} else {
		std::cout << "Parent: " << " NULL" << "\n";	
	}
	
	std::cout << "Total Children: " << this->num_children << "\n";
}

// #ifdef MAIN
// int main(){
// 	std::cout << "Making basic node" << std::endl;
// 	while( true ){
// 	  Node* n = new Node();
// 	  n->print();	
// 	  delete n;
// 	}	
// 	return 0;
// }
// #endif
