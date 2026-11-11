#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], cnt[5], ans;

void dfs(int step, int cnt, int sum)
{
	if (n - step + 1 < m - cnt) return ;
	if (cnt == m)
	{
		ans = max(ans, sum);
		return ;
	}
	if (step > n)
	{
		return ;
	}
	dfs(step + 1, cnt, sum);
	dfs(step + 1, cnt + 1, sum & a[step]);
}

void solve1()
{
	dfs(1, 0, 2097151);
	cout << ans << endl;
}

void solve2()
{
	if (m == 1)
	{
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			maxn = max(maxn, a[i]);
		}
		cout << maxn << endl;
	}
	else if (m == 2)
	{
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				maxn = max(maxn, (a[i] & a[j]));
			}
		}
		cout << maxn << endl;
	}
	else 
	{
		ans = a[1];
		for (int i = 2; i <= n; i++)
		{
			ans = (ans & a[i]);
		}
		cout << ans << endl;
	}
}

void solve3()
{
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i]]++;
	}
	if (cnt[3] >= m) cout << 3 << endl;
	else if (cnt[2] + cnt[3] >= m) cout << 2 << endl;
	else if (cnt[1] + cnt[3] >= m) cout << 1 << endl;
	else cout << 0 << endl;
}

void solve4()
{
	int n1 = n;
	while (n1)
	{
		n1 /= 2;
		if (m > n1) break;
		ans += n1;
	}
	cout << ans << endl;
}

bool cmp(int x, int y)
{
	return x > y;
}

void solve5()
{
	sort(a + 1, a + n + 1, cmp);
	ans = a[1];
	for (int i = 2; i <= m; i++)
	{
		ans = (ans & a[i]);
	}
	cout << ans << endl;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	bool f = true, f2 = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] >= 4) f = false;
		if (a[i] != i - 1) f2 = false;
	}
	if (n <= 20)
	{
		solve1();
	} 
	else if (n <= 2000)
	{
		solve2();
	}
	else
	{
		if (f) solve3();
		else if (f2) solve4();
		else solve5();
	}
	return 0;
}
