#include<bits/stdc++.h>
using namespace std;
int n,m; 
long long a[200010];
long long maxs=-1,ands=-1;
long long vis[200010];
void dfs(int cnt,long long sum,int j)
{
	if(cnt==m)
	{
		maxs=max(maxs,sum);
		return;
	}
	for(int i=j+1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(cnt+1,(sum&a[i]),i);
			vis[i]=0;
		}
	}
}
int main()
{
 	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			maxs=max(maxs,a[i]);
		}
		cout<<maxs;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(ands=-1) ands=a[i];
			else ands=(ands&a[i]);
		}
		cout<<ands;
		return 0;
	}
	if(n<=2000&&m==2)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long t=(a[i]&a[j]);
				maxs=max(maxs,t);
			}
		}
		cout<<maxs;
		return 0;
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			dfs(1,a[i],i);
			vis[i]=0;
		}
		cout<<maxs;
		return 0;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				long long t=a[2];
				for(int j=3;j<=n;j++)
				{
					t= t&a[j];
				}
				maxs=max(maxs,t);
			}
			else
			{
				long long t=a[1];
				for(int j=2;j<=n;j++)
				{
					if(j!=i) t= t&a[j];
				}
				maxs=max(maxs,t);
			}
		}
		cout<<maxs;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long ans=a[n];
	for(int i=2;i<=m;i++)
	{
		ans= ans&a[n-i+1];
	}
	cout<<ans;
    return 0;
}

