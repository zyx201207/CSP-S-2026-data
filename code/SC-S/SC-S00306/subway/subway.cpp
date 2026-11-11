#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
using namespace std;
const int N=5e5+5,inf=1e18+7;
int m,n,d,q,I_LOVE_CCF_AND_QZY,w[N],dist[N];
vector<pii> g[N];
bool vis[N];
void diji(int st,int ed)
{
	for(int i=1;i<=n;i++){vis[i]=0;dist[i]=inf;}
	queue<int> q;
	q.push(st);
	dist[st]=w[st];
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto nxt:g[u])
		{
			int v=nxt.fi,w=nxt.se;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				q.push(v);
			}
		}
	} 
	cout<<dist[ed]+w[ed]<<'\n';
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>I_LOVE_CCF_AND_QZY>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int u,t,v,t1;
		for(int j=1;j<=k;j++)
		{
			cin>>v>>t1;
			if(j==1)continue;
			g[u].push_back({v,t1+t});
			g[v].push_back({u,t1+t});
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		diji(l,r);
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2