#include <bits/stdc++.h>
using namespace std;
int a[2000010], n, d;
int main()
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int cnt = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (n <= 3) 
		{
			cout << 0;
			continue;
		}
		for (int i = 4; i <= n; i++)
		{
			if (a[i] - a[i - 3] > d) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}