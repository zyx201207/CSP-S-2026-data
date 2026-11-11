#include <bits/stdc++.h>
using namespace std;
int maxx, sum, n, m, a[500001], ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum = 1, ans = m;
		for (int j = i - 1; j >= 1; j--)
		{
			if (a[i] - a[j] <= ans)
			{
				sum++, ans -= a[i] - a[j];
			}
			else
			{
				break;
			}
		}
		maxx = max(maxx, sum);
	}
	cout << maxx;
	return 0;
}
