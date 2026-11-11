#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 5;
long long a[N][40], f[40], g[N];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		long long s;
		cin >> s;
		long long ans = 1;
		while (s != 0) 
		{
			a[i][ans] = s % 2;
			s /= 2;
			ans++;
		}
	}
	for (long long i = 1; i <= n; i++)
	{
		for (long long j = 1; j <= 30; j++)
			f[j] += a[i][j];
	}
	for (long long i = 1; i <= 30; i++)
		if (f[i] >= m) f[i] = 1;
		else f[i] = 0;
	long long s1 = n, s2 = n;
	for (long long i = 30; i >= 1; i--)
		if (f[i])
		{
			for (long long j = 1; j <= n; j++)
				if (g[j] == 0) 
				{
					if (a[j][i] == 0) {g[j] = 2; s1--;}
				}
			if (s1 < m) 
			{
				for (long long j = 1; j <= n; j++)
					if (g[j] == 2) g[j] = 0;
				s1 = s2;
			}
			else
			{
				for (long long j = 1; j <= n; j++)
					if (g[j] == 2) g[j] = 1;
				s2 = s1;
			}
		}
	long long l = INT_MAX;
	for (long long i = 1; i <= n; i++)
		if (g[i] == 0)
		{
			long long po = 1, sum = 0;
			for (long long j = 1; j <= 30; j++)
			{
				sum += a[i][j] * po;
				po *= 2;
			}
			l &= sum;
		}
	cout << l << endl;
	return 0;
}
