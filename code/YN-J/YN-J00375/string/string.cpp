#include <bits/stdc++.h>
using namespace std;
long long n, a, b = 1, t1, t2, cnt;
char ch;

struct qian {
	long long l, r, len;
	char c;
} x[200010];

struct hou {
	long long l, r;
	char c;
} y[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		x[i].len = a;
		x[i].l = b;
		x[i].r = b + a - 1;
		b += a;
		cin >> ch;
		x[i].c = ch;
	}
	b--;
	long long ml;
	if (b % 2 == 0) {
		ml = b / 2;
	} else {
		ml = b / 2 + 1;
	}
	for (int i = 1; i <= n; i++) {
		if (ml >= x[i].l && ml <= x[i].r) {
			x[i].r = ml;
			t1 = i;
			break;
		}
	}
	a = 1;
	for (int i = n; i >= 1; i--) {
		y[n - i + 1].l = a;
		y[n - i + 1].r = a + x[i].len - 1;
		y[n - i + 1].c = x[i].c;
		a += x[i].len;
		if (y[n - i + 1].r >= ml) {
			y[n - i + 1].r = ml;
			t2 = n - i + 1;
			break;
		}
	}
	long long L, R, xi = 1, yi = 1;
	for (int i = 1; xi <= t1 && yi <= t2;) {
		L = max(x[xi].l, y[yi].l);
		R = min(x[xi].r, y[yi].r);
		if (x[xi].c != y[yi].c)
			cnt += R - L + 1;
		if (x[xi].r == y[yi].r) {
			xi++;
			yi++;
		} else if (x[xi].r < y[yi].r)
			xi++;
		else if (x[xi].r > y[yi].r)
			yi++;
	}
	cout << cnt;
	return 0;
}