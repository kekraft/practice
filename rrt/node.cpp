#include "node.h"

// #define MAIN


// Node::Node : Node::Node() (float x, float y, float z){
// 	// Node();
// 	Point p = Point();
// 	p.x = x;
// 	p.y = y;
// 	p.z = z;
// 	this->p = p;
// }

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
	this->num_children ++;
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

Point Node::get_point(){
	return this->point;
};

void Node::set_point(Point point){
	this->point = point;
};

void Node::set_point(float x, float y, float z){
	Point p = Point();
	p.x = x;
	p.y = y;
	p.z = z;
	this->point = p;
};

void Node::set_max_children(int max_children){
	this->max_children = max_children;
}

void Node::print(){
	std::cout << "Node point: ";
	this->point.print();
	if (this->parent != nullptr) {
		// std::cout << "Parent: " << this->parent->point << "\n";	
		std::cout << "Parent: ";
		this->parent->point.print();
	} else {
		std::cout << "Parent: " << " NULL" << "\n";	
	}
	
	std::cout << "Total Children: " << this->num_children << "\n";
}

// ostream& operator<<(ostream& os, const Node& node)
// {
//     os << "Node point: " << '/' << dt.da << '/' << dt.yr;
//     return os;
// }


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
