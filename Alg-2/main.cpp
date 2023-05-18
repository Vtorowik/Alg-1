#include <iostream>
using namespace std;

struct Node{
    int UZEL;
    Node* left;
    Node* right;
};

Node* CreateNode(int UZEL){
    Node* node = new Node();
    node -> UZEL = UZEL;
    node -> left = nullptr;
    node -> right = nullptr;
    return node;
}

Node* insert(Node* node, int UZEL){
    if(!node){
        return CreateNode(UZEL);
    }
    else{
        if(UZEL<= node->UZEL){
            node->left = insert(node->left, UZEL);
        }
        else{
            node->right = insert(node->right, UZEL);
        }
        return node;
    }
}

int height(Node* node){
    if(!node){
        return 0;
    }
    else{
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight){
            return (leftHeight+1);
        }
        return rightHeight+1;

    }
}

int BalanceFactor(Node* node){
    if (!node){
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return abs(leftHeight-rightHeight);
}

void PrintBalanceFactor(Node* node){
    if (node){
        PrintBalanceFactor(node->left);
        cout << "Balance factor for node " << node->UZEL << " is " << BalanceFactor(node) << endl;
        PrintBalanceFactor(node->right);
    }
}

int main() {
    Node *Treant = CreateNode(2);
    int arr[7] = {1, 4, 6, 7, 77, 8, 99};
    for (int i = 0; i < 7; i++) {
        insert(Treant, arr[i]);
    }
    PrintBalanceFactor(Treant);
    return 0;
}