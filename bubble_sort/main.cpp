#include <iostream>
#include<vector>
using namespace std;
// thuật toán bubble sort
int main()
{
	vector<int> v={6,2,7,1,3};
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
		cout<< *it;
	cout<<endl;
	for(int i=v.size()-1;i>=1;i--)
	{
		for(int j=0;j<=i-1;j++)
		{
			if(v.at(j)>v.at(j+1))
				swap(v.at(j),v.at(j+1));
		}
	}
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
		cout<<*it;
	cout<<endl;
	for (auto& it : v) {
    cout << it ;
	}
            return 0;
}
