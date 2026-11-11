#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
map<int, bool> mp;
int ans;
inline void dfs(int x, int tot, int cnt)
{
	if (n - x + 1 < m - tot) return;
	if (tot > 0 && cnt <= ans) return;
	if (x > n)
	{
		if (tot == m) ans = max(ans, cnt);
		return;
	}
	dfs(x + 1, tot, cnt);
	if (tot < m)
	{
		if (tot == 0) dfs(x + 1, tot + 1, a[x]);
		else dfs(x + 1, tot + 1, cnt & a[x]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for (int i = 0; i <= 30; i++)
	{
		mp[1<<i] = true;
	}
	cin >> n >> m;
	bool flag = true;
	bool qq = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (flag) if (!mp[a[i] + 1]) flag = false;
		if (a[i] > 3) qq = false;
	}
	sort(a + 1, a + n + 1);
	if (flag)
	{
		cout << a[n - m + 1];
		return 0;
	}
	if (m == n)
	{
		int res = a[1];
		for (int i = 1; i <= n; i++)
		{
			res &= a[i];
		}
		cout << res;
		return 0;
	}
	if (m == 1)
	{
		cout << a[n];
		return 0;
	}
	if (qq)
	{
		int p[4] = {0, 0, 0, 0};
		for (int i = 1; i <= n; i++)
		{
			p[a[i]]++;
		}
		if (m <= p[3]) cout << 3;
		else if (m <= p[3] + p[2]) cout << 2;
		else if (m <= p[3] + p[1]) cout << 1;
		else cout << 0;
		return 0;
	}
	if (n > 2000)
	{
		cout << a[n - m + 1];
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}