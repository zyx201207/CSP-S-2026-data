#include <bits/stdc++.h>
using namespace std;

long long a[200005], maxnn = LONG_MIN;
int check(long long n)
{
	int f = 0;
	for (int i = 2; i <= pow(2, 25); i *= 2)
		if (n == i - 1)
		{
			f = 1;
			break;
		}
	return f;
}
void dfs(int dep, long long c, long long n, long long x, long long m)
{
	if (dep > n)
	{
		 if (x == m) maxnn = max(maxnn, c);
		return;
	} 
	dfs(dep + 1, c, n, x, m);
	dfs(dep + 1, c & a[dep], n, x + 1, m);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, f = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];	
		if (f && f < 6)
		{
			if (check(a[i])) f++;
			else f = 0;
			if (f == 5) f = 10;
		}
	} 
	if (f == 1)
	{
		sort (a + 1, a + n + 1);
		long long ans = a[n];
		for (int i = 1; i <= m; i++)
			ans &= a[n - i + 1];
		cout << ans << '\n';
	}
	else if (m == 1)
	{
		long long maxn = LONG_MIN;
		for (int i = 1; i <= n; i++)
			maxn = max(a[i], maxn);
		cout << maxn << '\n';
	}
	else if (m == n || m == n - 1)
	{
		long long ans = a[1];
		for (int i = 2; i <= n; i++)
			ans &= a[i];
		if (m == n) cout << ans << '\n';
		else
		{
			long long maxn = LONG_MIN;
			for (int i = 1; i <= n; i++)
				maxn = max(maxn, ans | a[i]);
			cout << maxn << '\n';
		}
	}
	else 
	{
		for (int i = 1; i <= n - m + 1; i++)
			dfs(i, a[i], n, 0, m);
		cout << maxnn << '\n';
	}
	return 0;
}
