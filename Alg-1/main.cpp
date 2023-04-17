#include <iostream>
using namespace std;

struct Node{
    int UZEL;
    Node* right;
    Node* left;
};

Node* createNode(int ch1){
    Node* newNode = new Node;
    newNode -> UZEL = ch1;
    newNode -> right = nullptr;
    newNode -> left = nullptr;
    return newNode;
}

void Set_Node(Node* Node1, int ch1){
    if(Node1->UZEL < ch1){
        if(Node1->right != nullptr){
            Set_Node(Node1->right,ch1);
        }
        else{
            Node1 -> right = createNode(ch1);
        }
    }
    else{
        if(Node1 -> left != nullptr){
            Set_Node(Node1->left,ch1);
        }
        else{
            Node1 -> left = createNode(ch1);
        }
    }
}

void Get_Tree(Node* imya){
    if(imya != nullptr){
        Get_Tree(imya->left);
        cout << imya->UZEL << " ";
        Get_Tree(imya -> right);
    }
}

int Depth_Tree(Node* TREE){
    if(TREE != NULL){
        int rightDepth = Depth_Tree(TREE->right);
        int leftDepth = Depth_Tree(TREE -> left);
//        if (leftDepth == rightDepth){
//            return leftDepth+1;
//        }
        return max(rightDepth,leftDepth)+1;

    }
    else{
        return 0;
    }
}

Node* Find_ch1(Node* TRE,int ch1){
    if(TRE == nullptr || ch1 == TRE->UZEL){
        return TRE;
    }
    if(ch1 > TRE->UZEL){
        return Find_ch1(TRE->right,ch1);
    }
    else{
        return Find_ch1(TRE->left,ch1);
    }
}

void DeleteNode(Node* TRE, int ch1) {
    Node *curr = TRE;
    Node *parent = NULL;
    while (curr != NULL && curr->UZEL != ch1) {
        parent = curr;
        if (curr->UZEL > ch1) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (curr = NULL) {
        return;
    }
    bool IsLeftChild = (parent != NULL && curr == parent->left);
    if (curr->left == nullptr && curr->right == nullptr) {
        if (parent == NULL) {
            TRE = NULL;
        } else if (IsLeftChild) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        delete curr;
    } else if (curr->left == nullptr || curr->right == nullptr) {
        Node *child = (curr->left != NULL) ? curr->left : curr->right;
        if (parent == NULL) {
            TRE = child;
        } else if (IsLeftChild) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete curr;
    } else {
        Node *successor = curr->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        int successorCh1 = successor->UZEL;
        DeleteNode(TRE, successorCh1);
        curr->UZEL = successorCh1;
    }
}

int main(){
    Node* Treant = createNode(2);
    int arr[7] = {1,4,6,7,77,8,99};
    for (int i=0; i < 7; i++){
        Set_Node(Treant, arr[i]);
    }
    cout << "Tree: ";

    Get_Tree(Treant);
    cout << endl;
    cout << Depth_Tree(Treant) << endl;
    Node* Found = Find_ch1(Treant,8);
    cout << Found->UZEL << " " << Found->left << " " << Found->right << endl;
}