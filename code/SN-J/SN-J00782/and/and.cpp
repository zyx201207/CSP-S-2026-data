//SN-J00782 李承欢 西安市铁一中学 
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200100;
int n, m, a[N], t[N];

signed main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		t[i] = 1;
	}
	for (int i = 30; i >= 0; i--) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (!t[j]) {
				continue;
			}
			if (a[j] & (1 << i)) {
				sum++;
			}
		}
		if (sum >= m) {
			for (int j = 1; j <= n; j++) {
				if (!t[j]) {
					continue;
				}
				if (!(a[j] & (1 << i))) {
					t[j] = 0;
				}
			}
		}
	}
	int ans = (1 << 30) - 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!t[i]) {
			continue;
		}
		cnt++;
		ans &= a[i];
		if (cnt == m) {
			break;
		}
	}
	cout << ans;
	return 0;
}
