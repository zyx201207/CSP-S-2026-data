#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, inf = 1e18;
int a[N],h[N],n,m,ans;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) h[i] = h[i-1] + a[i];
	int p = 0;
	for (int i = 1; i <= n; i++) {
		while (a[i] * (i - p) - (h[i] - h[p]) > m) p++;
		ans = max(ans, i - p);
	}
	cout << ans;
	return 0;
}

