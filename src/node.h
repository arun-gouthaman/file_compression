class Node
{
    public:
    char ch = '\0';
    int sum = 0;

    Node* l_node = nullptr;
    Node* r_node = nullptr;

    
};

class Node_Navigate
{
public:
    void traverse_from_node(Node* node, int indent = 0);
};

