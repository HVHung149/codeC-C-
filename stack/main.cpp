#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void ShowStack(stack<int> S)
{
	while(!S.empty())
	{
		cout<<" "<<S.top();
		S.pop();
	}
	cout<<endl;
}
void ConvertToBinary(int dec, stack<int> &Binary)
{
	while(dec!=0)
	{
		Binary.push(dec%2);
	    dec=dec/2;
	}
}
void ConvertToOcta(int dec, stack<int> &Octa)
{
	while(dec!=0)
	{
		Octa.push(dec%8);
	    dec=dec/8;
	}
}
void ConvertToHexa(int dec, stack<int> &
				Hexa)
{
	while(dec!=0)
	{
		Hexa.push(dec%16);
	    dec=dec/16;
	}
}
int main()
{
    stack<int> STACK;
	int dec;
	cout<<"nhap vao gia tri can chuyen doi: ";cin>>dec;
	stack<int> binary;
	stack<int> octa;
	stack<int> hexa;
	ConvertToBinary(dec,binary);
	ConvertToOcta(dec,octa);
	ConvertToHexa(dec,hexa);
	cout<<"binary: "; ShowStack(binary);
	cout<<"octa: ";ShowStack(octa);
	cout<<"hexa: ";ShowStack(hexa);
}
