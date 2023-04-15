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

int main(){
    Node* Treant = createNode(2);
    int arr[7] = {1,4,6,7,77,8,99};
    for (int i=0; i < 7; i++){
        Set_Node(Treant, arr[i]);
    }
    Get_Tree(Treant);
    cout << endl;
    cout << Depth_Tree(Treant) << endl;
    Node* Found = Find_ch1(Treant,8);
    cout << Found->UZEL << " " << Found->left << " " << Found->right << endl;
}