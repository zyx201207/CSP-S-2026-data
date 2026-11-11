#include <bits/stdc++.h>
using namespace std;
long long a[500010], n, m, d, ans = 0, tot[100010];
bool check()
{
	d = a[2] - a[1];
	for (int i = 3; i <= n; i++)
	{
		if (a[i] - a[i - 1] != d) return false;
	}
	return true;
}
void dfs(int step)
{
	if (step == m)
	{
		long long cur = -1;
		for (int i = 1; i <= n; i++) 
		{
			if (a[i] >= 0) tot[a[i]]++;
			cur = max(cur, a[i]);
		}
		for (int i = 1; i <= cur; i++) 
		{
			ans = max(ans, tot[i]);
			tot[i] = 0;
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		a[i]++;
		dfs(step + 1);
		a[i]--;
	}
}
int main()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (a[1] == a[2])
	{
		if (m == 0) cout << n;
		else cout << n - 1; 
	}
	else if(check())
	{
		if (d < 0) d = -d;
		long long x = m / d, cur = 1, cnt = 0;
		while (cur < n)
		{
			x -= cur;
			if (x < 0) break;
			cnt++;
			cur++;
		}
		if (x > 0 || (x == 0 && m % d != 0)) cout << n - 1;
		else cout << cnt + 1;
	}
	else
	{
		dfs(0);
		cout << ans;
	}
	return 0;
}//1hour 40pts emmm......