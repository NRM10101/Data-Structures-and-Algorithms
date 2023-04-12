#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//to creat a node
struct Node{
    Node *left;
    int data;
    Node *right;
};
Node* GetNewNode(int data){
    Node* node=new Node();
    node->data=data;
    node->right=NULL;
    node->left=NULL;
    return node;

}
//insert a data
Node* insert(Node* root,int data){
    Node *newNode= GetNewNode(data);
    if(root==NULL) {
        root = newNode;
    }else if(root->data > data){
        root->left=insert(root->left,data);
    }else if(data > (root->data)){
        root->right=insert(root->right,data);
    }
    return root;
}
//search
bool search(Node* root,int data){
    if(root==NULL){
        return false;
    }else if(root->data==data){
        return true;
    }else{
        if(root->data <data){
            return search(root->right,data);
        }else{
            return search(root->left,data);
        }
        //return search(root->left,data) || search(root->right,data);
    }
}
//Find minimum in the tree
Node* FindMin(Node* root){
    if(root==NULL){
        return root;
    }else{
        Node* min=GetNewNode(root->data);
        if(root->left==NULL){
            return min;
        }else{
            min=FindMin(root->left);
            return min;
        }
    }
}
//Find maximum in the tree
Node* FindMax(Node* root){
    if(root==NULL){
        return root;
    }else{
        Node* max= GetNewNode(root->data);
        if(root->right==NULL){
            return max;
        }else{
            max= FindMax(root->right);
            return max;
        }
    }
}
//delete a given value from the tree
Node* remove(Node* root,int data){
    if(root==NULL){return root;}
    else if(root->data >data){
        root->left= remove(root->left,data);
        return root;
    }else if(root->data <data){
        root->right=remove(root->right,data);
        return root;
    }else{  //root->data==data
        //case 01 : one child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
            return root;
        }
        //case 02 : one child
        else if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            root=temp;
            return  root;
        }else if(root->right==NULL){
            Node *temp=root->left;
            delete root;
            root=temp;
            return root;
        }
        //case 03 : two child
        else{
            //method 01:consider right side of the roof(then use minimum value of root->right)
            Node* temp=FindMin(root->right);
            root->data=temp->data;
            root->right= remove(root->right,temp->data);
            return root;

            //method 02:consider left side of the root(then use maximum value of root->left)
            //Node *temp= FindMax(root->left);
            //root->data=temp->data;
            //root->left= remove(root->left,temp->data);
            //return root
        }
    }
}
//tree traversing
void preOrder(Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
int main() {
    Node* binaryTree=NULL;
    binaryTree= insert(binaryTree,10);
    binaryTree= insert(binaryTree,20);
    binaryTree= insert(binaryTree,15);
    binaryTree= insert(binaryTree,65);
    binaryTree= insert(binaryTree,9);

    preOrder(binaryTree);cout<<endl;
    inOrder(binaryTree);
    binaryTree= remove(binaryTree,20);cout<<endl;
    //cout<<binaryTree<<endl;
    inOrder(binaryTree);cout<<endl;
    postOrder(binaryTree);cout<<endl;
    cout<<search(binaryTree,15);
    return 0;
}
