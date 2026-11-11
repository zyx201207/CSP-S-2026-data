#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 10;
int n;
ll a[N], d[N], p[N], m, ans; // diff, prefix
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i]; 
	sort(a+1, a+n+1);
	ll l = 1, r = 0, s = 0; // 把 [l, r] 全部转化为 a_r 
	while (l <= ++r && r <= n) {
//		cerr << "#(Before) l: " << l << ", r: " << r << "\n";
		s += (r-l) * (a[r]-a[r-1]);
//		cerr << "# s is: " << s << "\n";
		while (s > m && l <= r) s -= (a[r] - a[l++]);
//		cerr << "#(After) l: " << l << ", r: " << r << "\n";
		ans = max(r-l+1, ans);
//		cerr << "Updated: ans: " << ans << "\n";
	}
	cout << ans << "\n";
	return 0;
} 
