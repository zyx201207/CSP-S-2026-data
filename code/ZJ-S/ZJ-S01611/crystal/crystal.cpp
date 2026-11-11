#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int n, m;
int q[N], hh = 1, tt;
int ans = 1;
int siz()
{
	return tt - hh + 1;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int num = 0;
	for (int i = 2; i <= n; i ++)
	{
		num += (a[i] - a[i - 1]) * siz(); 
		q[++ tt] = i - 1;
		num += a[i] - a[i - 1];
		while (num > m)
		{
			int j = q[hh];
			hh ++;
			num -= (a[i] - a[j]);
		}
		ans = max(ans, siz() + 1);
	}
	cout << ans << "\n";
	return 0;
}
