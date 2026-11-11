#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int b[500005];
int ans[300005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int tot = 0;
		for (int j = i; j <= n; j++)
		{
			for (int k = 1; k <= tot; k++)
			{
				if (b[k] == a[j])
				{
					tot = k - 1;
					break;
				}
			}
			tot++;
			b[tot] = a[j];
		}
		for (int j = 1; j <= tot; j++)
		{
			ans[b[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}