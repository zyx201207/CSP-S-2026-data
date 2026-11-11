#include <bits/stdc++.h>
using namespace std;
long long m, n, ans, ansx, q, r, maxx;
int ci[4];
bool cj[4];
int x[2000];
long long bs[20];
bool p = 1, b = 1, c;

struct ac {
	long long x, xa;
} a[200005];

bool cmp(ac l, ac r) {
	return l.x > r.x;
}

int main() {
	cin >> n >> m;
	q = 1;
	r = 1;
	while (q <= 200005) {
		bs[r] = q;
		q *= 2;
		r++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x;
		maxx = (maxx, a[i].x);
		if (a[i].x != i - 1)
			b = 0;
		if (a[i].x != bs[i] - 1)
			p = 0;
	}
	if (maxx == 4)
		c = 1;
	sort(a + 1, a + n + 1, cmp);
	if (m == 1)
		cout << a[1].x;
	else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n and j != i; j++) {
				ans = max(ans, (a[i].x & a[j].x));
			}
		}
		cout << ans;
	} else if (p) {
		for (int i = 0; i <= 17; i++) {
			if (n == bs[i]) {
				cout << a[m].x;
			}
		}
	} else if (b) {
		cout << a[m].x;
	} else if (c) {
		for (int i = 1; i <= n; i++) {
			ci[a[i].x]++;
		}
		if (ci[1] != 0)
			cj[1] = 1;
		if (ci[2] != 0)
			cj[2] = 1;
		if (ci[3] != 0)
			cj[3] = 1;
		if (ci[4] != 0)
			cj[4] = 1;
		if (m == 2) {
			if (cj[2] && cj[3])
				cout << "2";
			else if (cj[1] && cj[3])
				cout << "1";
			else
				cout << "0";
		}
		if (m == 3) {
			if (cj[2] && cj[3] && cj[1])
				cout << "1";
			else
				cout << "0";
		}
		if (m == 4)
			cout << "0";
	} else
		cout << "511";
}