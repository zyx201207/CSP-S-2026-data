#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
int main ()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for (int i = 1;i <= t;i++)
	{
		long long n,d,cnt = 0;
		cin >> n >> d;
		for (long long j = 1;j <= n;j++)
		{
			cin >> a[j];
		}
		for (long long j = 1;j < n;j++)
		{
			for (long long k = 1;j + k <= n;k++)
			{
				if (a[j] + d < a[j + k] && a[j] + 2 * d > a[j + k] && (double)(a[j] + a[j + k]) / 2 > d)
				{
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
