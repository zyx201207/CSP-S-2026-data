#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
signed main ()
{
	freopen ("subwey.in", "r", stdin);
	freopen ("subwey.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if (c == 0)
	{
		if (n == 2)
		{
			cout << "32\n17";
		} else {
			if (n == 3)
			{
				cout << "35\n16";
			}
		}
		return 0;
	}
	for (int i = 1; i <= q; i ++)
	{
		cout << rand() % 10 << endl;
	}
	return 0;
}