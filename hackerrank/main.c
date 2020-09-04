#include <stdio.h>
#include <stdlib.h>
int capdo(int * scores, int scores_count, int pos)
{
	if(pos==0)return 1;
    int dem=1;
    for(int i=1;i<scores_count;i++)
    {
        if(scores[i]!=scores[i-1])
        {
			dem++;
        }
        if(i==pos)
			break;
    }
    return dem;
}
int max(int * scores, int scores_count)
{
    int dem=1;
    for(int i=1;i<scores_count;i++)
    {
        if(scores[i]!=scores[i-1])
        {
            dem++;
        }

    }
    return dem;
}
int* climbingLeaderboard(int scores_count, int* scores, int alice_count, int* alice, int* result_count)
{
    static int result[20000];
    for(int i=0; i<alice_count ;i++ )// cập nhật mảng result
    {
        for(int j=0;j<scores_count;j++)
        {
            if(alice[i]<scores[scores_count-1])
            {
                result[i]=max(scores,scores_count)+1;
                break;
            }
            else if(alice[i]>=scores[j])
            {
                result[i]=capdo(scores,scores_count,j);
                break;
            }
        }
    }
    *result_count = alice_count;
    return result;
}
int main()
{
    int scores[]={100,100,50,40,40,20,10};
    int scores_count=sizeof(scores)/sizeof(int);
    printf("size scores: %d \n",scores_count);
    int a_scores[]={5,25,50,120};
    int a_count=sizeof(a_scores)/sizeof(int);
    printf("size scores: %d \n",a_count);
    int level_max=max(scores,scores_count);
    printf(" level max :%d \n",level_max);
    int pos;
    for(int i=0;i<scores_count;i++)
	{
		pos=i;
		int level_pos=capdo(scores,scores_count,pos);
	     printf(" level tai pos %d :%d \n",pos,level_pos);
	}
	int *b;
	int *n;
	b=climbingLeaderboard(scores_count,scores,a_count,a_scores,&n);
	printf("n la: %d \n",n);
	int size=n;
	for(int i=0;i<size;i++)
	{
		printf("%d \n",b[i]);
	}
	int a[100000]={0};
a[0]=1;

for(int i=0;i<size;i++)
	{
		printf("%d \n",a[i]);
	}

}
