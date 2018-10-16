#include <iostream>

using namespace std;


/* This is an ordinary Binary Tree without any optimization.
    Binary Tree is the tree in which each node has 0,1 or 2 children and for each node, left child's
    value is always less than the parent and right child's value is always greater than the parent's.

    Time Complexity:
    Search		O(log n)	O(n)
    Insert		O(log n)	O(n)
    Delete		O(log n)	O(n)
    Space Complexity:
                O(n)	O(n)
*/

struct Node {
    struct Node* right;
    struct Node* left;
    int value;
};


struct Node* findMinimumInRight(struct Node* root){
    struct Node* current = root; 
    while (current->left != NULL) 
        current = current->left; 
    
    return current; 
}
struct Node* remove(struct Node* root, int value){
    if(root == NULL){
        return NULL;
    }else if(value > root->value){
        root->right = remove(root->right,value);
    }else if(value < root->value){
        root->left = remove(root->left,value);
    }else{
        if(root->right == NULL && root->left == NULL) return NULL;
        else if(root->left == NULL){
            struct Node* node = root->right;
            return node;
        }else if(root->right == NULL){
            struct Node* node = root->left;
            return node;
        }else{
            struct Node* inorder = findMinimumInRight(root->right);
            int value = inorder->value;
            root->value = value;
            root->right = remove(root->right, value); 
        }
    }
    return root;
}
struct Node* insert(struct Node* root, int value){
    if(root == NULL){
        struct Node* NewNode = (struct Node*)malloc(sizeof(Node));
        NewNode->right = NULL;
        NewNode->left = NULL;
        NewNode->value = value;
        return NewNode;
    }else if(value > root->value){
        root->right = insert(root->right, value);
    } else {
        root->left = insert(root->left, value);
    }
    return root;
}

int countNodes(struct Node* root){
    if(root == NULL){
        return 0;
    }
    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return left+right+1;
}

int countLeafs(struct Node* root){
    if(root ==NULL){
        return 0;
    }else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int left = countLeafs(root->left);
    int right = countLeafs(root->right);
    return left+right;
}


int height(struct Node* root){
    if(root == NULL){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;
}
void printTree(struct Node* root){
    if(root != NULL){
        printTree(root->left);
        cout<<root->value<<endl;
        printTree(root->right);
    }
}

 


int main(){
    struct Node* root = NULL;
    root = insert(root,50);
    insert(root,60);
    insert(root,40);
    insert(root,30);
    insert(root,70);
    
    remove(root,50);
    printTree(root);
}