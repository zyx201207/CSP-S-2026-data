#include <bits/stdc++.h>
using namespace std;

int a[200005];
int n, m, maxn = 0;
void dfs(int dep, int cnt, int t)
{
	if(cnt > 0 && t == 0)return;
	if(cnt + n - dep + 1 < m)return;
	if(dep > n)
	{
		maxn = max(maxn, t);
		return;
	}
	if(cnt == 0)dfs(dep + 1, cnt + 1, a[dep]);
	else dfs(dep + 1, cnt + 1, t & a[dep]);
	dfs(dep + 1, cnt, t);
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool f = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(sqrt((a[i] + 1) * (a[i] + 1)) != double(a[i] + 1))f = 0;
	}
		
	if(m == n)
	{
		int ans = a[1];
		for(int i = 2; i <= n; i++)
			ans = ans & a[i];
		cout << ans;
		return 0;
	}
	if(m == 1)
	{
		for(int i = 1; i <= n; i++)
			maxn = max(maxn, a[i]);
		cout << maxn;
	}
	if(m == 2)
	{
		for(int i = 2; i <= n; i++)
		{
			for(int j = 1; j < i; j++)
			{
				maxn = max(maxn, (a[i] & a[j]));
			}
		}
		cout << maxn;
		return 0;
	}
	if(n <= 20)
	{
		dfs(1, 0, 0);
		cout << maxn;
		return 0;
	}
	if(f)
	{
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1];
		return 0;
	}
	cout << 0;
	return 0;
}
