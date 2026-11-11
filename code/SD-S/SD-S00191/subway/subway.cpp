#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int MAXN = 505;
const int MAXM = 5e5+5;
const int MAXV = 2e6+5;
const int INF = 1e9;
int c,n,m,d,Q;
vector<pair<int,int> > G[MAXV];
int idx;
int w[MAXM];
void add(int u,int v,int w)
{
	//cout << u << " " << v << " " << w << '\n';
	G[u].push_back({v,w});
	G[v].push_back({u,w});
	return;
}
int dis[MAXV];
bool vis[MAXV];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void dijkstra(int s)
{
	for(int i = 1;i<=idx;i++) dis[i] = INF,vis[i] = 0;
	dis[s] = 0;
	q.push({0,s});
	while(!q.empty())
	{
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0;i<(int)G[u].size();i++)
		{
			int v = G[u][i].first,w = G[u][i].second;
			if(!vis[v] && dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push({dis[v],v});
			}
		}
	}
	return;
}
void sol1()
{
	for(int i = 1;i<=m;i++) cin >> w[i];
	idx = m;
	for(int i = 1;i<=n;i++)
	{
		int k; cin >> k;
		int num = ++idx; 
		//cout << num << '\n';
		for(int j = 1;j<=k;j++)
		{
			int a,b; cin >> a >> b;
			add(num,++idx,0);
			add(idx,a,b);
		}
	}
	for(int i = 1;i<=Q;i++)
	{
		int x,y; cin >> x >> y;
		dijkstra(x);
		cout << dis[y]+w[x]+w[y] << '\n';
	}
}
void sol2()
{
	for(int i = 1;i<=m;i++) cin >> w[i];
	idx = m;
	for(int i = 1;i<=n;i++)
	{
		int k; cin >> k;
		if(k == 1) continue;
		int a1,a2,b1,b2;
		cin >> a1 >> b1 >> a2 >> b2;
		add(a1,a2,b1+b2);
	}
	for(int i = 1;i<=Q;i++)
	{
		int x,y; cin >> x >> y;
		dijkstra(x);
		cout << dis[y]+w[x]+w[y] << '\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	if(1 <= c && c <= 6) sol1();
	else if(7 <= c && c <= 11) sol2();
	sol1();
	return 0;
}

