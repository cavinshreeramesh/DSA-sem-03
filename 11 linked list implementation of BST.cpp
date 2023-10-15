#include <iostream>

using namespace std;

typedef struct node{
    node* parent;
    int key;
    node* left;
    node* right;
} node;

node* head=(node*)malloc(sizeof(node));

void insertion(int key_val){
    //creating new leaf
    node* new_leaf=(node*)malloc(sizeof(node));
    
    new_leaf->key=key_val;
    new_leaf->left=NULL;
    new_leaf->right=NULL;
    
    //if root is empty, set root to leaf with with key=key val
    if(head==NULL){  
        new_leaf->parent=NULL;
        head=new_leaf;
    //if root is not empty
    }else{
        node *temp2,*temp1=head;
        int flag; //1->right, 0->left
        temp1=head;
        
        //to find the first empty location
        while(temp1!=NULL){
            
            //if new value is greater than current node go right
            if(temp1->key<key_val){
                temp2=temp1;   //parent of possible location
                temp1=temp1->right;
                flag=1;
            }
            //else go left
            else{
                temp2=temp1;
                temp1=temp1->left;
                flag=0;
            }
        }
        
        new_leaf->parent=temp2;
        //if we are inserting to right of parent node
        if(flag==1){
            temp2->right=new_leaf;
        }
        //inserting to left
        else{
            temp2->left=new_leaf;
        }
    }
}

void deletion(int del_key){
    if(head==NULL){
        cout<<"empty tree"<<endl;
    }else{
        node *ptr=head;
        while(ptr->key!=del_key){
            if(ptr->key>del_key){
                //if key to be deleted is less than current node's key, go left
                ptr=ptr->left;
            }else{
                //else go right
                ptr=ptr->right;
            }
            //if ptr is NULL, the del_key doesnt exist in tree
            if(ptr==NULL){
                cout<<"key doesn't exist in tree"<<endl;
                return;
            }
        }
        //node getting deleted has no subtrees
        if(ptr->left==NULL && ptr->right==NULL){
            //if node getting deleted is the head
            if(ptr->parent==NULL){
                head=NULL;
            }else{
                //if node getting deleted is a left key
                if(ptr->parent->key>ptr->key){
                    ptr->parent->left=NULL;
                //if node getting deleted is a right key
                }else{
                    ptr->parent->right=NULL;
                }
            }
            free(ptr);
        //node getting deleted only has a left subtree
        }else if(ptr->right==NULL){
            //if node getting deleted is the head
            if(ptr->parent==NULL){
                ptr->left->parent=NULL;
                head=ptr->left;
            }else{
                node *replacement=ptr->left;
                //if node getting deleted is a left key
                if(ptr->parent->key>ptr->key){
                    replacement->parent=ptr->parent;
                    ptr->parent->left=replacement;
                //if node getting deleted is a right key
                }else{
                    replacement->parent=ptr->parent;
                    ptr->parent->right=replacement;
                }
            }
            free(ptr);
        //node getting deleted only has a right subtree
        }else if(ptr->left==NULL){
            //if node getting deleted is the head
            if(ptr->parent==NULL){
                head=ptr->right;
                head->parent=NULL;
            }else{
                node *replacement=ptr->right;
                //if node getting deleted is a left key
                if(ptr->parent->key>ptr->key){
                    replacement->parent=ptr->parent;
                    ptr->parent->left=replacement;
                //if node getting deleted is a right key
                }else{
                    replacement->parent=ptr->parent;
                    ptr->parent->right=replacement;
                }
            }
            free(ptr);
        //node getting deleted has both right and left subtrees
        //it must be replaced by its inorder successor
        }else{
            node *replacement=ptr->right;
            //finding inorder successor
            while(replacement->left!=NULL){
                replacement=replacement->left;
            }
            //replacing the node
            replacement->parent=ptr->parent;
            replacement->left=ptr->left;
            //if node getting deleted is a left key
            if(ptr->parent->key>ptr->key){
                ptr->parent->left=replacement;
            //if node getting deleted is a right key
            }else{
                ptr->parent->right=replacement;
            }
            free(ptr);
        }
    }
}

// in order traversal
void inorder(node* root){
    
    if(root==NULL){
        return;
    }
    else{
        //print left child first
        inorder(root->left);
        
        //print root
        if(root->key != 0)
        cout << root->key << " ";

        //print right child
        inorder(root->right);
    }
}

// pre order traversal
void preorder(node* root){
    
    if(root==NULL){
        return;
    }
    else{
        //print root first
        if(root->key != 0)
        cout << root->key << " ";
        
        //print left child 
        preorder(root->left);

        //print right child
        preorder(root->right);
    }
}

// post order traversal
void postorder(node* root){
    
    if(root==NULL){
        return;
    }
    else{
        //print left child first
        postorder(root->left);
        
        //print right child
        postorder(root->right);
        
        //print root
        if(root->key != 0)
        cout << root->key << " ";
    }
}

int main()
{
    insertion(5);
    insertion(2);
    insertion(3);
    insertion(7);
    insertion(6);
    insertion(8);
    preorder(head);
    cout<<endl;
    postorder(head);
    //deletion(7);
    //inorder(head);
    return 0;
}
