#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdlib>
using namespace std;
struct node
{
	char Ten[40];
	char Lop[3];
	int SDT;
	int DTB;
	struct node* Next;
};
typedef struct node* NODE;
struct List{
NODE pHead;
NODE pTail;
};
NODE CreateNewNode(char ten[], char lop[], int SDT, int DTB )
{
	NODE nodeNew= new struct node;
	strcpy(nodeNew->Ten,ten);
	strcpy(nodeNew->Lop,lop);
	nodeNew->DTB=DTB;
	nodeNew->SDT=SDT;
	nodeNew->Next=NULL;
	return nodeNew;
}
void AddToTheFirst(struct List &l,NODE P)
{
	if(l.pHead==NULL)
		{
			l.pHead=l.pTail=P;
			l.pHead->Next=NULL;
		}
	else
		{
			P->Next=l.pHead;
			l.pHead=P;
		}
}
void AddtoTheLast(struct List &l,NODE P)
{
	if(l.pHead==NULL)
		{
			l.pHead=l.pTail=P;
			l.pHead->Next=NULL;
		}

	else{
		l.pTail->Next=P;
		l.pTail=P;
		l.pTail->Next=NULL;
	}
}
void AddAftertheName(char ten[], NODE P,struct List &l)
{
	if(l.pHead==NULL)
		return;
	else
	{
		NODE k= l.pHead;
		for(k; k!= NULL; k=k->Next)
		{
			if(strcmp(k->Ten,ten)==0)
			{
				NODE temp= k->Next;
				P->Next=temp;
				k->Next=P;
				return;
			}
		}
	}
	cout<<"KHONG THAY TEN SINH VIEN "<<endl;
	return;
}
void AddBeforetheName(char ten[], NODE P,struct List &l)
{
	if(l.pHead==NULL)
		return;
	else
	{
		NODE k= l.pHead;
		if(strcmp(k->Ten,ten)==0){
			AddToTheFirst(l,P);
			return;
		}
		for(k; k!= NULL; k=k->Next)
		{
			NODE temp=k->Next;
			if(strcmp(temp->Ten,ten)==0)
			{
				P->Next=temp;
				k->Next=P;
				return;
			}
		}

	}
	cout<<"KHONG THAY TEN SINH VIEN "<<endl;
	return;
}
int GetTheLengtList(struct List l)
{
	int dem=0;
	NODE k=l.pHead;
	while(k!=NULL)
	{
		dem++;
		k=k->Next;
	}
	return dem;
}
void AddBeforetheIndex(int index, NODE P,struct List &l)
{
	int dem=0;
	int length=GetTheLengtList(l);
	if(index==length+1)
		AddtoTheLast(l,P);
	if(l.pHead==NULL)
		return;
	else
	{
		NODE k= l.pHead;
		if(index==1){
			AddToTheFirst(l,P);
			return;
		}
		for(k; k!= NULL; k=k->Next)
		{
			dem++;
			if(dem==index-1)
			{
				P->Next=k->Next;
				k->Next=P;
				return;
			}
		}

	}
}
void AddAftertheIndex(int index, NODE P,struct List &l)
{
	int dem=0;
	int length=GetTheLengtList(l);
	if(index==length+1)
		AddtoTheLast(l,P);
	if(l.pHead==NULL)
		return;
	else
	{
		NODE k= l.pHead;
		for(k; k!= NULL; k=k->Next)
		{
			dem++;
			if(dem==index)
			{
				P->Next=k->Next;
				k->Next=P;
				return;
			}
		}

	}
}
void swapNODE(NODE a, NODE b)
{
	char ten[40];
	char lop[3];
	int sdt,dtb;
	strcpy(ten,b->Ten);
	strcpy(lop,b->Lop);
	sdt=b->SDT;
	dtb=b->DTB;
	strcpy(b->Ten,a->Ten);
	strcpy(b->Lop,a->Lop);
	b->SDT=a->SDT;
	b->DTB=a->DTB;

	strcpy(a->Ten,ten);
	strcpy(a->Lop,lop);
	a->SDT=sdt;
	a->DTB=dtb;
}
void SelectionSort(struct List &L)
{
	//sap xep tu be den lon
	NODE k=L.pHead;
	NODE m=new struct node;
	for(k;k!=NULL;k=k->Next)
	{
		for(m=k->Next;m!=NULL;m=m->Next)
		{
			if(m->DTB<k->DTB)
				swapNODE(m,k);
		}
	}
}
void ClearTheHead(struct List &l)
{
	if(l.pHead==NULL)
		return;

	else
	{
		NODE temp=l.pHead->Next;
		delete l.pHead;
		l.pHead=temp;
	}
}
void ClearTheTail(struct List &l)
{
	if(l.pHead==NULL)
		return;
	if(l.pHead->Next==NULL)
		{
			ClearTheHead(l);
			return;
		}
	else
	{
		NODE k= l.pHead;
		for(k;k!=NULL;k=k->Next)
		{
			if(k->Next==l.pTail)
			{
				delete l.pTail;
				k->Next=NULL;
				l.pTail=k;
				return;
			}
		}

	}
}
void ClearBeforeTheName(char name[],struct List &l)
{
	if(l.pHead==NULL)
		return;
	if(strcmp(name,l.pHead->Ten)==0)
		return;
	if(strcmp(name,(l.pHead->Next)->Ten)==0)
	{
		ClearTheHead(l);
		return;
	}
	else
	{
		NODE k= new struct node;
		for(k=l.pHead;k!=NULL;k=k->Next)
		{
			NODE temp= (k->Next)->Next;
			if(strcmp(name,temp->Ten)==0)
			{
				delete k->Next;
				k->Next=temp;
				return;
			}
		}
	}
}
void ClearAfterTheName(char name[],struct List &l)
{
	if(l.pHead==NULL)
		return;

	else
	{
		NODE k= new struct node;
		for(k=l.pHead;k!=NULL;k=k->Next)
		{
			NODE temp= k->Next;
			if(strcmp(name,k->Ten)==0&& k->Next!=NULL)
			{
				if(temp==l.pTail)
				{
					ClearTheTail(l);
				}
				else
				{
				k->Next=temp->Next;
				delete temp;
				return;
				}

			}
		}
	}
}
void NhapThongTin(NODE P)
{
cin.ignore(100,'\n');
  char name[50];\
  char lop[10];
  int sdt;
  int dtb;
  cout<<"\tnhap vao ten: ";cin.getline(name,50);
  cout<<"\tnhap vao lop: ";cin.getline(lop,10);
  cout<<"\tnhap vao so dien thoai: ";cin>>sdt;
  cout<<"\tnhap vao diem trung binh: ";cin>>dtb;
  cout<<endl;
  strcpy(P->Ten,name);
  strcpy(P->Lop,lop);
  P->DTB=dtb;
  P->SDT=sdt;
}
void PrintList(struct List l)
{
	int dem=0;
	NODE k= new struct node;
	for(k=l.pHead;k!=NULL;k=k->Next)
	{
		cout<<"\MSSV:"<<dem<<endl;
		dem++;
		cout<<"\Ten Sinh Vien: ";
		int index=0;
		while(k->Ten[index]!='\0')
		{
			cout<<k->Ten[index];
			index++;
		}
		cout<<endl;
		index=0;
		cout<<"\Sinh Vien hoc lop: ";
		while(k->Lop[index]!='\0')
		{
			cout<<k->Lop[index];
			index++;
		}
		cout<<endl;
		cout<<"\So dien thoai: "<<k->SDT<<endl;
		cout<<"\Diem trung binh: "<<k->DTB<<endl;
		cout<<endl;
	}
}
void PrintInfor(NODE P)
{
	cout<<"THONG TIN: "<<endl;
	cout<<"Ten: "<<P->Ten<<endl;
	cout<<"Lop: "<<P->Lop<<endl;
	cout<<"dtb: "<<P->DTB<<endl;
	cout<<"sdt: "<<P->SDT<<endl;
}
int main()
{
	NODE a= new struct node();
	struct List L;
	L.pHead=NULL;
	L.pTail=NULL;
	char ten[10]="viet hung";
	char lop[3]="12";
	int sdt=964029461;
	int dtb=10;
	a=CreateNewNode(ten,lop,sdt,dtb);
	AddToTheFirst(L,a);
	NODE b= new struct node;
	b=CreateNewNode("khoa","mt",90,9);
	AddtoTheLast(L,b);
	PrintList(L);
	int n;
	NODE pt1= new struct node;
	NODE pt2= new struct node;
	pt1=CreateNewNode("Nguyen Van A","A",123,9);
	pt2=CreateNewNode("Nguyen van B","B",321,6);
	PrintInfor(pt1);
	PrintInfor(pt2);
	swapNODE(pt1,pt2);
	cout<<"sau swap: "<<endl;
	PrintInfor(pt1);
	PrintInfor(pt2);
	while(1)
	{	system("cls");
		cout<<"1. Them phan tu vao dau danh sach"<<endl;
		cout<<"2. Them phan tu vao cuoi danh sach"<<endl;
		cout<<"3. Them phan tu sau ten: "<<endl;
		cout<<"4. Them phan tu truoc ten: "<<endl;
		cout<<"5. Them phan tu o truoc vi tri n: "<<endl;
		cout<<"6. Them phan tu o sau vi tri n: "<<endl;
		cout<<"7. Xoa phan tu dau danh sach"<<endl;
		cout<<"8. Xoa phan tu cuoi danh sach"<<endl;
		cout<<"9. Xoa phan tu sau ten:"<<endl;
		cout<<"10. Xoa phan tu truoc ten: "<<endl;
		cout<<"11. Xoa phan tu vi tri n"<<endl;
		cout<<"12. Do dai chuoi: "<<endl;
		cout<<"13. Sap xep danh sach theo diem trung binh"<<endl;
		again: cout<<"nhap vao su lua chon cua ban: ";
	    cin>>n;
	    if(n<0 ||n>13)
		{
			goto again;
		}
		switch(n)
	{
		cout<< "danh sach hien tai: "<<endl;
		PrintList(L);
		case 1:{

				NODE P= new struct node;
				NhapThongTin(P);
				AddToTheFirst(L,P);
				cout<<"danh sach sau khi in them vao dau danh sach: "<<endl;
				PrintList(L);
				getch();
				break;
		       }
		case 2:{
				NODE P= new struct node;
				NhapThongTin(P);
				AddtoTheLast(L,P);
				cout<<"danh sach sau khi in them vao cuoi danh sach: "<<endl;
				PrintList(L);
				getch();
				break;
		       }
		case 3: {
				cout<<"them vao sau chuoi co ten la"<<endl;
				char name[50];
				cin.ignore(100,'\n');
				cin.getline(name,50);
				cout<<endl;
				NODE P=new struct node;
				NhapThongTin(P);
				AddAftertheName(name,P,L);
				PrintList(L);
				getch();
				break;
				}
		case 4: {
				cout<<"them vao truoc chuoi co ten la"<<endl;
				char name[50];
				cin.ignore(100,'\n');
				cin.getline(name,50);
				cout<<endl;
				NODE P=new struct node;
				NhapThongTin(P);
				AddBeforetheName(name,P,L);
				PrintList(L);
				break;
				}
		case 5: {
				int index_add;
				cout<<"Them vao trc vi tri :";cin>>index_add;
				NODE P= new struct node;
				NhapThongTin(P);
				AddBeforetheIndex(index_add,P,L);
				PrintList(L);
				getch();
				break;
				}
		case 6: {
				int index_add;
				cout<<"Them vao sau vi tri :";cin>>index_add;
				NODE P= new struct node;
				NhapThongTin(P);
				AddBeforetheIndex(index_add,P,L);
				PrintList(L);
				getch();
				break;
				}
		case 7: {cout<<"Xoa Phan Tu Dau"<<endl;
				ClearTheHead(L);
				PrintList(L);
				getch();

				break;
				}
		case 8: {cout<<"Xoa Phan Tu Cuoi"<<endl;
				ClearTheTail(L);
				PrintList(L);
				break;
				}
		case 9: {cout<<"Xoa Phan Tu Sau Ten: ";
				char name[50];
				cin.ignore(100,'\n');
				cin.getline(name,50);
				ClearAfterTheName(name,L);
				PrintList(L);
				getch();
				break;
				}
		case 10: {cout<<"Xoa Phan Tu Truoc Ten: ";
				char name[50];
				cin.ignore(100,'\n');
				cin.getline(name,50);
				ClearBeforeTheName(name,L);
				PrintList(L);
				getch();
				break;
				}
		case 12:{
				cout<<"Do dai chuoi la: "<<GetTheLengtList(L)<<endl;
				getch();
				break;
		}
		case 13:{
				cout<<"danh sach sau xap xep: "<<endl;
				SelectionSort(L);
				PrintList(L);
				getch();
				break;
		}

	}
	n=0;
	}

    return 0;
}
