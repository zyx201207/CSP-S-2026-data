#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500001;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
int C;
int n;
int m;
int d;
int q;
int num;
int cost[MAXN];
long long dist[MAXN];
long long f[505][505];
long long to[505][505];
vector<long long> dis[501];
bool vis[MAXN];
vector<pair<int,int> > vec[MAXN];
unordered_map<int,int> a[500001];
int get(int type, int id)
{
	if(type == 1)   //xian
	{
		return id;
	}
	if(type == 2)   //zhanting
	{
		return n+id;
	}
	return n+m+id;//zhantai
}
void dij1(int st)
{
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	dist[st] = 0;
	priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long,int> > > q;
	q.push(make_pair(0,st));
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u] = true;
		for(auto i : vec[u])
		{
			int v = i.first;
			int w = i.second;
			if(dist[v]>dist[u]+w)
			{
				dist[v] = dist[u]+w;
				q.push(make_pair(dist[v],v));
			}
		}
	}
	for(int i = 1; i<=n; i++)
	{
		to[st][i] = dist[i];
	}
}
void dij(int st)
{
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	dist[st] = 0;
	priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long,int> > > q;
	q.push(make_pair(0,st));
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u] = true;
		for(auto i : vec[u])
		{
			int v = i.first;
			int w = i.second;
			if(dist[v]>dist[u]+w)
			{
				dist[v] = dist[u]+w;
				q.push(make_pair(dist[v],v));
			}
		}
	}
	for(int i = 1; i<=m; i++)
	{
		dis[st][i] = dist[get(2,i)];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>C>>n>>m>>d>>q;
	if(1ll*n*m*log2(m)>=1000000000ll)
	{
		for(int i = 1; i<=m; i++)
		{
			cin>>cost[i];
		}
		for(int i = 1; i<=n; i++)
		{
			int k;
			cin>>k;
			for(int j = 1; j<=k; j++)
			{
				int u;
				int t;
				cin>>u>>t;
				a[u][i] = t;
			}
		}
		memset(to,INF,sizeof(to));
		memset(f,INF,sizeof(f));
		for(int i = 1; i<=m; i++)
		{
			for(int x = 1; x<=d; x++)
			{
				for(int y = 1; y<=d; y++)
				{
					if(x == y)
					{
						continue;
					}
					if(a[i].count(x) && a[i].count(y))
					{
						f[y][x] = f[x][y] = min(1ll*f[x][y],1ll*a[i][x]+a[i][y]);
					}
				}
			}
		}
		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<=n; j++)
			{
				if(i == j)
				{
					continue;
				}
				if(f[i][j] == INF)
				{
					continue;
				}
				vec[i].push_back(make_pair(j,f[i][j]));
				vec[j].push_back(make_pair(i,f[i][j]));
			}
		}
		for(int i = 1; i<=n; i++)
		{
			dij1(i);
		}
		while(q--)
		{
			int u;
			int v;
			cin>>u>>v;
			long long res = INF;
			for(int i = 1; i<=n; i++)
			{
				for(int j = 1; j<=n; j++)
				{
					if(a[u].count(i) && a[v].count(j))
					{
						long long tmp1 = a[u][i];
						long long tmp2 = a[v][j];
						long long tmp3 = to[i][j];
						res = min(res,tmp1+tmp2+tmp3);
					}
				}
			}
			cout<<res+cost[u]+cost[v]<<'\n';
		}
		return 0;
	}
	for(int i = 1; i<=n; i++)
	{
		dis[i].resize(m+1);
	}
	for(int i = 1; i<=m; i++)
	{
		cin>>cost[i];
	}
	for(int i = 1; i<=n; i++)
	{
		int k;
		cin>>k;
		for(int j = 1; j<=k; j++)
		{
			int u;
			int t;
			cin>>u>>t;
			int id = ++num;
			vec[get(1,i)].push_back(make_pair(get(3,id),0));
			vec[get(3,id)].push_back(make_pair(get(1,i),0));
			vec[get(2,u)].push_back(make_pair(get(3,id),t));
			vec[get(3,id)].push_back(make_pair(get(2,u),t));
		}
	}
	for(int i = 1; i<=n; i++)
	{
		dij(i);
	}
	while(q--)
	{
		int u;
		int v;
		cin>>u>>v;
		long long res = INF;
		for(int i = 1; i<=n; i++)
		{
			long long tmp1 = dis[i][u];
			long long tmp2 = dis[i][v];
			res = min(res,tmp1+tmp2);
		}
		cout<<res+cost[u]+cost[v]<<'\n';
	}
	return 0;
}
