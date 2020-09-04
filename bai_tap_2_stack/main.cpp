#include <iostream>
#include<stack>
#include<queue>
using namespace std;
void SetTrainA(stack<int> & A,int n)
{
	for(int i=n;i>=1;i--)
	{
		A.push(i);
	}
}
void ShowStack(stack<int> A)
{
	while(!A.empty())
	{
		cout<<" "<<A.top();
		A.pop();
	}
	cout<<endl;
}

int main()
{
    stack<int> A;
    stack<int> B;
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
	cout<<"chuoi c: ";
	for(int i=0;i<n;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;
    SetTrainA(A,n);
    ShowStack(A);
    //dk dừng B ko còn phần tử đẩy qua --> YES
    // A empty và B ko empty
    // thực hienj là B có và B ko rỗng thì B-> C
    //            nếu ko thì nếu A rỗng  thì A , A có thì A-> C end :ko có thì A->B tiếp tục đến khi có rỗng là NO luôn
    for(int i=0;i<n;)
		{
			cout<<"lan lap thu: "<<i<<endl;
			if(!B.empty())// nếu B có và B ko rỗng thì B->C chuyển qua so phần tử tiếp theo
			{
				if(c[i]==B.top())
				{
				cout<<"B->C"<<endl;
				C.push(B.top());
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
				return 0;}
	NO:
					cout<<"NO";
					return 0;
}
