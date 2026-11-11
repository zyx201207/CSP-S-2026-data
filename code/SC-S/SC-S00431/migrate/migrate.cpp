#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000010];
int s[2000005][2000010];
int n,d,jl,ans=0;//数量，能飞多远，记录数值 ，某个点可到达的点 
void read()
{
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	if(n<4)
	{
		cout<<0;
		return;
	}
	for(int i=1;i<=n-3;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i]+d<x[j])
			{
				jl=j-1;
				break;
			}
		}
	}
	for(int i=2;i<=jl;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i]+d<x[j])
			{
				s[i][j]=x[j];
				break;
			}
			
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=2 ;i<=jl;i++)
		{
			for(int z=0;z<n;z++)
			{
				if(s[i][j]==s[i+1][j+z])
				{
					ans++;
				}
			}
		}
	}
	cout<<ans;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++)
	{
		read();
	}
	return 0;
} 