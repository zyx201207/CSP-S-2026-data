#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long n, m, a[N], sum, ans = -2e18;

bool bjt = true;

int main ()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	long long t = a[2] - a[1];
	for (long long i = 3;i <= n;i ++)
	{
		if (a[i] - a[i - 1] != t)
		{
			bjt = false;
			break;
		}
		t = a[i] - a[i - 1];
	}
	if (t == 0)
	{
		cout << n;
		exit (0);
	}
	if (bjt == true)
	{
		sort (a + 1, a + n + 1);
		long long tmp = a[n] - a[n - 1], id, cnt = 1;
		for (long long i = tmp;;i += tmp)
		{
			sum += i;
			if (sum > m)
			{
				id = cnt;
				break;
			}
			cnt ++;
		}
		cout << id;
		return 0;
	}
	sort (a + 1, a + n + 1);
	for (long long i = 1;i <= n;i ++)
	{
		long long bf = m;
		long long l = i - 1, r = i + 1, jsq = 1;
		while (l >= 1 && r <= n && bf > 0)
		{
			if (a[r] - a[i] > a[i] - a[l])
			{
				bf -= (a[i] - a[l]);
				l --;
				jsq ++;
			}
			else if (a[r] - a[i] < a[i] - a[l])
			{
				bf -= (a[r] - a[i]);
				r ++;
				jsq ++;
			}
			else if (a[r] - a[i] == a[i] - a[l])
			{
				while (a[r] - a[i] == a[i] - a[l] && bf > 0 && l >= 1 && r <= n)
				{
					l --;
					bf -= (a[i] - a[l]);
					jsq ++;
					if (bf <= 0) break;
					r ++;
					bf -= (a[r] - a[i]);
					jsq ++;
					if (bf <= 0) break;
				}
			}
		}
		if (bf == 0) ans = max (ans, jsq);
		else ans = max (ans, jsq - 1);
	}
	cout << min (ans, n);
	fclose (stdin);fclose (stdout);
	return 0;
} 