#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005], l[300005];
bool w[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	memset(w, false, sizeof(w));
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		memset(w, false, sizeof(w));
		int k = 0;
		for (int j = i; j <= n; j++)
		{
			if (w[a[j]] == true)
			{
				do
				{
					w[l[k]] = false;
					k--;
				}
				while (l[k] != a[j]);
			}
			l[++k] = a[j], w[a[j]] = true;
		}
		for (int j = 1; j <= m; j++)
			if (w[j] == true)
				ans[j]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}

