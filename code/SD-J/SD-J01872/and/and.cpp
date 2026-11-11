#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, mx = INT_MIN;
int a[N];
int p[N];
bool vis[N];
int num[N];
void dfs(int u, int st)
{
	if (u == m)
	{
		for (int i = 0; i < m; i++) num[i] = p[i];
		int t = a[num[0]];
		for (int i = 1; i < m; i++) t &= a[num[i]];
		if (t > mx) mx = t;
		return;
	}
	for (int i = st; i <= n; i++)
	{
		if (!vis[i])
		{
			p[u] = i;
			vis[i] = true;
			dfs(u + 1, st + 1);
			vis[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(0, 1);
	cout << mx << "\n";
	return 0;
}
