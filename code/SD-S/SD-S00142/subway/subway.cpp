#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXM = 1e6 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
ll w[MAXN], dis[MAXM];
bool vis[MAXM];
struct Edge
{
	int v;
	ll w;
};
vector <Edge> adj[MAXM];
void dijkstra(int s)
{
	priority_queue <int> q;
	q.push(s);
	dis[s] = 0;
	while(!q.empty())
	{
		int u = q.top();
		q.pop();
		vis[u] = true;
		// printf("当前父亲节点：%d\n", u);
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].v;
			ll w = adj[u][i].w;
			if(vis[v])
			{
				continue;
			}
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
			}
			q.push(v);
			// printf("延申子节点：%d\n", v);
		}
	}
	return ;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld", &w[i]);
	}
	int sum = m;
	for(int i = 1, k; i <= n; i++)
	{
		scanf("%d", &k);
		for(int j = 1, a; j <= k; j++)
		{
			ll t;
			scanf("%d%lld", &a, &t);
			sum++;
			adj[sum].push_back({a, t});
			adj[a].push_back({sum, t});
			if(j > 1)
			{
				adj[sum].push_back({sum - 1, 0});
				adj[sum - 1].push_back({sum, 0});
			}
		}
	}
	while(q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		fill(dis + 1, dis + m + sum + 1, INF);
		fill(vis + 1, vis + m + sum + 1, false);
		dijkstra(x);
		printf("%lld\n", dis[y] + w[x] + w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 15:13 思路考虑分层图，英改师正解，兑。（还有这个 c 是 hyw，纯粹增加阅读难度的吗） 
// 15:28 啥叫 q 有 1e5，坏了好像不会 
// 15:29 易得超级节点（展示嘴脸）  又：无疑是不对的 
// 15:56 坏了好像真不会了
// 16:13 写 60pts 吧，思路太石山了
// 16:29 其实连 60pts 都拿不到，时间复杂度太高了应该是 40pts~50pts. 
