#include <iostream>
#include <stdio.h>
using namespace std;
long long x[2000005];
long long maxn=0,ans=0,anss=0;
long long n,d;
void dfs(int now,int end,long long step)
{
	if(ans>2) return ;
	if(step>maxn) return ;
	if(now==end)
	{
		if(step==maxn)
		{
			ans++;
		}
		return ;
	}
	for(int i=1;i<=end-now;i++)
	{
		if(x[now+i]-x[now]<=d)
		{
			dfs(now+i,end,step+1);
		}
	}
}
void find(int x1,int y1)
{
	int u=x[x1],v=x[y1];
	long long sum=0;
	int cnt=1;
	for(int i=x1;i<=y1;i++)
	{
		if(x[i]-u>d)
		{
			cnt++;
			u=x[i-1];
		}
	}
	maxn=cnt;
	ans=0;
	dfs(x1,y1,0);
	if(ans==2)
	{
		anss++;
	} 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		anss=0;
		scanf("%lld%lld",&n,&d);
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				find(i,j);
			}
		}
		printf("%lld\n",anss);
	}
}
