#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[10050],a[10050],t[10050];
long long dp[10050];
vector<pair<int,int>>g[10005];
bool vis[10050];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>k[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)cin>>a[j]>>t[j];
		for(int j=1;j<x;j++)
	    {
	    	for(int k=j+1;k<=x;k++)
	    	{
	    		g[a[j]].push_back({a[k],t[k]+t[j]});
		        g[a[k]].push_back({a[j],t[k]+t[j]});
			}
	    }
	}
	for(int i=1;i<=q;i++)
	{
		int fi,en;
		cin>>fi>>en;
		memset(dp,0x3f,sizeof dp);
		memset(vis,0,sizeof vis);
		dp[fi]=0;
		for(int j=1;j<=m;j++)
		{
			int u=0;
			for(int k=1;k<=m;k++)
			{
				if(!vis[k]&&dp[k]<dp[u])u=k;
			}
			vis[u]=1;
			for(auto &it:g[u])
			{
				dp[it.first]=min(dp[it.first],dp[u]+it.second);
			}
		}
		cout<<dp[en]+k[fi]+k[en]<<"\n";
	}
	return 0;
 } 
