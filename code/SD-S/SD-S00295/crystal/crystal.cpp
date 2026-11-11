#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

namespace PTqwq {
	
i64 readqwq() {
	i64 x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

const int N = 5e5 + 50;

i64 n, m, a[N], b[N];

i64 query(i64 l, i64 r) {
	return b[r] - b[l - 1];
}

void Solve() {
	n = readqwq();
	m = readqwq();
	for (i64 i = 1; i <= n; ++ i) {
		a[i] = readqwq();
	}
	sort(a + 1, a + 1 + n);
	b[0] = 0;
	for (i64 i = 1; i <= n; ++ i) {
		b[i] = b[i - 1] + a[i];
	}
	i64 ans = 0;
	for (i64 i = 1; i <= n; ++ i) {
		i64 L = 1, R = i;
		while (L <= R) {
			i64 mid = (L + R) / 2;
			if (a[i] * mid - query(i - mid + 1, i) <= m) {
				ans = max(ans, mid);
				L = mid + 1;
			} else {
				R = mid - 1;
			}
		}
	}
	printf("%lld\n", ans);
}
	
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	PTqwq::Solve();
	
	return 0;
}
