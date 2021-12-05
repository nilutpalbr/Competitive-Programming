#include <iostream>
#include "BinaryTreeNode.cpp"
#include <queue>
using namespace std;

BinaryTreeNode<int>* TakeInputLevelWise(){
 int rootData;
 cout<<"Enter rootData "<<endl;
 cin>> rootData;
 if(rootData==-1){
     return NULL;
 }
 BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
 queue<BinaryTreeNode<int>*> pendingNodes;
 pendingNodes.push(root);
 while(!pendingNodes.empty()){
     BinaryTreeNode<int>* front= pendingNodes.front();
    pendingNodes.pop();
    int leftNode;
    cout<<"Enter left child of "<<front->data<<endl;
    cin>>leftNode;
    if(leftNode!=-1){
          BinaryTreeNode<int>*leftchild=new BinaryTreeNode<int>(leftNode);
          front->left=leftchild;
          pendingNodes.push(leftchild);
    }
     cout<<"Enter right child of "<<front->data<<endl;
     int rightNodeData;
    cin>>rightNodeData;
    if(leftNode!=-1){
          BinaryTreeNode<int>*rightchild=new BinaryTreeNode<int>(rightNodeData);
          front->right=rightchild;
          pendingNodes.push(rightchild);
    }
 }
 return root;
}

BinaryTreeNode<int>* TakeInput(){
 int rootData;
 cout<<"Enter Data ";
 cin>>rootData;
 if(rootData==-1){
     return NULL;
 }
 BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
 BinaryTreeNode<int>* node1= TakeInput();
 BinaryTreeNode<int>* node2= TakeInput();
 root->left=node1;
 root->right=node2;
 return root;
}  

void printLevelWise(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;}
    queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(!pendingNodes.empty()){
      cout<<pendingNodes.front()->data<<":";
      if(pendingNodes.front()->left !=NULL){
          cout<<"Left "<<pendingNodes.front()->left->data<<" ";
           pendingNodes.push(pendingNodes.front()->left);
      }
      if(pendingNodes.front()->right!=NULL){
          cout<<"right "<<pendingNodes.front()->right->data<<" ";
           pendingNodes.push(pendingNodes.front()->right);
      }
      pendingNodes.pop();
      cout<<endl;
  }
}
void PrintBinaryTree(BinaryTreeNode<int> * root){
  if(root==NULL){
      return;
  }
  cout<<root->data<<":";
  if(root->left !=NULL){
      cout<<"left "<<root->left->data<<" ";
  }
  if(root->right !=NULL){
      cout<<"right "<<root->right->data<<" ";
  }
   cout<<endl;
   PrintBinaryTree(root->left);
   PrintBinaryTree(root->right);
}
//count node in a Binary Tree
int countNode(BinaryTreeNode<int>* root){
    if(root->left==NULL){
     return 1;
    }
    if(root->right==NULL){
        return 1;
    }
    int left=countNode(root->left);
    int right=countNode(root->right);
   return 1+left+right;
}
//isNodePresent
bool isNodePresent(BinaryTreeNode<int>*root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
  return isNodePresent(root->left,x)||isNodePresent(root->right,x);
}
//height of a binary tree
  int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return max(leftheight,rightheight)+1;
  }
  //mirror tree
  BinaryTreeNode<int>* mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root==NULL) {
        return NULL;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int>* temp;
    temp= root->left;
    root->left=root->right;
    root->right=temp;

    return root;
}
//pre order binary tree
void preOrder(BinaryTreeNode<int> *root) {
	if(root==NULL){
        return ;
    }
    cout<< root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return ;
    }
     postOrder(root->left);
     postOrder(root->right);
     cout<<root->data<<" ";

}
void leftView(BinaryTreeNode<int>* root){
    cout<<root->data<<" ";
    if(root->left==NULL){
        return;
    }
    leftView(root->left);
}

int main(){
    // 1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 10 11 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

 BinaryTreeNode<int>* root=TakeInputLevelWise();
 //mirrorBinaryTree(root);
 //preOrder(root);
 //cout<<endl;
 //postOrder(root);
 printf("The tree is : \n");
 PrintBinaryTree(root);
 //leftView(root);
 //cout<<countNode(root)<<endl;
 //int x;
 //cin>>x;
 //cout<< isNodePresent(root,x)<<endl;
 //cout<<height(root)<<endl;
}
