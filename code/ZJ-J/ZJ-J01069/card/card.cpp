#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int x, y, p, a[500010], l1[500010], l2[500010], ans[300010];

long long read() {
	char ch = getchar();
	long long num = 0;
	bool p = 1;
	if (isdigit(ch)) {
		num = ch - '0';
	} else {
		p = -1;
	}
	while (true) {
		ch = getchar();
		if (!isdigit(ch)) {
			return num * p;
		} else {
			num = num * 10 + ch - '0';
		}
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read();
	m = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
		l2[a[i]] = l1[a[i]];
		l1[a[i]] = i;
		c = max(a[i] - a[i - 1], c);
	}
	if (c <= 1) {
		for (int i = n; i >= 1; i --) {
			for (int k = n; k >= i; k --) {
			if (a[k] == a[k - 1]) {
				for (int j = i + 1; j <= n; j ++) {
					ans[j] ++;
				}
			}
			}
		}
		for (int i = 1; i <= m; i ++) {
			cout << ans[i] << ' ';
		}
		return 0;
	}
	for (int i = n; i >= 1; i --) {
		p = i;
		for (int j = m; j >= p; j --) {
			x = l1[a[i]];
			y = l2[a[i]];
			if (p <= x) {
				p = max(p, x);
			}
		}
		for (int j = p ; j <= n; j ++) {
			ans[a[j]] ++;
		}
		cout << '\n';
	}
	for (int i = 1; i <= m; i ++) {
	}
	return 0;
} //      10 3 3 1 2 1 3 2 3 1 2 1
