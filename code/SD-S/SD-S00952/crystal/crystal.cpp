#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int SIZE = 5e5 + 5;
int n, m, a[SIZE], sum[SIZE], ans;
void _main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	a[n + 1] = 1e13;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++){
		if (a[i] == a[i + 1])continue;
		int l = 1, r = i;
		while (l < r){
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) > m)l = mid + 1;
			else r = mid;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return;
} 
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	while (t--){
		_main();
	}
}
