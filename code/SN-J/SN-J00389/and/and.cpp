#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;

int n, m, cnt[40];
ll a[maxn], ans, pre[maxn], suf[maxn], flag;

vector<int> b[40];

void dfs (int now, int chose, ll val)
{
	//cout << now << ' ' << chose << ' ' << val << '\n';
	if (now > n && chose == m)
	{
		ans = max(ans, val);
		return;
	}
	else if (now > n)
	{
		return;
	}
	if (chose == 0)
	{
		dfs(now + 1, 1, a[now]);
		dfs(now + 1, 0, 0);
	}
	else
	{
		dfs(now + 1, chose + 1, a[now] & val);
		dfs(now + 1, chose, val);
	}
}

ll fal[40];

vector<int> work;

int main ()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	ll maxx = 0, all = 0;
	for (int i = 0; i <= 30; i++) fal[i] = (1 << i) - 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for (int j = 0; j <= 30; j++)
		{
			if (a[i] == fal[j])
			{
				work.push_back(j - 1);
				break;
			}
			if (j == 30) flag = 1;
		}
		if (i == 1)
		{
			all = a[1];
		}
		else
		{
			all &= a[i];
		}
		maxx = max(maxx, a[i]);
	}
	if (n <= 20)
	{
		dfs(1, 0, 0);
		cout << ans;
		return 0;
	}
	if (m == 1)
	{
		cout << maxx;
		return 0;
	}
	if (m == n)
	{
		cout << all;
		return 0;
	}
	if (m == n -1)
	{
		pre[1] = a[1];
		for (int i = 2; i <= n; i++)
		{
			pre[i] = pre[i - 1] & a[i];
		}
		suf[n] = a[n];
		for (int i = n - 1; i >= 1; i--)
		{
			suf[i] = suf[i + 1] & a[i];
		}
		for (int i = 2; i < n; i++)
		{
			ans = max(ans, pre[i - 1] & suf[i + 1]);
		}
		ans = max(ans, pre[n - 1]);
		ans = max(ans, suf[2]);
		cout << ans;
		return 0;
	}
	if (m == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if (flag == 0)
	{
		sort(work.begin(), work.end());
		ll x = work[n - m];
		x++;
		cout << (1 << x) - 1;
		return 0;
	}
	return 0;
}

