#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for(int i = (a); i <= (b); i ++)
#define DOW(i, a, b) for(int i = (a); i >= (b); i --)
const int N = 5e5 + 5;
int a[N];
int n, m;
bool check(int d) {
	int res = 0;
	REP(i, 1, d) res += a[d] - a[i];
	if(res <= m) return 1;
	REP(i, d + 1, n) {
		res = res - (a[i - 1] - a[i - d]) + (a[i] - a[i - 1]) * d;
		if(res <= m) return 1;
	}
	return 0;
}
void Solve() {
	cin >> n >> m;
	REP(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n, ans = 0;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T = 1;
//	cin >> T;
	while(T --) {
		Solve();
	}
	return 0;
}
