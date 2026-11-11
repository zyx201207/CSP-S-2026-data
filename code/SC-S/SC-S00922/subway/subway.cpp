#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, m, n, d, q;
int w[500010], len[510];
vector<pair<int, int> > li[510];
int dis[1010][1010];
signed main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
//	if(c <= 11)
	{
		memset(dis, 0x3f, sizeof(dis));
		for(int i = 1;i <= m;i++)
		{
			cin >> w[i];
		}
		for(int i = 1;i <= n;i++)
		{
			dis[i][i] = 0;
			cin >> len[i];
			for(int j = 1;j <= len[i];j++)
			{
				int x, y;
				cin >> x >> y;
				li[i].push_back({x, y});
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(pair<int, int> u : li[i])
			{
				for(pair<int, int> v : li[i])
				{
					if(u.first == v.first)
					{
						continue;
					}
//					cout << u.first << ' ' << v.first << '\n';
					dis[u.first][v.first] = u.second + v.second;
				}
			}
		}
		for(int i = 1;i <= m;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				if(i == j)
				{
					continue;
				}
				for(int k = 1;k <= m;k++)
				{
					if(k == i || k == j)
					{
						continue;
					}
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		while(q--)
		{
			int st, ed;
			cin >> st >> ed;
			cout << dis[st][ed] + w[st] + w[ed] << '\n';
		}
	}
	return 0;
}
/*
d有什么用？
复杂度里肯定有d
md?
 
*/