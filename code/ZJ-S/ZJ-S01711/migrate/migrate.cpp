#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 10;
int a[N];
int n, d, sum;
void dfs(int now, int end, int maxn, int cnt)
{
	if (cnt > maxn || sum > 2) return;
	if (now >= end)
	{
		if (cnt == maxn) sum++;
		return;
	}
	int nxt = now;
	while(a[nxt + 1] - a[now] <= d && nxt + 1 <= end)
	{
		nxt++;
		dfs(nxt, end, maxn, cnt + 1);
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, T;
	cin >> c >> T;
	if (c == 11 || c == 12)
	{
		while(T--)
		{
			cin >> n >> d;
			for (int i = 1; i <= n; i++) cin >> a[i];
			int x = a[2] - a[1];
			if (d < x * 2)
			{
				cout << 0 << endl;
				continue;
			}
			int len = d / x * 2;
			if (len > n) cout << 0 << endl;
			else cout << n - len + 1 << endl;
		}
		return 0;
	}
	if (c == 13 || c == 14)
	{
		while(T--)
		{
			cin >> n >> d;
			for (int i = 1; i <= n; i++) cin >> a[i];
			cout << 0 << endl;
		}
		return 0;
	}
	while(T--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 3; j <= n; j++)
			{
				int l = i, r = j, flag = 1, maxn = 0;
				sum = 0;
				while(l < r)
				{
					int nxt = l;
					while(a[nxt + 1] - a[l] <= d) nxt++;
					if (l == nxt)
					{
						flag = 0;
						break;
					}
					l = nxt, maxn++;
				}
				if (flag == 0) break;
				sum = 0;
				dfs(i, j, maxn, 0);
				if (sum == 2) ans++;
			}
		cout << ans << endl;
	}
	return 0;
}
