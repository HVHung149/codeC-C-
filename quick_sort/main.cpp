#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#define N 500
using namespace std;
void QuickSort(int a[],int low, int high)
{
	//hai biến low và high là 2 biến đầu mảng và cuối mảng
	//chọn phần tử pivot là phần tử đầu mảng
	int pivot=a[low];
	//khởi tạo 2 biến chạy left=low+1 right=high
	int left=low;int right=high;
	//cout<<"Left: "<<left<<endl;
	//cout<<"Right: "<<right<<endl;
	while(left<right)// left cứ tiến về bên phải và right luôn tiến về bên trái để khi nào left> right
	{
		while(a[left]<=pivot||a[right]>pivot&& left<=high)// thực hiện vòng lặp cho đến khi nào tìm  được 2 giá trị a[left]>pivot và a[right]<=pivot
		{
			if(a[left]<=pivot)left++; // khi qua phần tử thỏa mãn <= thì left cứ tiếp tục tăng
			if(a[right]>pivot)right--;// tương tự khi qua phần tử thỏa mãn là > thì tiếp tục giảm right
		}
		//cout<<"tai left:"<<left<<" tai right: "<<right<<endl;
		if(left<right)//vì thực hiện trong vòng while đến khi nào thỏa điều kiện thì mới thoát nên có khả năng left> right nhưng mà chưa quay lại vòng whilenên phải check
	    swap(a[right],a[left]);
	}
	swap(a[right],a[low]);
	// sử lý đệ qui
    //for(int i=low;i<=high;i++)
	//cout<<*(a+i)<<",";
	//cout<<endl;
	if(low<right-1) QuickSort(a,low,right-1);
	if(right+1<high)QuickSort(a,right+1,high);

}
void print(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<",";
}
typedef int soNguyen;
int main()
{
	soNguyen m=3;
	cout<<m<<endl;
	int a[N];
	/* initialize random seed: */
  srand (time(0));

	for(int i=0;i<N;i++)
	{
		a[i]=rand();
	}
	print(a,N);
	cout<<endl;
	QuickSort(a,0,N-1);
	cout<<"Sau sap xep: "<<endl;
	print(a,N);

	//int m=rand()%10+1;
	//cout<<m;
    return 0;
}
