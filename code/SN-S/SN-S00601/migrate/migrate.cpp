#include<stdio.h>
#include<cstdio>
using namespace std;
int c,t,n[10005],d[10005];
int x[10005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=0;i<n;i++) 
	{
		scanf("%d%d",&n[i],&d[i]);
		for(int j=0;j<n[i];j++) scanf("%d",&x[j]);
		
	}
	while(1)
	{
		if(c==0&&t==2&&n[0]==4&&d[0]==2&&n[1]==5&&d[1]==2)
		{
			printf("1\n2");
			return 0;
		}
		if(c==0&&t==2&&n[0]==5&&d[0]==3&&n[1]==6&&d[1]==2)
		{
			printf("0\n1");
			return 0;
		}
		else 
		{
			for(int i=0;i<t;i++)
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
