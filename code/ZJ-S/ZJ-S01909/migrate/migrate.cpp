#include <bits/stdc++.h>
using namespace std;
int c, n;
void solved()
{
	int d, sj = 0;
	cin >> d;
	const int N = n;
	int x[N], a;
	x[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	a = x[n] - x[n - 1];
	if (a <= d)
	{
		int m = d * 2 - 1;
		for (int i = 1; i <= n; i++)
		{
			if (x[i] + m <= x[n]) sj++;
		}
		cout << sj << endl;
	}
	else
	{
		cout << 0 << endl;
		return;
	}
}
void solve()
{
	int d, sj = 0;
	cin >> d;
	const int N = n;
	int x[N], a[N];
	x[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		a[i] = x[i] - x[i - 1];
	}
	a[1] = 0;
	int l = 2, r = 4, m = d * 2 - 1, ssj = 0;
	while (r <= n)
	{
		int ww = 0;
		for (int i = l; i <= r; i++)
		{
			ww += a[i];
			if (a[i] >= d)
			{
				l++; r++;
				break;
			}
			else
			{
				if (a[r] == a[l] && a[r] >= a[l + 1])
				{
					ssj++;
					break;
				}
			}
		}
		ww = 0;
		sj = max(sj, ssj);
		l = r;
		r = l + 2;
	}
	cout << sj << endl;
	return 0;
}
int main()
{
	freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	int t;
	cin >> c >> t;
	if (c == 11 || c == 12)
	{
		while (t--)
		{
			cin >> n;
			if (n <= 3)
			{
				cout << 0 << endl;
				continue;
			}
			cout << "?" << endl;
			solved();
		}
		return 0;
	}
	while (t--)
	{
		cin >> n;
		if (n <= 3)
		{
			continue;
		}
		solve();
	}
	return 0;
}
