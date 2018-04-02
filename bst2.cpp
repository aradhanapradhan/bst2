#include<iostream>
using namespace std;

 struct node
 {
        int data;
        node* left;
        node* right;
        node* parent;
 };

class BST
{
   public:
    node* root;
    //Function for inserting a node
    node* insert(int x, node* temp)
    {
        if(temp == NULL)     
        {
            temp = new node;
            temp->data = x;
            temp->left = temp->right = NULL;
        }

        else if(x < temp->data) 
        {
        	temp->left = insert(x, temp->left);
            temp->left->parent = temp;
        }

        else if(x > temp->data)   
        {
        	temp->right = insert(x, temp->right);
            temp->right->parent = temp;
        }

        return temp;
    }

    //Function for searching a node in the Binary Search Tree 
    node* search(int x, node* temp)
    {
      if(temp == NULL)
           return NULL;
      else if(x==temp->data)  
           return temp;     
      else if(x<temp->data)
           return search(x,temp->left);   
      else if(x>temp->data)
           return search(x,temp->right);  
    }
    node* parent(int x, node* temp)
    {
    	if(temp==NULL)
    		return NULL;
    		
    	else if(x==temp->data){         
    		if(temp->parent==NULL){   
    			return temp;
    		}
    		else if(temp->parent!=NULL){  
    	                       return temp->parent;
    		}
    	}

            else if(x<temp->data)           
            return parent(x, temp->left);
            else if(x>temp->data)          
            return parent(x, temp->right);
    	}

    

    //Function for traversing the tree in inorder fashion and displaying the nodes
    void inorder(node* temp)
    {
        if(temp == NULL)
            return;
        inorder(temp->left);      
        cout << temp->data << " ";    
        inorder(temp->right);     

    }

    //Function for finding the minimum element
    node* min(node *temp){
    	if(temp==NULL){
    		return NULL;
    	}
    	else if(temp->left==NULL){       
    		return temp;
    	}
    	else if(temp->left!=NULL){
    		return min(temp->left);      
    	}
    }  

    

    //Function for deleting a node in Binary Search Tree
    node* deletion(int x, node* temp)
   {
     if(temp == NULL)
           return NULL;

     else if(x<temp->data)         //Finding the node in left subtree
           deletion(x,temp->left);

     else if(x>temp->data)         //Finding the node in right subtree
           deletion(x,temp->right);

   else if(x==temp->data)         
     {       

     	//Case-1: The node has no child
     	if(temp->left== NULL && temp->right == NULL){   
     		if(temp->parent->left==temp){         //If the node is in its parent's left
     			temp->parent->left=NULL;  
     		}

     		else if(temp->parent->right==temp){   //If the node is in its parent's right
     			temp->parent->right=NULL;
     		}

     		delete temp;  //Deleting the node
     		}

     	//Case-2: The node has 1 child	
     	else if(temp->left== NULL || temp->right == NULL){ 
     		if(temp->parent->left==temp){        //If the node is at its parent's left
     			if(temp->left!=NULL){     //If the node has left child
     			temp->parent->left=temp->left;  //Replacing the node's place by its child
     			temp->left->parent=temp->parent;
     			}

     			else if(temp->right!=NULL){    //If the node is at its parent's right
     			temp->parent->left=temp->right;   //Replacing the node's place by its child
     			temp->right->parent=temp->parent;
     			}
     		}

     		else if(temp->parent->right==temp){   //If the node is at its parent's right
     			if(temp->left!=NULL){
     				temp->parent->left=temp->left;
     				temp->left->parent=temp->parent;
     			}

     			else if(temp->right!=NULL){
     				temp->parent->right=temp->right;
     				temp->right->parent=temp->parent;
     			}
     		}
     		delete temp;   //Deleting the node
     	}

     	//Case-3: The node has 2 children
     	else if(temp->left!=NULL && temp->right!=NULL){
     		node* temp1=min(temp->right);    //Finding the smallest node in the node's right subtree
     		temp->data=temp1->data;   //Replacing the node's value with this min node's value

     		//If the min node has no child
     		if(temp1->left==NULL && temp1->right==NULL){
     			if(temp1->parent->left==temp1){
     			temp1->parent->left=NULL;
     		}
     		            else if(temp1->parent->right==temp1){
     			temp1->parent->right=NULL;
     		}
     		delete temp1;
     		}

     		//If the min node has 1 right child (It will have no left child as it is the smallest)
     		else if(temp1->right!=NULL){
     				temp1->parent->right=temp1->right;
     				temp1->right->parent=temp1->parent;
     		delete temp1;
     		}
     	}
     } 

     }


    BST()
    {
        root = NULL;
    }

     void insert(int x)
     {
        root = insert(x, root);
     }

     void display()
     {
        inorder(root);
        cout << endl;
    }

    node* search(int x)
    {   
       node *temp=search(x,root);
       return temp;
    }

    node* parent(int x){
    	 node*ti=parent(x,root);
    	 return ti;
    }

    void deletion(int x)
    {
      deletion(x,root);
    }
};

  

//Main function for the programme    

int main()

{

    BST t;  //Making BST variable type  

    t.insert(12);

    t.insert(8);

    t.insert(7);

    t.insert(6);

    t.insert(45);

    t.insert(50);

    t.display();

    node * temp =t.search(6);

    cout << temp -> data;

    cout<<endl;

    t.deletion(45);

    t.display();

    node* ti= t.parent(45);

    cout<<ti->data;

    cout<<endl;

}