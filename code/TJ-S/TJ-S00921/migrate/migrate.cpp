#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000009];
int n;
long long d;
int dp[19][19];
void dfs(int x,int fa)
{
	if(x>=n)
	{
		return;
	}
	dp[fa][x]++;
	for(long long i=1;i<=d;i++)
	{
		if(a[x+i]!=0x80)
		{
		dfs(x+i,x);
		}
		else continue;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t)
	{
		int ans=0;
		cin>>n>>d;
		memset(a,0x80,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		bool f=1;
		for(int i=2;i<=n-1;i++)
		{
			if(a[i]-a[i-1]!=a[i+1]-a[i])
			{
				f=0;
			}
		}
		if(f)
		{
			long long q=d/(a[2]-a[1]);
			if(q<=1)
			{
				cout<<0<<"\n";
			
			}
			for(int i=1;i<=n;i++)
			{
				a[i]=i;
			}
			if(q>=3)
			{
				cout<<0<<"\n";
		
			}
			else if(q>1&&q<=2)
			{
				cout<<n-3<<"\n";
		
			}
		}
		else
		{
		dfs(1,0);
		for(int len=3;len<=n;len++)
		{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			for(int k=i;k<=j;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(dp[i][j]==2)
			{
				ans++;
			}
		}
	}
		cout<<ans<<"\n";
	}
		t--;
	}
	
	return 0;
}
