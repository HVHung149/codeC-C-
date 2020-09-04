#include <iostream>

using namespace std;
struct node{
char value;
struct node* Left;
struct node* Right;
};
typedef struct node* NODE;
NODE CreatNewNode(char value,NODE L, NODE R)
{
	NODE A= new struct node;
	A->value=value;
	A->Left=L;
	A->Right=R;
	return A;
}
void PreOderTraversal(NODE P)
{
	if(P==NULL)return;
	else
	{
		cout<<P->value<<" ";
		PreOderTraversal(P->Left);
		PreOderTraversal(P->Right);
	}
}
void InOderTraversal(NODE P)
{
	if(P==NULL)return;
	else
	{

		InOderTraversal(P->Left);
		cout<<P->value<<" ";
		InOderTraversal(P->Right);
	}
}
void PostOderTraversal(NODE P)
{
	if(P==NULL)return;
	else
	{
		PostOderTraversal(P->Left);
		PostOderTraversal(P->Right);
		cout<<P->value<<" ";

	}
}
int main()
{
    NODE A= new struct node;
    NODE B= new struct node;
    NODE C= new struct node;
    NODE D= new struct node;
    NODE E= new struct node;
    NODE F= new struct node;
    NODE G= new struct node;
    NODE H= new struct node;
    NODE I= new struct node;
    NODE J= new struct node;
    NODE K= new struct node;
    NODE L= new struct node;
    A=CreatNewNode('A',NULL,NULL);
    B=CreatNewNode('B',NULL,NULL);
    C=CreatNewNode('C',NULL,NULL);
    D=CreatNewNode('D',NULL,NULL);
    E=CreatNewNode('E',NULL,NULL);
    F=CreatNewNode('F',NULL,NULL);
    G=CreatNewNode('G',NULL,NULL);
    H=CreatNewNode('H',NULL,NULL);
    I=CreatNewNode('I',NULL,NULL);
    J=CreatNewNode('J',NULL,NULL);
    K=CreatNewNode('K',NULL,NULL);
    L=CreatNewNode('L',NULL,NULL);
    A->Left=B;A->Right=C;
    B->Left=D;B->Right=E;
    C->Left=F;C->Right=G;
    D->Left=H;D->Right=I;
    E->Left=NULL;E->Right=J;
    F->Left=K;F->Right=NULL;
    G->Left=NULL;G->Right=L;
    cout<<"Pre: ";
	PreOderTraversal(A);
	cout<<endl;
	cout<<"In: ";
	InOderTraversal(A);
	cout<<endl;
	cout<<"Pos: ";
	PostOderTraversal(A);

}
