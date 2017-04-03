#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	
	char d;
	struct Node* right;
	struct Node* left;
	
}Node;

Node* allocNode(char ch){
	Node *r=(Node*)malloc(sizeof(Node));
    r->d=ch;
    r->left=NULL;
    r->right=NULL;
    return r;
   
}
void printTree(Node *r){
	if(r==NULL)return;
	
	printf("%c",r->d);
	printTree(r->left);
	printTree(r->right);
}
int evaluateTree(Node *r){
	
	if(r->left==NULL&&r->right==NULL)
	{
		return(r->d-'0');
	}
	if(r->d=='+')
	{
	return(evaluateTree(r->right)+evaluateTree(r->left));
	}
	if(r->d=='-')
	{
		return(evaluateTree(r->right)-evaluateTree(r->left));
	}
	if(r->d=='*')
	{
		return(evaluateTree(r->right)*evaluateTree(r->left));
	}
	
}
int main()
{
   int e;
	
   Node *r=allocNode('*');
   
   r->left=allocNode('+');
   r->right=allocNode('-');
   
   r->left->left=allocNode('1');
   r->left->right=allocNode('2');
 
   r->left->left->left=NULL;
   r->left->left->right=NULL;
   
   r->left->right->left=NULL;
   r->left->right->right=NULL;
   
   r->right->right=allocNode('3');
   r->right->left=allocNode('4');
 
   r->right->right->right=NULL;
   r->right->right->left=NULL;

   r->right->left->right=NULL;
   r->right->left->left=NULL;
   
   e=evaluateTree(r);
   printf("%d",e);
   
   return 0;   	
}
