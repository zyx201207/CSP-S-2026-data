// subway

#include <bits/stdc++.h>

#define int long long
#define pii pair <int, int>

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;

inline int read()
{
	int  absl = 0;
	bool sign = 0;
	char temp = getchar();
	for (; !isdigit(temp); temp = getchar()) sign ^= (temp == '-');
	for (;  isdigit(temp); temp = getchar()) absl = absl * 10 + temp - '0';
	return sign ? - absl : absl;
}

const int N = 505;
const int M = 5e5 + 5;

int c, n, m, d, q;
int a[M];

vector <pii> t[M];

int g[N][N];

signed main()
{
	freopen("subway.in" , "r", stdin );
	freopen("subway.out", "w", stdout);
	
	memset(g, 0x3f, sizeof(g));
	
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	
	for (int i = 1; i <= m; i ++) a[i] = read();
	for (int i = 1; i <= n; i ++)
	{
		g[i][i] = 0;
		int k = read();
		for (int j = 1; j <= k; j ++)
		{
			int tmpa = read();
			int tmpt = read();
			t[tmpa].push_back(make_pair(i, tmpt));
		}
	}
	for (int i = 1; i <= m; i ++)
		for (int j = 0; j < t[i].size(); j ++)
			for (int k = 0; k < t[i].size(); k ++)
			{
				int u = t[i][j].first, wu = t[i][j].second;
				int v = t[i][k].first, wv = t[i][k].second;
				g[u][v] = min(g[u][v], wu + wv);
			}
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	for (int i = 1; i <= q; i ++)
	{
		int x = read();
		int y = read(), s = INF;
		for (int j = 0; j < t[x].size(); j ++)
			for (int k = 0; k < t[y].size(); k ++)
			{
				int u = t[x][j].first, wu = t[x][j].second;
				int v = t[y][k].first, wv = t[y][k].second;
				s = min(s, g[u][v] + wu + wv);
			}
		printf("%lld\n", s + a[x] + a[y]);
	}
	
	
	return 0;
}
