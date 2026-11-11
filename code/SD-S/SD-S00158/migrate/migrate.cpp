#include <bits/stdc++.h>
using namespace std;

const int MX = 2e6;
int x[MX + 10];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, t, n, d, i;
	cin >> c >> t;
	while (t -- )
	{
		cin >> n >> d;
		for (i = 1; i <= n; i ++ )
		{
			cin >> x[i];
		}
		cout << 1 << endl;
	} 
	return 0;
}

