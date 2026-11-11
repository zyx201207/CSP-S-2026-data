#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const int M = 5e5 + 10, N = 1010;
LL h[N], e[M * 2], ne[M * 2], w[M * 2], idx;
LL dist[N][N];
bool st[N];
void add(int a, int b, LL c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int cost[N];
//vector<int> pass[N]; //经过 i 地铁站的路线数，不会超过 20 
vector<PII> vec[N]; //第i条路线经过的站点及时间 
int test, n, m, d, q, k, a, t;

void dijkstra(int start)
{
	memset(dist[start], 0x7f, sizeof dist[start]);
	memset(st, false, sizeof st);
	dist[start][start] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({0, start});
	while(q.size())
	{
		auto x = q.top();
		q.pop();
		int t = x.second;
		if(st[t]) continue;
		st[t] = true;
		for(int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if(dist[start][j] > dist[start][t] + w[i])
			{
				dist[start][j] = dist[start][t] + w[i];
				q.push({dist[start][j], j});
			}
		}
	}
}
int main()
{
	//only when sigma(C(ki, 2)) is small can it work
	
	//最后记得删掉//
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(h, -1, sizeof h);
	cin >> test >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) scanf("%d", &cost[i]);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &k);
		for(int j = 1; j <= k; j ++)
		{
			scanf("%d%d", &a, &t);
			vec[i].push_back({a, t});
			//pass[a].push_back(i);
		}
		for(int j = 0; j < vec[i].size(); j ++)
			for(int l = 0; l < j; l ++)
			{
				add(vec[i][j].first, vec[i][l].first, vec[i][j].second + vec[i][l].second);
				add(vec[i][l].first, vec[i][j].first, vec[i][j].second + vec[i][l].second);
			}
	}
	for(int i = 1; i <= m; i ++) dijkstra(i);
	int x, y;
	while(q --)
	{
		scanf("%d%d", &x, &y);
		printf("%lld\n", 1ll * (cost[x] + cost[y]) + dist[x][y]);
	} 

	return 0;
}

