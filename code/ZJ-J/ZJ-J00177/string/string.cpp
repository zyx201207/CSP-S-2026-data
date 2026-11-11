//CCF ±£””Œ“ AC£°£°
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int n;

long long ans = 0;

struct Node
{
	int g;

	char c;
} a[MAXN];

int main ()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].g >> a[i].c;
	}

	int l = 1;

	int r = n;

	while (l <= r)
	{
		if (a[l].c != a[r].c)
		{
			if (a[l].g < a[r].g)
			{
				ans += a[l].g;

				a[r].g -= a[l].g;

				l++;
			}
			else
			{
				ans += a[r].g;

				a[l].g -= a[r].g;

				r--;
			}
		}
		else
		{
			if (a[l].g < a[r].g)
			{
				a[r].g -= a[l].g;

				l++;
			}
			else
			{
				a[l].g -= a[r].g;

				r--;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
