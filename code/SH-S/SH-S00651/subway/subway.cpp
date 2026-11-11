#include<bits/stdc++.h>
using namespace std;

/*
这道题有陷阱：n是地铁线路数，m反倒是地铁站数
将同一根地铁上的两个站点的距离看做 U 站台到地铁 + 地铁到 V 站台
不管怎样，先写dj 
*/

typedef long long ll;

int c, n, m, d, q; // c是不是给得有点太没用了 

const int M = 5e5 + 5;
bool vis[M];
int dis[M];
const int INF = 0x3f3f3f3f;
int arr[M]; // 从地铁口到站厅的距离 

struct edge
{
	int v;
	int w;
};

vector<edge> g[M];

struct node
{
	int idx;
	int dist;
	bool operator < (const node & other) const
	{
		return dist > other.dist;
	}
};

void dj(int s)
{
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	priority_queue<node> q;
	q.push({s, 0});
	while(!q.empty())
	{
		node cur = q.top();
		q.pop();
		int u = cur.idx;
		vis[u] = true;
//		cout<<444<<" "<<g[u].size()<<endl;
		for(int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i].v;
			int w = g[u][i].w;
			if(vis[v]) continue;
//			cout<<333<<endl;
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	cin>>c>>n>>m>>d>>q;
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
	{
//		cin>>arr[i];
		scanf("%d", &arr[i]);
	}
	vector<int> ve;
	vector<int> tt;
	for(int i = 1; i <= n; i++)
	{
		int k;
//		cin>>k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		{
			int u, t;
//			cin>>u>>t;
			scanf("%d %d", &u, &t);
			for(int l = 0; l < ve.size(); l++)
			{
				int v = ve[l];
				g[u].push_back({v, t + tt[l]});
				g[v].push_back({u, t + tt[l]});
//				cout<<555<<" "<<u<<" "<<v<<" "<<t + tt[l]<<endl;
			}
			ve.push_back(u);
			tt.push_back(t);
//			cout<<222<<endl;
		}
		ve.clear();
		tt.clear();
	}
//	cout<<111;
	while(q--)
	{
		int s, e;
//		cin>>s>>e;
		scanf("%d %d", &s, &e);
		dj(s);
//		cout<<dis[e] + arr[s] + arr[e]<<"\n";
		printf("%d\n", dis[e] + arr[s] + arr[e]);
	}
	return 0;
}
/*
预计本题得到12分，回头用scanf/printf优化一下
优化过了，只要不犯小错误，能拿到24分 
*/
