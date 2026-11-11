#include <bits/stdc++.h>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5 + 5;

int n, ans;
ll m, a[N];

int main() {
	assert(freopen("crystal.in", "r", stdin));
	assert(freopen("crystal.out", "w", stdout));
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll s = 0;
	for (int i = 2, j = 1; i <= n; ++i) {
		s += (i - j) * (a[i] - a[i - 1]);
		while (s > m) {
			s -= a[i] - a[j], ++j;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans << "\n";
	return 0;
}
