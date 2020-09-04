#include <iostream>

using namespace std;
	int a[100][100];
	int b[100][100];
	int c[100][100];
	int SOHANG;
	int SOCOT;
void NhapMaTran(int a[][100])
{
	for(int i=0;i<SOHANG;i++)
	{
		for(int j=0;j<SOCOT;j++)
		{
			cout<<"phan tu hang: "<<i<<"cot: "<<j<<"la: ";cin>>a[i][j];
		}
	}
}
void bangnhau(int  x,int y)
{
	if(x==y)
		cout<<"haha";
}
void InMaTran(int a[][100])
{
	for(int i=0;i<SOHANG;i++)
	{
		for(int j=0;j<SOCOT;j++)
		{
			cout<<"["<<a[i][j]<<"] ";
		}
		cout<<endl;
	}
}
int max_with1(int a)
{
	int kq;
	return kq=a>-1?a:-1;
}
void Get_maxtrixL2(int a[][100],int b[][100])
{
	for(int i=0;i<SOHANG;i++)
	{
		for(int j=0;j<SOCOT;j++)
		{
			int temp=-1;
			for(int k=0;k<SOHANG;k++)
			{
				if(a[i][k]!=-1 && a[k][j]!=-1)
				{
					if(temp<a[i][k]+a[k][j])
					{
						temp=a[i][k]+a[k][j];
					}
				}
				else
				{
					if(temp==-1)
						temp=-1;
				}
			}
			b[i][j]=max_with1(temp);
		}
	}
}
void Get_maxtrixL3(int a[][100],int b[][100],int c[][100])
{
	for(int i=0;i<SOHANG;i++)
	{
		for(int j=0;j<SOCOT;j++)
		{
			int temp=-1;
			for(int k=0;k<SOHANG;k++)
			{
				if(a[i][k]!=-1 && b[k][j]!=-1)
				{
					if(temp<a[i][k]+b[k][j])
					{
						temp=a[i][k]+b[k][j];
					}
				}
				else
				{
					if(temp==-1)
						temp=-1;
				}
			}
			c[i][j]=max_with1(temp);
		}
	}
}
void get_L1(int a[][100], int b[][100],int c[][100])
{
	for(int i=0;i<SOHANG;i++)
	{
		for(int j=0;j<SOCOT;j++)
		{
			int temp=-1;
			for(int k=0;k<SOHANG;k++)
			{
				if(a[i][k]!=-1 && b[k][j]!=-1)
				{
					if(temp<a[i][k]+b[k][j])
					{
						temp=a[i][k]+b[k][j];
					}
				}
				else
				{
					if(temp==-1)
						temp=-1;
				}
			}
			c[i][j]=max_with1(temp);
		}
	}
}
float lon_nhat(int a[][100],int heso)
{
	float temp=-1;
	for(int i=0;i<SOHANG;i++)
	{
		if(a[i][i]!=-1)
			{
				if((float)a[i][i]/heso>temp)
					temp=(float)a[i][i]/heso;
			}
		else
		{
			if(temp==-1)
				temp=-1;
		}
	}
	return temp;
}
float lonNhatTrong2So(float a,float b)
{
	return (a>=b)?a:b;
}
float lonNhatTrong3So(float a,float b,float c)
{
	float m=lonNhatTrong2So(a,b);
	float n=lonNhatTrong2So(m,c);
	return n;
}
int main()
{
	int x=3;
	bangnhau(x,x);

	cout<<"Nhap vao so hang: ";
	cin>>SOHANG;
	cout<<"Nhap vao So Cot : ";
	cin >>SOCOT;
	NhapMaTran(a);
	cout<<"ma tran L1"<<endl;
	InMaTran(a);
	//cout<<"ma tran B la: "<<endl;
	//Get_maxtrixL2(a,b);
	//InMaTran(b);
	//cout<<"ma tran C la: "<<endl;
	//Get_maxtrixL3(a,b,c);
	//InMaTran(c);
	cout<<"ma tran L2"<<endl;
	get_L1(a,a,b);
	InMaTran(b);
	cout<<"ma tran L3"<<endl;
	get_L1(b,a,c);
	InMaTran(c);
	float t=lonNhatTrong3So(lon_nhat(a,1),lon_nhat(b,2),lon_nhat(c,3));
	cout<<"gioi han lap: "<<t<<endl;
}
