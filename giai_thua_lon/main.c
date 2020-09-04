#include <stdio.h>
#include <stdlib.h>

#define size 200
int main()
{
	int a[size]={0};
	a[size-1]=1;
	int du=0;
	int nguyen=0;
	int temp;
	int n=100;
	int dem=0;
for(int i=1;i<=n;i++)
{
    for(int j=size-1;j>=0;j--)
    {
        temp=a[j]*i;
        du=temp%10000;
        a[j]=du+nguyen;
        nguyen=temp/10000;
    }
}
for (int i=0;i<size;i++)
{
	if(dem==0)
    {
        if(a[i]!=0)
            dem++;
    }
    if(dem==1)
    {
        if(a[i]%10000!=0)
        printf("%d",a[i]%10000);
        else
        printf("0000");

    }
}
printf("\n");
for (int i=0;i<size;i++)
{
	printf("%d ",a[i]);
}

}
