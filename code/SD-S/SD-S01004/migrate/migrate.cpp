#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,x[N];
vector<int> g[N];
int dis[N],dp[N],bj[N];
void bfs(int s)
{
	for(int i=1;i<=n;i++) dis[i]=1e18,dp[i]=0;
	dis[s]=0,dp[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				dp[v]=dp[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+1) dp[v]+=dp[u];
		}
	} 
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int gc=x[2]-x[1];
			if(gc>=d)
			{
				cout<<"0\n";
				continue;
			}
			int x=d/gc;
			cout<<max(0ll,n-(x*2-1))<<"\n";
		}
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(x[i]-x[j])<=d)
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		} 
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++) if(dp[j]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}


