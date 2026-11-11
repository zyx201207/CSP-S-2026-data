#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 10;

ll x[N];
int f[N], g[N], nxt[N], h[N];

void solve()
{
	int n;
	ll d, ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = n, j = n; i >= 1; i--)
	{
		while (x[j] - x[i] > d) j--;
		nxt[i] = j;
	}
	for (int i = 1; i <= n; i++)
	{
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		memset(h, 0, sizeof h);
		for (int k = i, j = 0; ; k = nxt[k], j++)
		{
			h[k] = j;
			if (nxt[k] == k) break;
		}
		for (int k = n; k > i; k--) if (!h[k]) h[k] = h[k + 1];
		f[i] = g[i] = 1;
		for (int k = i + 1, l = 1, r = 1; k <= n; k++)
		{
			while (x[k] - x[l] > d) l++;
			while (h[r + 1] != h[k]) r++;
			if (l > r) break;
			f[k] = g[r] - g[l - 1];
			g[k] = g[k - 1] + f[k];
		}
		for (int k = i + 1; k <= n; k++)
			ans += (f[k] == 2);
	}
	cout << ans << "\n";
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c, T;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}

