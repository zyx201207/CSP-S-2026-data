#include <bits/stdc++.h>
#define endl '\n'
using i32 = int;
using i64 = long long;
void solve();
signed main() {
	std::cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
	while (T--) solve();
}
void solve() {
	i32 n, ans = 0;
	i64 m, c = 0;
	i64 cur = 0;
	std::cin >> n >> m;
	std::vector<i64> a(n + 2, 0);
	for (i32 i = 1; i <= n; i++) std::cin >> a[i];
	std::sort(a.begin() + 1, a.begin() + n + 1);
	cur = 0;
	std::deque<i32> dq;
	for (i32 i = 1; i <= n; i++) {
		c += (i64)dq.size() * (a[i] - cur), cur = a[i];
		while (not dq.empty() and c > m) c -= cur - a[dq.front()], dq.pop_front();
		dq.push_back(i);
		ans = std::max(ans, (i32)dq.size());
	} 
	std::cout << ans << endl;
	return void();
}

// g++ -O2 -std=c++14 -o crystal crystal.cpp && ./crystal && diff crystal.out crystal4.ans