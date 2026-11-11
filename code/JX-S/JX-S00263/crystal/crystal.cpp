#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= (r); ++i)
#define req(i, l, r) for (int i = l; i < (r); ++i)
#define per(i, r, l) for (int i = r; i >= (l); --i)
#define qer(i, r, l) for (int i = r; i > (l); --i)
#define eb emplace_back
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n;
ll m, a[N], s[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	int p = 1, ans = 1;
	rep(i, 1, n) {
		while (p < n && (p - i + 2) * a[p + 1] - (s[p + 1] - s[i - 1]) <= m) ++p;
		ans = max(ans, p - i + 1);
	}
	cout << ans;
	return 0;
}
/*
ulimit -s 256000000
g++ -o crystal crystal.cpp -std=c++14 -O2 -static
./crystal
*/