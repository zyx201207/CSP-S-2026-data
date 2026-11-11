#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e2+5,INF=1e18;
int c,T,n,d,ans=0,cnt=0;
int a[N],dp[N];
void dfs(int cur,int ed,int sum,int l)
{
	if(sum>l)
	{
		return ;
	}
	if(cur==ed)
	{
		if(sum==l)
		{
			cnt++;
		} 
		return ;
	}
	for(int i=cur+1;i<=ed&&a[i]-a[cur]<=d;i++)
	{
		dfs(i,ed,sum+1,l);
	}
	return ;
}
bool check(int x,int y)
{
	for(int i=x;i<=y;i++)
	{
		dp[i]=INF;
	}
	dp[x]=0;
	cnt=0;
	for(int i=x;i<=y;i++)
	{
		for(int j=i+1;j<=y;j++)
		{
			if(a[j]-a[i]<=d)
			{
				dp[j]=min(dp[j],dp[i]+1);
			}
		} 
	}
	dfs(x,y,0,dp[y]);
	return cnt==2;
}
void solve()
{
	cin>>n>>d;
//	if(n<=9)
//	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				if(check(i,j)==true)
				{
					ans++;		
				}
			}
		}
		cout<<ans<<"\n";
//	}
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
} 
/*
0 2 
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
