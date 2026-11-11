#include <bits/stdc++.h>
using namespace std;

long long a[200005], v[200005], l[200005], p[200005], ans[200005];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n > 500)
		for (int i = 1; i < n; i++)
			cout << n << '\n';
	else
	{
		for (int k = 1; k <= n; k++)
		{
			long long len = 0;
			memset(v, 0, sizeof(v));
			memset(l, 0, sizeof(l));
			memset(p, 0, sizeof(p));
			for (int i = k; i <= n; i++)
			{
				if (l[a[i]] == 0) 
				{
					l[a[i]] = ++len;
					v[len] = a[i];
				}
				else
				{
					len = l[a[i]];
					v[len] = a[i];
				}
			}
			for (int i = 1; i <= len; i++)
				p[v[i]] = 1;
			for (int i = 1; i <= m; i++)
				ans[i] += p[i];
		}
		for (int i = 1; i <= m; i++)
			cout << ans[i] << " ";
	}
	return 0;
}

