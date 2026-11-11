#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, ans = 0, maxn = 0, maxx;
ll a[100005];
bool cmp(int x, int y)
{
	return x > y;
}
ll check()
{
	ll maxt = -1e18,cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (a[j] == a[i])
			{
				cnt++;
				maxt = max(maxt, cnt);
			}
		}
		cnt = 0;
	}
	return maxt;
}
void print()
{
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return ;
}
void dfs(int step)
{
	if (step > m)
	{
		ans = max(ans, check());
		return;
	}
	for (ll i = 1; i <= n; ++i)
	{
		a[i]++;
		dfs(step + 1);
		a[i]--;
	}
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
