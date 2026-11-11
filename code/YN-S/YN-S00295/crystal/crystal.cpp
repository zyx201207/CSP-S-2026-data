#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long LL;
const int N = 1e6 + 5;

namespace problem {

bool BEgin;
LL n, m;
LL a[N];
bool ENd;
void solve() {
	std::cerr << (&BEgin - &ENd) / 1024 / 1024 << "\n";
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	LL cnt = 1;
	for (LL l = 1, r = 1; l <= n; l++) {
		while (r < n && m >= (r - l + 1) * (a[r + 1] - a[r])) {
			m -= (r - l + 1) * (a[r + 1] - a[r]);
			r++;
		}
		cnt = std::max(cnt, r - l + 1);
		m += a[r] - a[l];
	}
	std::cout << cnt << "\n";
}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	problem::solve();
	return 0;
}
/*
3 1
1 100 101
*/