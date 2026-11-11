#include <bits/stdc++.h>
using namespace std;

long long ccccc, T;
long long n, d;
long long a[2000005];
long long c[2000005];
long long s[2000005];
long long p[2000005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> ccccc >> T;
	while (T--)
	{
		cin >> n >> d;
		for (long long i = 1; i <= n; i++)
			cin >> a[i], s[i] = 0, c[i] = 0, p[i] = INT_MAX;
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			c[i] = 1;
			p[i] = 0;
			for(int j = i + 1; j <= n; j++)
				p[j] = INT_MAX;
			for(int j = i; j <= n; j++)
			{
				for (int k = j - 1; k >= i; k--)
				{
					if (a[j] - a[k] > d)
						break;
					if (p[k] + 1 < p[j])
						p[j] = p[k] + 1, c[j] = c[k];
					else
						if (p[k] + 1 == p[j])
							c[j] += c[k];
				}
				if (c[j] == 2)
					ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}