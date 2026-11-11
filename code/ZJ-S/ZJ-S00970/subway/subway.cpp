#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[int(5e5) + 5], k, a[505][505], anext[505][505], t[505][505], x, y, vis2[505][505];
long long ans = 1e9;


vector <int> vis[505];

void DFS(int now, int y, long long sum, int line)
{
		if(now == y) 
		{
			ans = min(ans, sum + t[line][now]);
			return;
		}
		if(sum > ans || now == 0) return;
		if(vis[now].size() == 1)
		{
			DFS(a[line][int(vis2[line][now]) + 1], y, sum, line);
		}
		else{
			for(int i = 0; i < vis[now].size(); i++)
			{
				if(vis[now][i] == line)
				{
					DFS(a[line][int(vis2[line][now]) + 1], y, sum, line);
				}
				else{
					DFS(a[vis[now][i]][int(vis2[vis[now][i]][now]) + 1], y, sum + t[line][now] + t[vis[now][i]][now], vis[now][i]);
				}
			}
		}
		
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> a[i][j] >> t[i][a[i][j]];
			vis[a[i][j]].push_back(i);
			vis2[i][a[i][j]] = j;
		}
	}
	for(int i = 1; i <= q; i++)
	{
		ans = 1e9;
		cin >> x >> y;
		int line = 0, time = 1e9;
		for(int i = 1; i <= n; i++)
		{
			if(t[i][x] == 0) continue;
			if(t[i][x] < time)
			{
				line = i;
				time = t[i][x];
			}
		}
		time += w[x];
		DFS(x, y, 1ll * time, line);
		cout << ans + w[y]<< ' ';
	}
	return 0;
}

