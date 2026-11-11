#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define lc u>>1
#define rc u>>1+1
#define fir first
#define sec second
const int N=2e5+10;
const int INF=1e18;
bool st[25];
int a[25];
int ans=-INF;
int n,m;
void dfs(int x)
{
	if(x>n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++) if(st[i]) cnt++;
		if(cnt==m)
		{
			int sum=0,pos=0;
			for(int i=1;i<=n;i++)
			{
				if(st[i])
				{
					pos=i;
					sum=a[i];
					break;
				}
			}
			for(int i=pos+1;i<=n;i++)
			{
				if(st[i]) sum&=a[i];
			}
			ans=max(ans,sum);
		}
		return;
	}
	st[x]=0;
	dfs(x+1);
	st[x]=1;
	dfs(x+1);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios;
	cin>>n>>m;
	bool pp=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<=21;j++) if(a[i]!=((1<<j)-1)) pp=0;
	}
	if(m==n)
	{
		int p=a[1];
		for(int i=2;i<=n;i++) p&=a[i];
		cout<<p;
	}
	else if(m==1)
	{
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
	}
	else if(pp)
	{
		sort(a+1,a+n+1,greater<int>());
		int tt=a[1];
		for(int i=2;i<=m;i++) tt&=a[i];
		cout<<tt;
	} 
	else
	{
		dfs(1);
		cout<<ans;
	}
	return 0;
} 
/*
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[j][i][0]=-INF;
			dp[j][i][1]=-INF;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[0][i][0]=0;
		dp[0][i][1]=0;
	}
	dp[1][1][0]=0;
	dp[1][1][1]=a[1];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
			dp[i][j][1]=max(dp[i-1][j][0]&a[j],dp[i-1][j][1]&a[j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<dp[i][j][0]<<" ";
		}
		cout<<"\n";
		for(int j=1;j<=n;j++)
		{
			cout<<dp[i][j][1]<<" ";
		}
		cout<<"\n\n";
	}
	int ans=-INF;
	for(int i=1;i<=n;i++)
	{
		ans=max(dp[m][i][0],dp[m][i][1]);
	}
	cout<<ans;
	return 0;
}

4 2
3 15 12 12

*/
