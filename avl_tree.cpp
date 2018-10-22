#include <iostream>
#include <stdlib.h>

using namespace std;


// /* This is an AVL Binary Tree;
//     Binary Tree is the tree in which each node has 0,1 or 2 children and for each node, left child's
//     value is always less than the parent and right child's value is always greater than the parent's.
//     AVL means that for each node, its left-subtree's height minus its right-subtrees height is 0,-1 or 1;

//     Time Complexity:
//     Search		O(log n)
//     Insert		O(log n)
//     Delete		O(log n)
// */

// struct Node {
//     struct Node* right;
//     struct Node* left;
//     int value;
// };


// struct Node *rightRotate(struct Node *y) 
// { 
//     struct Node *x = y->left; 
//     struct Node *T2 = x->right; 
  
//     // Perform rotation 
//     x->right = y; 
//     y->left = T2; 
  
//     // Update heights 
//     y->height = max(height(y->left), height(y->right))+1; 
//     x->height = max(height(x->left), height(x->right))+1; 
  
//     // Return new root 
//     return x; 
// } 
  
// // A utility function to left rotate subtree rooted with x 
// // See the diagram given above. 
// struct Node *leftRotate(struct Node *x) 
// { 
//     struct Node *y = x->right; 
//     struct Node *T2 = y->left; 
  
//     // Perform rotation 
//     y->left = x; 
//     x->right = T2; 
  
//     //  Update heights 
//     x->height = max(height(x->left), height(x->right))+1; 
//     y->height = max(height(y->left), height(y->right))+1; 
  
//     // Return new root 
//     return y; 
// } 
  
// // Get Balance factor of node N 
// int getBalance(struct Node *N) 
// { 
//     if (N == NULL) 
//         return 0; 
//     return height(N->left) - height(N->right); 
// } 
  
// // Recursive function to insert a key in the subtree rooted 
// // with node and returns the new root of the subtree. 
// struct Node* insert(struct Node* node, int key) 
// { 
//     /* 1.  Perform the normal BST insertion */
//     if (node == NULL) 
//         return(newNode(key)); 
  
//     if (key < node->key) 
//         node->left  = insert(node->left, key); 
//     else if (key > node->key) 
//         node->right = insert(node->right, key); 
//     else // Equal keys are not allowed in BST 
//         return node; 
  
//     /* 2. Update height of this ancestor node */
//     node->height = 1 + max(height(node->left), 
//                            height(node->right)); 
  
//     /* 3. Get the balance factor of this ancestor 
//           node to check whether this node became 
//           unbalanced */
//     int balance = getBalance(node); 
  
//     // If this node becomes unbalanced, then 
//     // there are 4 cases 
  
//     // Left Left Case 
//     if (balance > 1 && key < node->left->key) 
//         return rightRotate(node); 
  
//     // Right Right Case 
//     if (balance < -1 && key > node->right->key) 
//         return leftRotate(node); 
  
//     // Left Right Case 
//     if (balance > 1 && key > node->left->key) 
//     { 
//         node->left =  leftRotate(node->left); 
//         return rightRotate(node); 
//     } 
  
//     // Right Left Case 
//     if (balance < -1 && key < node->right->key) 
//     { 
//         node->right = rightRotate(node->right); 
//         return leftRotate(node); 
//     } 
  
//     /* return the (unchanged) node pointer */
//     return node; 
// } 

int main(){
    // struct Node* root = NULL;
    // root = insert(root,50);
    // insert(root,60);
    // insert(root,40);
    // insert(root,30);
    // insert(root,70);
    // insert(root,80);
    // remove(root,50);
    // insert(root,90);
    // cout<<IsItAvlTree(root)<<endl;
    int k = 15;
    int index = k & (-k);
    cout<<index<<endl;
}