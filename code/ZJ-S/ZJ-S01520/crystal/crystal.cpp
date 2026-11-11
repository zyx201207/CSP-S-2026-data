#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];
int ans = 1;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int h = 1, t = 1, cost = 0;
	while(h >= t && h <= n)
	{
		while(m - cost >= (a[h + 1] - a[h]) * (h - t + 1) && h < n) cost += (a[h + 1] - a[h]) * (h - t + 1), h ++;
		ans = max(ans, h - t + 1);
		if(t == h) h ++, cost = 0;
		else cost -= a[h] - a[t];
		t ++;
	}
	cout << ans << endl;
	return 0;
}
