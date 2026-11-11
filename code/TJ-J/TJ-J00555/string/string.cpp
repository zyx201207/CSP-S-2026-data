/*

	rating: 1100
	
	a leetcode-style problem, but ok for CSP-J T2

*/

#include <bits/stdc++.h>

int n, a[200005], c[200005];
char str[20];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%s", &a[i], str + 1);
		c[i] = str[1] - 'a';
	}
	long long ans = 0;
	int l_ptr = 1, r_ptr = n, l_left = a[1], r_left = a[n];
	while (true) {
		if (l_ptr == n + 1 || r_ptr == 0) {
			break;
		}
		int parse = std::min(l_left, r_left);
		if (c[l_ptr] != c[r_ptr]) {
			ans += 1ll * parse; 
		}
		l_left -= parse;
		r_left -= parse;
		if (l_left == 0) {
			++l_ptr;
			l_left = a[l_ptr];
		}
		if (r_left == 0) {
			--r_ptr;
			r_left = a[r_ptr];
		}
	}
	printf("%lld\n", ans >> 1);
	return 0;
}
