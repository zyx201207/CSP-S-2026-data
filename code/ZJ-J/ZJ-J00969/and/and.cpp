#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, ans;
int a[maxn];
int sum;
int vis[maxn];

void dfs(int depth, int now)
{
	if (depth == m)
	{
		ans = max(ans, now);
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(depth + 1, (now & a[i]));
			vis[i] = 0;
		}
	}
}

int main()
{
	{;{;{;{;{;
	 /* ohhhh shit ive got no time ahhhhhhhhh */ 
	};};};};};
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum &= a[i];
	}
	if (m == n)
	{
		cout << sum;
		return 0;
	}
	dfs(0, INT_MAX);
	cout << ans;
	return 0;
}
// 1~10 10/20 50pts
