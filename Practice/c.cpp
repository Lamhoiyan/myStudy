#include<iostream>
#include <queue>
using namespace std;

struct node{
    node* left;
    node* right;
    int d;
    node(int x):d(x),left(NULL),right(NULL){}
};

void build(node*& root, int x){
    if(root ==NULL){
        root = new node(x);
    }
    else{
        if(x<root->d) {
            build(root->left, x);
        }
        else{
            build(root->right, x);
        }
    }
}

queue<node*> qu;

void preOrder(node* root){
    if(root!=NULL){
        cout << root->d<<"  ";
    }
    if(root->left!=NULL){
        preOrder(root->left);
    }
    if(root->right!=NULL){
        preOrder(root->right);
    }
}

int main(){

    int a;
    node *root = NULL;
    while(cin>>a){
        build(root, a);
        if(cin.get()=='\n')
            break;
        
    }
    preOrder(root);
    // qu.push(root);
    // node *cur;
    // while(!qu.empty()){
    //     cur = qu.front();
    //     qu.pop();
    //     cout << cur->d << " ";
    //     if(cur->left!=NULL){
    //         qu.push(cur->left);
    //     }
    //     if(cur->right!=NULL){
    //         qu.push(cur->right);
    //     }
    // }

    system("pause");
    return 0;
}