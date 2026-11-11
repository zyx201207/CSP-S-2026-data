#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10;
int n, m, answer, a[maxn], s[maxn], d[maxn];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf ("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		d[i - 1] = a[i] - a[i - 1];
	}
	s[1] = d[1];
	for (int i = 2; i <= n - 1; i++) {
		s[i] = s[i - 1] + d[i];
	}
	answer = 1;
	int l = 1, r = 1, now = 0;
	while (r <= n && l <= r) {
		int delta = 0;
		if (r < n) {
			delta = (a[r + 1] - a[r]) * (r - l + 1);
		}
		if (r == n) {
			break;
		}
		if (now + delta <= m) {
			now += delta, r++;
			answer = max(answer, r - l + 1);
		}
		else {
			now += delta, r++;
			while (now > m) {
				now -= (s[r - 1] - s[l - 1]), l++;
			}
			answer = max(answer, r - l + 1);
		}
	}
	printf ("%lld\n", answer);
	return 0;
}
/* 
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

老师我想去看更多的色彩
哪怕代价是永远不回来
老师人生的答案太苍白
往后的道路 该怎么期待 
*/