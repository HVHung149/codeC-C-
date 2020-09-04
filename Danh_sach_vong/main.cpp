#include <iostream>

using namespace std;
struct node{
int index;
int counter;
struct node* next;
};
typedef struct node* NODE;
struct List{
NODE pHead;
NODE pTail;
};
typedef struct List LIST;
void createList(LIST &l )
{
	l.pHead=NULL;
	l.pTail=NULL;
}
NODE CreateNewNODE(int index, int counter)
{
	NODE NewNode=new struct node;
	NewNode->counter=counter;
	NewNode->index=index;
	NewNode->next=NULL;
}
void AddToTheHead(LIST &l,NODE P)
{
	if(l.pHead==NULL)                      //nếu hiện tại chưa có phần tử nào thì add
												// vào dầu và cho head= tail cho tail trỏ đến head
	{
		l.pHead=l.pTail=P;
		l.pTail->next=l.pHead;
		return;
	}
	else
	{
		P->next=l.pHead;                 //node mới trở đến  head
		l.pHead=P;	                     //cập nhật node mới là head
		l.pTail->next=l.pHead;           //cho node cuối trở đến node head
	}
}
void CreatTheListN(LIST &l,int n)
{   int counter=0;
	for(int i=1;i<=n;i++)
	{
		//counter<3?counter++:counter=1;
		NODE P=CreateNewNODE(i,counter);
		AddToTheHead(l,P);
	}
}
int GetTheLenght(LIST l)
{
	int dem=0;
	NODE k= l.pHead;
	NODE temp=k;
	if(l.pHead==NULL)
		return dem;
	if(l.pHead->next==l.pHead)
		return 1;
	while(k->next!=temp)
	{
		dem++;
		k=k->next;
	}
	return dem+1;
}

void PrintInfor(NODE P)
{
	cout<<"vi tri: "<<P->index;
	cout<<" counter: "<<P->counter<<endl;
}
void PrintTheList(LIST l)
{
	NODE k= l.pHead;
	NODE temp=k;
	int dem=0;
	while(k->next!=temp)//in n-1 người
	{
		PrintInfor(k);
		k=k->next;
	}
	PrintInfor(k);//in người cuối cùng
}
void ClearP(LIST &l,int value)
{
	NODE k=l.pHead;                  //cho chạy từ đầu danh sách
	while(k->next!=l.pHead)          //chạy đến phần tử kế cuối dừng
	{
		NODE temp=new struct node;
		if((k->next)->counter==value)  //nếu giá trị counter của phần tử kế đó bằng value
		{                              //Thì xóa phần tử kế tiếp đó
			temp=k->next;
			k->next=temp->next;
			//delete temp;
			cout<<"*************"<<endl;
			PrintTheList(l);
			return;
		}
		k=k->next;
	}
	// k hien tai la ptail neu phead =3 thi xoa head
	NODE temp=new struct node;
	if((k->next)->counter==value)
		{
			temp=k->next;
			l.pHead=temp->next;
			k->next=l.pHead;
			//delete temp;
			cout<<"*************"<<endl;
			PrintTheList(l);
			return;
		}
}
NODE GetFinal(LIST &l)
{
		NODE k= l.pHead;
		int counter=0;
		while(GetTheLenght(l)>2)           // nếu lenght lớn hơn 2 thì mọi người trong vòng cứ tiếp tục đếm
		{
			counter<3?counter++:counter=1;
			k->counter=counter;           //cập nhật giá trị đếm của người thứ k
			if(k->counter==3)             //nếu giá trị đếm là 3 thì xóa người đó ra khỏi danh sách
			{
				ClearP(l,3);
			}
			k=k->next;                    //trỏ đến người kế tiếp
		}
		if(k->counter==1)return k;
		else return k->next;
}
int main()
{

	LIST L;
	createList(L);
	CreatTheListN(L,15);
	PrintTheList(L);
	cout<<"Do dai danh sach: ";
	cout<<GetTheLenght(L)<<endl;

	NODE k=GetFinal(L);
	cout<<"result"<<endl;
	PrintInfor(k);

	NODE m=CreateNewNODE(1,1);
	NODE n=m;
	cout<<m<<endl;
	cout<<n<<endl;


}
