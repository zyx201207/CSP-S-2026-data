#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+5;

int c, n, m, d, q, w[500005], a[500005], t[500005], dis[500005], vis[500005];
vector<vector<pair<int, int> > > tl(500005);

void djstl(int x, int y)
{
	memset(dis, INF, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, x});
//	for(int i = 0; i<(int)tl[x].size(); i++)
//	{
//		pq.push({tl[x][i].ti, tl[x][i].t});
//	}
	dis[x]=0;
	while(!pq.empty())
	{
//		cout<<1;
		pair<int, int> kb=pq.top(); pq.pop();
		if(vis[kb.second]) continue;
		vis[kb.second]=1;
		for(int i = 0; i<(int)tl[kb.second].size(); i++)
		{
			int xt=tl[kb.second][i].second, xti=tl[kb.second][i].first;
			if(!vis[xt] && dis[kb.second]+xti < dis[xt])
			{
				dis[xt]=dis[kb.second]+xti;
				pq.push({dis[xt], xt});
//				cout<<1;
			}
		}
	}
	cout<<dis[y]+w[x]+w[y]<<endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i<=m; i++)
	{
		cin>>w[i];
	}
	for(int i = 1; i<=n; i++)
	{
		int k;
		cin>>k;
		for(int j = 1; j<=k; j++)
		{
			int a, t;
			cin>>a>>t;
			tl[m+i].push_back({t, a});
			tl[a].push_back({t, m+i});
		}
	}
	while(q--)
	{
		int x, y;
		cin>>x>>y;
			djstl(x, y);
	}
	return 0;
 } 

//c[i+1]=当前升级代价 
