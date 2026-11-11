#include<bits/stdc++.h>
using namespace std;
int c,t;
long long dp[5001],dis[5001],a[5001];
vector<int> b[5001];
bool vis[5001];
void dfs(int x,int fa)
{
	//cout<<x<<"\n";
	for(int i=0;i<b[x].size();i++)
	{
		int nv=b[x][i];
		if(nv==fa or vis[nv])
		{
			continue;
		}
		if(dis[x]+abs(a[x]-a[i])<dis[nv])
		{
			dis[nv]=dis[x]+abs(a[i]-a[x]);
			dp[nv]=dp[x];
			vis[nv]=1;
			dfs(nv,x);
			vis[nv]=0;
		}
		else if(dis[x]+abs(a[x]-a[i])==dis[nv])
		{
			dp[nv]+=dp[x];
			vis[nv]=1;
			dfs(nv,x);
			vis[nv]=0;
		}
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ac=1;ac<=t;ac++)
	{
		memset(dp,0,sizeof(dp));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]-a[j]>d)
				{
					break;
				}
				b[i].push_back(j);
				b[j].push_back(i);
				//cout<<i<<" and "<<j<<"\n";
			}
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d)
				{
					break;
				}
				b[i].push_back(j);
				b[j].push_back(i);
				//cout<<i<<" and "<<j<<"\n";
			}
		}
		for(int i=1;i<=n;i++)
		{
			dis[i]=1e18;
		}
		for(int i=1;i<=n;i++)
		{
			if(dis[i]==1e18)
			{
				dis[i]=0LL;
				dp[i]=1LL;
				vis[i]=1;
				dfs(i,i);
				vis[i]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			//cout<<dis[i]<<"\n";
			if(dp[i]==2LL)
			{
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
