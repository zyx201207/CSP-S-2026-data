// 阮文轩 西北大学附属中学 SN-J00737
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005], d[200005];
int n, m, ans = 0;
void dfs(int pos, int sum, int s)
{
	if (pos > n)
	{
		if (s == m)
			ans = max(ans, sum);
		return;
	}
	dfs(pos + 1, (sum & a[pos]), s + 1);
	dfs(pos + 1, sum, s);
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int f = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		if (a[i] == (i - 1))
			f++;
	if (f == n)
	{
		sort(a + 1, a + n + 1, greater<int>());
		cout << a[m];
		return 0;
	}
	if (m == n)
	{
		int sum = -1;
		for (int i = 1; i <= n; i++)
			sum &= a[i];
		cout << sum;
		return 0;
	}
	if (m == 1)
	{
		int s = 0;
		for (int i = 1; i <= n; i++) s = max(s, a[i]);
		cout << s;
		return 0;
	}
	if (m == 2)
	{
		int s = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i != j)
					s = max(s, (a[i] & a[j]));
			}
		}
		cout << s;
		return 0;
	}
	dfs(1, -1, 0);
	cout << ans;
	return 0;
}
