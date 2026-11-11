#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 5e5 + 5, maxM = 5e5 * 20 + 5;
int cnt = 0;
struct Edge
{
	int u, v;
	ll val;
}E[maxM];
int p[maxM], c[maxM];
int getP(int x)
{
	if(p[x] == x)return x;
	return p[x] = getP(p[x]);
}
bool lnk(int x, int y)
{
	int px = getP(x), py = getP(y);
	if(px == py)return 0;
	if(c[px] < c[py])swap(px, py);
	c[px] += c[py];
	p[py] = p[px];
	return 1;
}
struct edge
{
	int v;
	ll d;
};
vector<edge> G[maxM];
ll dis[maxM];
void dfs(int u, int p)
{
	for(auto v : G[u])
		if(v.v != p)
		{
			dis[v.v] = dis[u] + v.d;
			dfs(v.v, u);
		}
} 
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	//口和厅 
	//i表示第几个站 
	for(int i = 1; i <= m; i++)
	{
		ll w;
		scanf("%lld", &w);
		E[++cnt] = {(i - 1) * d, (i - 1) * d + 1, w};
	}
	//i表示台的种类，a表示第几个站，t表示厅和台的距离，lsta表示上一个站 
	for(int i = 1; i <= n; i++)
	{
		int k, a, lsta;
		ll t;
		scanf("%d", &k);
		scanf("%d%lld", &a, &t);
		E[++cnt] = {(a - 1) * d + 1, (a - 1) * d + i + 1, t}; //厅和台 
		lsta = a;
		for(int j = 2; j <= k; j++)
		{
			scanf("%d%lld", &a, &t);
			E[++cnt] = {(lsta - 1) * d + i + 1, (a - 1) * d + i + 1, 0};//站和站 
			E[++cnt] = {(a - 1) * d + 1, (a - 1) * d + i + 1, t}; //厅和台 
			lsta = a;
		}
	}
	sort(E + 1, E + cnt + 1, 
	[](Edge a, Edge b)
	{
		return a.val < b.val;
	});
	for(int i = 1; i <= m * d; i++)p[i] = i;
	for(int i = 1; i <= cnt; i++)
	{
		int u = E[i].u, v = E[i].v;
		ll val = E[i].val;
		if(lnk(u, v))
		{
			G[u].push_back({v, val});
			G[v].push_back({u, val});
		}
	}
	while(q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		dis[(x - 1) * d] = 0;
		dfs((x - 1) * d, -1);
		printf("%lld\n", dis[(y - 1) * d]);
	}
	return 0;
}
