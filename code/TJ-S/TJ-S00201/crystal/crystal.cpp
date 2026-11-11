#include<bits/stdc++.h>

using namespace std;
#define int long long

int n, m, a[500001], ans, b[500001], l = 0;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		while((b[i] - l * (a[i] - a[l]) - b[l]) > m) l++;
		ans = max(i - l, ans);
	}
	cout << ans;
	return 0;
 } 
