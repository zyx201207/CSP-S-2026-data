#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans = 0, num, md[220000];
char c[220000];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> md[i] >> c[i];
	}
	for (int l = 1, r = n;;) {

		if (md[l] == 0 || md[r] == 0) {
			break;
		}
		num = min(md[l], md[r]);
		if (c[l] != c[r]) {
			ans += num;
		}
		md[l] -= num;
		md[r] -= num;
		if (md[l] <= 0) {
			l++;
		}
		if (md[r] <= 0) {
			r--;
		}
	}
	cout << ans << '\n';
	return 0;
}