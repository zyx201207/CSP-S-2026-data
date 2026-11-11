#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 10;

namespace Loop1st {
int n;
ll m, a[N], s[N];
void init() {

}
void Main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int L = 1, R = i - 1;
		while (L < R) {
			int mid = (L + R) >> 1;
			if (s[mid - 1] - a[i] * mid <= m + s[i - 1] - a[i] * i) R = mid;
			else L = mid + 1;
		}
		ans = max(ans, i - L + 1);
	}
	cout << ans << '\n';
}

}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	auto st = clock();
	int C = 0, T = 1;
	// cin >> C >> T;
	while (T--) Loop1st::Main();
	// cerr << fixed << setprecision(10) << "Time = " << 1. * (clock() - st) / CLOCKS_PER_SEC << '\n';
	return 0;
}
