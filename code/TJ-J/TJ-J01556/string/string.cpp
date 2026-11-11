#include <bits/stdc++.h>
using namespace std;
long long n, sum = 0, x, ans, s1, s2, r, nx, nx1, bj;
bool f;
char c, nc, nc1;

struct node {
	long long w;
	char s;
};
node a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	r = n + 1;
	for (int i = 1; i <= n; i++) {
		cin >> x >> c;
		a[i].w = x;
		a[i].s = c;
		sum += x;
	}
	for (int i = 1; i <= n + 1; i++) {
		if (f) {
			nx1 = a[i].w;
			nc1 = a[i].s;
			a[i].w = nx;
			a[i].s = nc;
			nc = nc1;
			nx = nx1;
		} else {
			if (s1 + a[i].w > (sum / 2)) {
				if (sum & 1) {
					nx = a[i].w + s1 - sum / 2 - 1;
					a[i].w = sum / 2 - s1;
					nc = a[i].s;
				} else {
					nx = a[i].w + s1 - sum / 2;
					a[i].w = sum / 2 - s1;
					nc = a[i].s;
				}
				f = 1;
				bj = i;
			} else {
				s1 += a[i].w;
			}
		}
	}
	for (int i = 1; i <= bj; i++) {
		while (a[i].w > 0) {
			if (a[i].s == a[r].s) {
				if (a[i].w < a[r].w) {
					a[r].w = a[r].w - a[i].w;
					a[i].w = 0;
					break;
				} else {
					a[i].w = a[i].w - a[r].w;
					r--;
				}
			} else {
				if (a[i].w < a[r].w) {
					a[r].w = a[r].w - a[i].w;
					ans += a[i].w;
					a[i].w = 0;
					break;
				} else {
					a[i].w = a[i].w - a[r].w;
					ans += a[r].w;
					r--;
				}
			}
		}
	}
	cout << ans;
	return 0;
}