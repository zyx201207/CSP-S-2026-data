#include <bits/stdc++.h>
#define int long long
using namespace std;
int _, n, m, q, a[500005], x, y, f[505][505], ans;
struct T{int x, y;};
vector<T> e[505], e1[500005];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> _ >> n >> m >> _ >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) 
	{
		int k;
		cin >> k;
		while (k--) {cin >> x >> y; e[i].push_back({x, y}), e1[x].push_back({i, y});}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][i] = 0;
	for (int i = 1; i <= n; i++) for (T j : e[i]) for (T k : e1[j.x])
		f[i][k.x] = min(f[i][k.x], j.y + k.y);
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--)
	{
		cin >> x >> y;
		ans = 1e18;
		for (T i : e1[x]) for (T j : e1[y]) ans = min(ans, i.y + j.y + f[i.x][j.x]);
		cout << ans + a[x] + a[y] << '\n';
	}
	return 0;
}
//freopen("
//freeopen("
//froepen("
//freopen("subaway.in",
//freopen("crystel.in",
//来自中原的一群伙伴，结庐东南山~~~
