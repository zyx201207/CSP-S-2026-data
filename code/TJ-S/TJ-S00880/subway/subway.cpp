#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, cv, kk[510], w[500010], lb[510][510], dis[510][510][2], t[500010][510];
bool a[500010][510];
vector<pair<int, int> > G[510];
vector<int> h, l[500010];
vector<pair<int, int> > qs;
void s()
{
	for(int i = 1; i <= n; ++i)
	{
		dis[i][i][0] = 0;
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int k = 1; k <= n; ++k)
		{
			for(int j = 1; j <= n + cv; ++j)
			{
				if(lb[i][k] && lb[j][k])
				{
					dis[i][j][0] = min(dis[i][j][0], dis[i][k][0] + dis[k][j][0] + G[i][k].second + G[k][j].second);
					if(j > n)dis[i][j][1] = min(dis[i][j][1], dis[i][k][0] + dis[k][j][0] + G[i][k].second + G[k][j].second);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(long long i = 1; i <= m; ++i)
	{
		scanf("%d", w + i);
	}
	for(long long i = 1; i <= n; ++i)
	{
		scanf("%d", kk + i);
		for(int j = 1, tmp; j <= kk[i]; ++j)
		{
			scanf("%d", &tmp);
			scanf("%d", &t[tmp][i]);
			a[tmp][i] = true;
			l[j].push_back(i);
		}
	}
	for(int i = 1, s, e; i <= q; ++i)
	{
		scanf("%d%d", &s, &e);
		qs.push_back({s, e});
		++cv;
		l[cv + n].push_back(e);
		a[e][cv + n] = true;
	}
	//cout << l[3][0];
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(a[i][j] == true)
			{
				for(int k = 0; k < h.size(); ++k)
				{
					if(lb[j][h[k]] != 0)
					{
						G[j][lb[j][h[k]]].second = min(G[j][lb[j][h[k]]].second, t[i][j] + t[i][h[k]]);
						G[lb[j][h[k]]][j].second = min(G[lb[i][h[k]]][j].second, t[i][j] + t[i][h[k]]);
					}
					else
					{
						lb[j][h[k]] = G[j].size() - 1;
						G[j].push_back({h[k], t[i][j] + t[i][h[k]]});
						lb[h[k]][j] = G[h[k]].size() - 1;
						G[h[k]].push_back({j, t[i][j] + t[i][h[k]]});
					}
				}
				h.push_back(j);
			}
		}
		h.clear();
	}
	for(int i = n + 1; i <= n + cv; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(a[l[i][0]][j])
			{
				G[j].push_back({i, t[l[i][0]][j]});
				lb[j][i] = G[j].size() - 1;
			}
		}
	}
//	for(int i = 1; i <= n; ++i)
//	{
//		for(int j = 0; j < G[i].size(); ++j)
//		{
//			cout << G[i][j].first << " " << G[i][j].second << " " << i << " " << j << "\n";
//		}
//		cout << "\n\n";
//	}
	s();
	//cout << "A";
	for(int i = 1; i <= q; ++i)
	{
		cout << dis[qs[i].first][qs[i].second][1] + w[qs[i].first] + w[qs[i].second] << "\n";
	}

	return 0;
}
