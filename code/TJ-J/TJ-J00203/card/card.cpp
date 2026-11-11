#include <bits/stdc++.h>
using namespace std;

int b[300010], a[500010], c[300010], ans[300010];
int n, m;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	
	int tot = 0;
	for (int i = n-1; i >= 0 && tot < m; i--)
	{
		if (b[a[i]])
		{
			c[a[i]] = i;
			ans[a[i]] += b[a[i]];
			for (int j = i; j < n-1;)
			{
				j++;
				j = c[a[j]];
				ans[a[j]] += b[a[i]];
			}
			b[a[i]] = 0;
			tot++;
		}
	}
	
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	
	return 0;
}
