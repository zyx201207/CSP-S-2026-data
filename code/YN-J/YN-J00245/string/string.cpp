// c - j - c 2026 10 31 csp T2
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, tot, cnt;
long long siz;

struct node {
	long long s;
	char c;
} a[N];

int main(void) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long x;
		char c;
		cin >> x >> c;
		siz += x;
		if (c != a[tot].c) {
			a[++tot].c = c;
			a[tot].s = x;
		} else {
			a[tot].s += x;
		}
	}
	int i = 1, j = tot;
	long long l = 0, r = 0, res = 0;
	bool f1 = 0, f2 = 0;
	while (i < j) {
		if (!f1)
			l += a[i].s, f1 = 1;
		if (!f2)
			r += a[j].s, f2 = 1;
		if (a[i].c != a[j].c) {
			if (l <= r)
				res += a[i].s;
			else
				res += a[j].s;
		}
		if (l <= r) {
			a[j].s -= a[i].s;
			if (a[j].s < 0)
				j--, f2 = 0;
			i++, f1 = 0;
		} else {
			a[i].s -= a[j].s;
			if (a[i].s < 0)
				i++, f2 = 0;
			j--, f2 = 0;
		}
	}
	cout << res;
	return 0;
}