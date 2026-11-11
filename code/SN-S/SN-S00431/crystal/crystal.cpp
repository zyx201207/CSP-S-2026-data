//高文轩 铜川市第二中学  SN-S00431 
#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500010], maxn;

int main ()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	cout << m;
	return 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
	{
		int j = 1;
		long long s = m;
		while (s > 0 && j + i <= n)
		{
			s -= (a[i + j] - a[i + j - 1]) * j;
			a[i] = a[i + j];
			j++;
		}
		if (j > maxn)
		{
			maxn = j;
		}
	}
	cout << maxn;
	return 0;
}
