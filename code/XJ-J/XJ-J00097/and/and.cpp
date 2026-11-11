#include <bits/stdc++.h>
using namespace std;
const int M = 2 * 1e5 + 20;
int n, m, a[M], sum[M], maxn = -1e9;
int main()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			sum[j] = a[i] & a[i + 1];
			if (sum[j] > maxn)
				maxn = sum[j];
		}
	}
	cout << maxn;
	return 0;
}
