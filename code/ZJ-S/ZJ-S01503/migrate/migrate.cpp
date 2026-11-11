#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],num,run,dai;
void pan(int x,int y,int ci)
{
	if(x==y)
	{
		if(ci<run) run=ci,dai=1;
		else if(ci==run) dai++;
		return ;
	}
	for(int i=1;i<=y-x && a[x+i]-a[x]<=d;i++)
	{
		pan(x+i,y,ci+1);
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		num=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n>5000)
		{
			if(a[2]-a[1]==a[3]-a[2] && a[4]-a[3]==a[3]-a[2])
			{
				if(a[3]-a[1]<=d && a[4]-a[1]>d) printf("%d\n",n-3);
				else printf("%d\n",0);
			}
		}
		else
		{
			for(int i=1;i<n-1;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
					dai=1,run=1e9;
					pan(i,j,0);
					if(dai==2) num++;
				}
			}
			printf("%d\n",num);
		}
	}
	return 0;
}