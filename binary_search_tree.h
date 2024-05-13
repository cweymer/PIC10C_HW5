#ifndef binary_search_tree_h
#define binary_search_tree_h

#include <string>
#include <stack>
#include <queue>
#include <iomanip>

// class Iterator;
// class Node;

template<typename T = int>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
        void print(Node* parent, int indent, char symbol) const;
    };

    Node* root;

    void insert(Node*& node, const T& val) {
        if (!node)
            node = new Node(val);
        else if (val < node->data)
            insert(node->left, val);
        else if (val > node->data)
            insert(node->right, val);
    }

    void print(Node* node) {
        if (node) {
            print(node->left);
            std::cout << node->data << " ";
            print(node->right);
        }
    }

    Node* copyTree(const Node* otherNode) {
        if (!otherNode)
            return nullptr;
        Node* newNode = new Node(otherNode->data);
        newNode->left = copyTree(otherNode->left);
        newNode->right = copyTree(otherNode->right);
        return newNode;
    }

    void destroyTree(Node*& node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
            node = nullptr;
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        destroyTree(root);
    }

    BinarySearchTree(const BinarySearchTree& other) : root(nullptr) {
        root = copyTree(other.root);
    }

    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this != &other) {
            destroyTree(root);
            root = copyTree(other.root);
        }
        return *this;
    }

    void insert(const T& val) {
        insert(root, val);
    }

    void print() {
        print(root, 0, ' ');
        std::cout << std::endl;
    }
    void print(Node* parent, int indent, char symbol) const
    {
    if (parent == nullptr) { return; }
    print(parent->right, indent + 3, '/');
    // Print right subtree with increased indentation
    std::cout << std::setw(indent) << symbol << parent->data << std::endl;
    // Print current node with indentation
    print(parent->left, indent + 3, '\\');
    // Print left subtree with increased indentation
    }
};

#endif /* binary_search_tree_h */
