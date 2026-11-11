#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 5e5 + 10;

std::mt19937_64 rnd(time(0));

i64 myrand (i64 l, i64 r) {
	return rnd() % (r - l + 1) + l;
}

int n;
int ans;

i64 m;
i64 a[N], p[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.in", "w", stdout);

	n = 5e5, m = 1e18;
	std::cout << n << ' ' << m << std::endl;
	for (int i = 1; i <= n; ++i) std::cout << myrand(1, 1e12) << ' ';

	return 0;
}