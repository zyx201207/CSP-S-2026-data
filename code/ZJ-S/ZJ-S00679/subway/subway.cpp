#include<bits/stdc++.h>
using namespace std;

#define int long long
const int RP = 0x3f3f3f3f;
int c, n, m, d, q;
const int N = 510, M = 5e5 + 10;
int g[N][N];
int w[M];
int k[N];
int s[M];
vector<int> a[M], t[M];

void build()
{
	memset(g, 0x3f, sizeof g);
	for(int i = 1; i <= n; i ++) g[i][i] = 0;
	for(int i = 1; i <= m; i ++)
		for(int j = 1; j <= s[i]; j ++)
			for(int l = 1; l <= s[i]; l ++)
			{
				int x = a[i][j], y = a[i][l];
				g[x][y] = g[y][x] = min(g[x][y], t[i][j] + t[i][l]);
			}
}
void floyd()
{
	for(int l = 1; l <= n; l ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				g[i][j] = min(g[i][j], g[i][l] + g[l][j]);
}
signed main()
{
freopen("subway.in", "r", stdin);
freopen("subway.out", "w", stdout);
ios::sync_with_stdio(false);
cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
	{
		cin >> w[i];
		a[i].push_back(0);
		t[i].push_back(0);
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> k[i];
		int x, y;
		for(int j = 1; j <= k[i]; j ++)
		{
			cin >> x >> y;
			a[x].push_back(i), t[x].push_back(y);
			s[x] ++;
		}
	}
	build();
	floyd();
	while(q --)
	{
		int x, y;
		cin >> x >> y;
		int ans = 0x3f3f3f3f3f3f3f3fll;
		for(int i = 1; i <= s[x]; i ++)
			for(int j = 1; j <= s[y]; j ++)
				ans = min(ans, g[a[x][i]][a[y][j]] + t[x][i] + t[y][j]);
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	
	return 0;
}
