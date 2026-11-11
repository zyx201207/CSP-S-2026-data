#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];

int kthbit(int n, int k) { return (n >> k) & 1; }

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("and.in", "r", stdin); freopen("and.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	int t = n;
	for (int i = 31;i >= 0;i--) {
		int cnt = 0;
		for (int j = 1;j <= t;j++) {
			if (kthbit(a[j], i)) cnt++;
		}
		if (cnt >= k) {
			for (int j = 1, k4 = 1;j <= t;j++) {
				if (kthbit(a[j], i)) a[k4++] = a[j];
			}
			t = cnt;
		}
	}
	int ans = 0xffffffff;
	for (int i = 1;i <= k;i++) ans &= a[i];
	cout << ans;
	return 0;
}
