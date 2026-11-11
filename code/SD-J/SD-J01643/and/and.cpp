#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
const int INF=0x3f3f3f3f;
using namespace std;
int n,m;
int a[N];
int mx=-1;
int id;
int ans=-1;
bool vis[N];
void dfs(int sum,int cnt)
{
	if(cnt==m)
	{
		ans=max(ans,sum);
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				dfs(sum&a[i],cnt+1);
				vis[i]=0;
			}
			
		}
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(mx<=a[i])
		{
			mx=a[i];
			id=i;
		}
	}
	if(n<=2000)
	{
		if(m==1)
		{
			cout<<mx<<"\n";
			return 0;
		}
		if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j)
					{
						ans=max(ans,a[i]&a[j]);
					}
				}
			}
			cout<<ans<<"\n";
			return 0;
		}
		if(m==n)
		{
			ans=a[1];
			for(int i=2;i<=n;i++)
			{
				ans=ans&a[i];
			}
			cout<<ans<<"\n";
			return 0;
		}
		dfs(INF,0);
		cout<<ans<<"\n";
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int ans=INF;
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans&=a[i];
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 3
31 3 1 15 7

*/
