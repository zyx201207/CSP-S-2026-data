//CCF ±£””Œ“ AC£°£°
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int n;

int m;

int ans;

int a[MAXN];

void worm ();

int main ()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	worm ();

	cout << ans << "\n";

	return 0;
}

void worm ()
{
	for (int i = 30; i >= 0; i--)
	{
		int tp = ans | (1 << i);

		int ct = 0;

		for (int j = 1; j <= n; j++)
		{
			((a[j] & tp) == tp) ? ct++ :ct = ct;
		}

		(ct >= m) ? ans |= (1 << i) : ans = ans;
	}
}
