/*

	rating: 1300
	bad
	
	extremely traditional codeforces-style problem (and will definitely be rejected by the coordinators in 2026),
	what do you mean???

*/

#include <bits/stdc++.h>

int a[200005], m, n;
int b[200005], cnt = 0, tmp[200005], tmp_cnt;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	int ans = 0;
	cnt = n;
	for (int i = 29; i >= 0; --i) {
		int one_cnt = 0;
		for (int j = 1; j <= cnt; ++j) {
			if ((b[j] >> i) & 1) {
				++one_cnt;
			}
		}
		if (one_cnt >= m) {
			ans ^= (1 << i);
			tmp_cnt = 0;
			for (int j = 1; j <= cnt; ++j) {
				if ((b[j] >> i) & 1) {
					tmp[++tmp_cnt] = b[j];
				}
			}
			cnt = tmp_cnt;
			for (int j = 1; j <= cnt; ++j) {
				b[j] = tmp[j];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
