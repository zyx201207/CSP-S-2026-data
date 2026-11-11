#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 0x3f3f3f3f3f3f3f3f;
ll w[500005];
//w 地铁口走到站厅需要的时间
vector<int> a[505];
vector<int> sub[500005];
map<int, ll> t[505];
//a[i][j] 表示第 i 条线路经过的第 j 个地铁站
//t[i][j] 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
int k[505];
//k[i] 表示第 i 条线路经过的地铁站数
ll wib[505][505], mn[505][505];
//wib[i][j] 表示 i 地铁到 j 地铁边权
//mn[i][j] 表示 i 地铁到 j 地铁最短路
int c, n, m, d, q;

struct node
{
	int x;
	ll dis;
};

bool operator < (node x, node y)
{
	return x.dis > y.dis;
}

priority_queue<node> pq;

void dij(int s)
{
	while (!pq.empty())
		pq.pop();
	pq.push({s, 0});
	mn[s][s] = 0;
	while (!pq.empty())
	{
		node ff = pq.top();
		pq.pop();
		int x = ff.x;
		for (int i = 1; i <= n; i++)
		{
			if (i == x)
				continue;
			if (wib[x][i] == inf)
				continue;
			if (mn[s][i] <= mn[s][x] + wib[x][i])
				continue;
			mn[s][i] = mn[s][x] + wib[x][i];
			pq.push({i, mn[s][i]});
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//c	分别表示测试点编号
//n	地铁线路数
//m	地铁站数
//d	每个地铁站最多被几条线路经过
//q	以及出行计划数
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k[i]);
		a[i].push_back(0);
		for (int j = 1; j <= k[i]; j++)
		{
			int aa;
			ll tt;
			scanf("%d%lld", &aa, &tt);
			sub[aa].push_back(i);
			a[i].push_back(aa);
			t[i][aa] = tt;
		}
	}
	memset(wib, 0x3f, sizeof wib);
	for (int i = 1; i <= m; i++)
	{
		for (auto x : sub[i])
		{
			for (auto y : sub[i])
			{
				if (x == y)
					continue;
				wib[x][y] = min(wib[x][y], t[x][i] + t[y][i]);
			}
		}
	}
	memset(mn, 0x3f, sizeof mn);
	for (int i = 1; i <= n; i++)
		dij(i);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = 1e18;
		for (auto A : sub[x])
		{
			for (auto B : sub[y])
			{
				ans = min(ans, t[A][x] + mn[A][B] + t[B][y]);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}