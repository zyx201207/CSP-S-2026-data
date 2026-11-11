#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
#define int long long
int a[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, ans = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--) {
		int sum = 0, cnt = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (sum + (a[i] - a[j]) <= m) {
				sum += (a[i] - a[j]);
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
