/*
Calm down and trust yourself, control the match in your pace.
*/
#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define I using
#define AK namespace
#define CSPS2026 std
I AK CSPS2026;
const int maxn=1e6+10,maxm=5e2+10,mod=998244353,inf=1e18;
int t,c,n,m,d,x,y,z,u,v,w,arr[maxn],dp[maxm][maxm];
vector<pair<int,int> >g[maxn];
void floyd()
{
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	FastIO;
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++)cin>>arr[i];
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>u>>w;
			g[u].push_back({i,w});
		}
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			dp[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int cur=(int)(g[i].size());
		for(int j=0;j<cur;j++)for(int k=j+1;k<cur;k++)
		{
			int mn=min(dp[g[i][j].first][g[i][k].first],dp[g[i][k].first][g[i][j].first]); 
			dp[g[i][j].first][g[i][k].first]=min(mn,g[i][j].second+g[i][k].second);
			dp[g[i][k].first][g[i][j].first]=dp[g[i][j].first][g[i][k].first];
		}
	}
	floyd();
	while(t--)
	{
		cin>>u>>v;
		int ans=arr[u]+arr[v],res=inf;
		for(auto i:g[u])for(auto j:g[v])res=min(res,i.second+j.second+dp[i.first][j.first]);
		cout<<ans+res<<"\n";
	}
	return 0;
}
/*
15:30 pass!!!!
*/

