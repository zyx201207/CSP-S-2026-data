#include <bits/stdc++.h>
using namespace std;
bool k[200005];
int n, m, a[200005];
int ma = -1;
void dfs (int x, int t, int f)
{
	if (t >= m)
	{
		ma = max((f & x), ma);
		return ;
	}
	f = f & x;
	for (int i = 1;i <= n;i++)
	{
		if (k[i] == 0)
		{
			k[i] = 1;
			dfs(a[i], t + 1, f);
			k[i] = 0;
		}
	}
	return ;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out","w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		k[i] = 1;
		dfs(a[i], 1, a[i]);
		k[i] = 0;
	}
	cout << ma;
	return 0;
}
