#include <iostream>
#include <queue>
#include<stack>
using namespace std;
void SetQueue(int n, queue<int> &B)
{
	for(int i=1;i<=n;i++)
		B.push(i);
}
void PrintQueue(queue<int>B)
{
	while(!B.empty())
	{
		cout<<B.front()<<" ";
		B.pop();
	}
	cout<<endl;
}
void SetTrainA(stack<int> & A,int n)
{
	for(int i=n;i>=1;i--)
	{
		A.push(i);
	}
}
void PrintStack(stack<int> A)
{
	while(!A.empty())
	{
		cout<<" "<<A.top();
		A.pop();
	}kl
	cout<<endl;
}
int main()
{
   queue<int> B;
   stack<int> A;
   stack<int> C;
    int n;
    cout<<"nhap so toa tau: ";
    cin>>n;
    int *c;
    c=new int[n];
    for(int i=0;i<n;i++)
	{
		cout<<"out"<<i+1<<":";
		cin>>c[i];
	}
	cout<<endl;
	SetTrainA(A,n);
	//dk dừng B ko còn phần tử đẩy qua --> YES
    // A empty và B ko empty
    // thực hienj là B front có và B  ko rỗng thì B-> C
    //            nếu ko thì nếu A rỗng  thì A , A có thì A-> C end :ko có thì A->B tiếp tục đến khi có rỗng là NO luôn
        for(int i=0;i<n;)
		{
			 cout<<"lan lap thu: "<<i<<endl;
			if(!B.empty())// nếu B có và B ko rỗng thì B->C chuyển qua so phần tử tiếp theo
			{
				if(c[i]==B.front())
				{
				cout<<"B->C"<<endl;
				C.push(B.front());
				B.pop();
				goto LAP;
				}
			}
			if(!A.empty())// nếu mà A không rỗng
			{
				while(!A.empty())
				{
					if(A.top()==c[i])// co thi A ->C rồi qua phần tử tiếp theo
					{
						cout<<"A->C"<<endl;
						C.push(A.top());
						A.pop();
						break;
					}
					else// ko thì A đẩy sang B
					{
						cout<<"A->B"<<endl;
						B.push(A.top());
						A.pop();
						if(A.empty())
						{
							goto NO;
						}
					}
				}
			}
			LAP:
		i++;
	}


		if(B.empty())
				{cout<<"YES";
				PrintStack(C);
				return 0;}
	NO:
					cout<<"NO";
					PrintStack(C);
					return 0;
}
