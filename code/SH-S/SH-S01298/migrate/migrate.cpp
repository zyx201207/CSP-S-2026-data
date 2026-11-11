#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;

int c, t, n, d, cnt;
int w[N];
int q[N], hh, tt;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		int k = 0;
		cin >> n >> d;
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (w[i] - w[1] <= d && w[n] - w[i] <= d)
			{
				k = i;
				cnt++;
			}
		}
		if (cnt <= 1 || cnt >= 3)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << (n - k) * (k - 2) << endl;
		}
	}
	return 0;
} 
