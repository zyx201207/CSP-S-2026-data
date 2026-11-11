#include<bits/stdc++.h>
using namespace std;
struct qwe{
	int a,t;
};
int cz[500005],xls[505];
qwe xl[505][20];
int qa(int a1,int n)
{
	for(int i=1;i<=xls[n];i++)
	{
		if(xl[n][i].a==a1)
		{
			return 1;
		}
    }
    return 0;
}
int qaz(int b1,int b2,int n)
{
	for(int i=1;i<=xls[n];i++)
	{
		for(int i=1;i<=xls[n];i++)
		{

    	}
    }
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&cz[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&xls[i]);
		for(int j=1,k=1;j<=xls[i]*2;j++)
		{
			if(j%2==1)
			{
				scanf("%d",&xl[i][k].a);
			}
			else
			{
				scanf("%d",&xl[i][k].t);
				k++;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int cu,dao,sum=0;
		scanf("%d%d",%cu,%dao);
		for(;;)
		{

		}
		sum+=cz[cu]+cz[dao];
		
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
