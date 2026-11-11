#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d;
long long x[2000009];
void solvesp1()
{
	long long dis = x[2] - x[1];
	
	if (d < dis)
	{
		cout << 0 << endl;
		return;
	}
	long long jp = d / dis;
	//cout << n << " " << d << " " << dis << " " << jp << endl;
	if (jp == 1)
	{
		cout << 0 << endl;
		return;
	}
	long long ans = n - jp * 2 + 1;
	if (ans < 0)
	{
		ans = 0;
	}
	cout << ans << endl;
	return;
}
int main()
{
	cin.tie(0);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		solvesp1();
		for (int i = 1; i <= n; i++)
		{
			x[i] = 0;
		}
	}
	return 0;
}
