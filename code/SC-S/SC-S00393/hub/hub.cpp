#include <bits/stdc++.h>
using std::cin; using std::cout;
using std::max; using std::min;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
int n, k;
void Solve() {
	cin >> n >> k;
	int ans1 = ceil((n - k) / 2);
	int ans2 = ceil((n - k) / 3);
	cout << min(ans1, ans2) << '\n';
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c, t; cin >>c >> t;
	while (t--) {
		Solve();
	}
	return 0;
}