#include <bits/stdc++.h>
using namespace std;
int a[200000], n, m;
int dfs(int lst, int cnt, int v)
{
	if (cnt == m)
		return v;
	int res = 0;
	for (int i = lst; i < n; i++)
		res = max(res, dfs(i + 1, cnt + 1, v & a[i]));
	return res;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n <= 2000)
		cout << dfs(0, 0, INT_MAX);
	else
	{
		int minn = INT_MAX;
		for (int i = 0; i < n; i++)
			minn = min(minn, a[i]);
		cout << minn;
	}
}
