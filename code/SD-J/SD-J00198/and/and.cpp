#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;
int a[MX + 10];
bool vis[MX + 10];
int n, m, ans;

void dfs(int x, int k)
{
	int tot, i;
	bool f;
	if (k == m)
	{
		f = false;
		for (i = 1; i <= n; i ++ )
		{
			if (vis[i])
			{
				if (!f)
				{
					tot = a[i];
					f = true;
				}
				else
				{
					tot &= a[i];
				}
			}
		}
		cout << endl;
		ans = max(ans, tot);
		return ;
	}
	for (i = x + 1; i <= n; i ++ )
	{
		if (!vis[i])
		{
			vis[i] = true;
			dfs(i, k + 1);
			vis[i] = false;
		}
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i, cnt1 = 0, cnt2 = 0;
	bool f1 = true, f2 = true;
	cin >> n >> m;
	ans = 0;
	for (i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		if (ceil(1.0 * log2(1.0 * (a[i] + 1))) != log2(a[i] + 1))
		{
			f1 = false;
		}
		if (a[i] != i - 1)
		{
			f2 = false;
		} 
	}
	sort (a + 1, a + n + 1);
	if (m == 1 || a[n - m + 1] == a[n])
	{
		cout << a[n] << '\n';
		return 0;
	}
	if (m == n)
	{
		for (i = 1; i <= n; i ++ )
		{
			ans &= a[i];
		}
		cout << ans << '\n';
		return 0;
	}
	if (f1 == true)
	{
		cout << a[n - m + 1] << '\n';
		return 0;
	}
	if (ceil(1.0 * log2(1.0 * n)) == log2(n) && f2 == true)
	{
		cout << n - m << '\n';
		return 0;
	}
	if (a[n] <= 4)
	{
		for (i = 1; i <= n; i ++ )
		{
			if (a[i] == 3)
			{
				cnt1 ++ ; 
			}
			if (a[i] == 2)
			{
				cnt2 ++ ;
			}
		}
		if (cnt1 >= m)
		{
			cout << 3 << endl;
		}
		else if (cnt1 + cnt2 >= m)
		{
			cout << 2 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
		return 0;
	}
	for (i = 1; i <= n - m + 1; i ++ )
	{
		vis[i] = true;
		dfs(i, 1);
		vis[i] = false;
	}
	cout << ans << '\n';
	return 0;
}
