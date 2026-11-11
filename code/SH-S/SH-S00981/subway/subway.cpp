#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ti
{
	int a;
	ll t;
};

bool operator<(ti a, ti b)
{
	return a.t < b.t;
}

const int N = 505, M = 500005;
vector<ti> b[M];
ll dis1[N][N], dis[N][N], w[M];
priority_queue<ti> p;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		while(k--)
		{
			int a;
			ll t;
			cin >> a;
			cin >> t;
			b[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			dis1[i][j] = 1e18;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int l = int(b[i].size());
		for(int j = 0; j < l; j++)
		{
			for(int k = 0; k < l; k++)
			{
				if(j == k) continue;
				dis1[b[i][j].a][b[i][k].a] = min(dis1[b[i][j].a][b[i][k].a], b[i][j].t + b[i][k].t);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) dis[i][j] = 9e17;
		p.push({i, 0});
		dis[i][i] = 0;
		while(!p.empty())
		{
			ti t = p.top();
			p.pop();
			if(t.t > dis[i][t.a]) continue;
			for(int j = 1; j <= n; j++)
			{
				ll cur = dis[i][t.a] + dis1[t.a][j];
				if(cur < dis[i][j])
				{
					dis[i][j] = cur;
					p.push({j, cur});
				}
			}
		}
	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		ll ans = 1e18;
		for(int i = 0; i < int(b[x].size()); i++)
		{
			for(int j = 0; j < int(b[y].size()); j++)
			{
				ans = min(ans, dis[b[x][i].a][b[y][j].a] + b[x][i].t + b[y][j].t);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
}
