#include <string>
#include <iostream>
#include "node.h"

void Node_Navigate::traverse_from_node(Node* node, int indent)
{
	std::string indent_char = std::string(indent,' ');
	if (node->ch != '\0')
	{
		std::cout << indent_char << node->ch << " - " << node->sum <<"\n";
	}
	else
	{
		std::cout << indent_char << node->sum << "\n";
	}
	if (node->l_node)
	{
		this->traverse_from_node(node->l_node, indent+1);
	}
	if (node->r_node)
	{
		this->traverse_from_node(node->r_node, indent + 1);
	}
}