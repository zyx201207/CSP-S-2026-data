#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second
#define y1 csps300
#define stp(x) fixed << setprecision(x)

using namespace std;

const int N = 5e5 + 50, p = 998244353, inf = 1 << 29;

int n;
ll m, a[N], s[N];

void init() {
	
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int L = 0, R = i;
		while (L + 1 < R) {
			int mid = (L + R) / 2;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) 
				R = mid;
			else L = mid;
		}
		ans = max(ans, i - R + 1);
	}
	cout << ans << endl;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}