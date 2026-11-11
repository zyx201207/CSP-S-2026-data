#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long x[2000005],ans;
vector<int>g[2000005];
int dp[2000005],min_dp[2000005];//dp[i][j]表示i点的j“深度”出现情况 
void dfs(int x,int step)
{
	for(int i=0;i<g[x].size();i++)
	{
		
		if(min_dp[g[x][i]]>step+1)
		{
			min_dp[g[x][i]]=step+1;
			dp[g[x][i]]=1;
		}
		else if(min_dp[g[x][i]]==step+1)
		{
			dp[g[x][i]]++;
		}
		dfs(g[x][i],step+1);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		{
			if(x[j]-x[i]<=d)g[i].push_back(j);
			else break;	
		} 
		for(int i=1;i<=n;i++)
		{
			memset(dp,0,sizeof dp);
			memset(min_dp,0x3f,sizeof min_dp);
			dfs(i,0);
			for(int j=i+1;j<=n;j++)
			{
				if(min_dp[j]!=1061109567)ans+=(dp[j]==2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
