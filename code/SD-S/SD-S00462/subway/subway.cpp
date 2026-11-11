#include <bits/stdc++.h>
#define pa pair<int,int>
using namespace std;

const int N = 505, M = 500005;
int c, n, m, d, q, X, Y;
//int a[N][M], t[N][M];
int w[N], f[M], k[M];
map<int,int> a[N], t[N];
vector<pair<int,int> > s[M];

int dfs(int i, int j, int fi, int fj)
{
	if (a[i][j] == Y)
	{
		return t[i][j];
	}
	if (a[i][j] == 0)
	{
		return 0x3f3f3f3f;
	}
	
	int u = a[i][j], ans = 0x3f3f3f3f;
	for (int w = 0; w < s[u].size(); w++)
	{
		int x = s[u][w].first, y = s[u][w].second;
		if (x == fi && y + 1 == fj) continue;
		if (x == i) ans = min(ans, dfs(x, y+1, i, j));
		else ans = min(ans, dfs(x, y+1, i, j)  + t[i][j] + t[x][y] );
		if (x == fi && y - 1 == fj) continue;
		if (x == i) ans = min(ans, dfs(x, y-1, i, j));
		else ans = min(ans, dfs(x, y-1, i, j)  + t[i][j] + t[x][y] );
	}
	return ans;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			pair<int,int> p;
			p.first = i, p.second = j;
			s[a[i][j]].push_back(p);
		}
	}
	
	while (q--)
	{
		cin >> X >> Y;
//		cout << "q" << q;
		int ans = 0x3f3f3f3f;
		for (int w = 0; w < s[X].size(); w++)
		{
			int i = s[X][w].first, j = s[X][w].second;
			
			ans = min(ans, dfs(i, j, 0, 0));
		}
		cout << ans << '\n';
	}
}

