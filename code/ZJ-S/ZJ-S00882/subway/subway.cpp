#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int re()
{
	char ch = getchar();
	int sum = 0, p = 1;
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0'); ch = getchar();}
	return sum * p;
}
const int N = 505, M = 5e5 + 5, INF = 4e18;
int c, n, m, d, q, w[M], dis[N][N];
vector<pair<int, int> > vec[M];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = re(), n = re(), m = re(), d = re(), q = re();
	for(int i = 1; i <= m; i++) w[i] = re();
	for(int i = 1; i <= n; i++)
	{
		int l = re();
		for(int j = 1; j <= l; j++)
		{
			int x = re(), t = re();
			vec[x].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) dis[i][j] = INF;
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++)
	{
		int len = vec[i].size();
		for(int j = 0; j < len; j++)
		{
			for(int k = j + 1; k < len; k++)
			{
				int JJ1 = vec[i][j].fi, JJ2 = vec[i][j].se;
				int KK1 = vec[i][k].fi, KK2 = vec[i][k].se;
				dis[JJ1][KK1] = dis[KK1][JJ1] = min(dis[JJ1][KK1], JJ2 + KK2);
			}
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--)
	{
		int x = re(), y = re(), ans = INF;
		int l1 = vec[x].size(), l2 = vec[y].size();
		for(int i = 0; i < l1; i++)
		{
			for(int j = 0; j < l2; j++)
			{
				int JJ1 = vec[x][i].fi, JJ2 = vec[x][i].se;
				int KK1 = vec[y][j].fi, KK2 = vec[y][j].se;
				ans = min(ans, dis[JJ1][KK1] + JJ2 + KK2);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
