#include<bits/stdc++.h>
using namespace std;
#define N 500011
#define int long long
int n, m; 
int a[N], b[N], ans;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		while (a[i] * (i - p + 1) - (b[i] - b[p - 1]) > m)
			p++;
		ans = max(ans, i - p + 1);
	}
	cout << ans;
	return 0;
}

