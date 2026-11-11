#include <bits/stdc++.h>
using namespace std;
long long n, l, r, cnt;

struct q {
	string s;
	long long x;
} a[2000010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].s;
	}
	l = 1, r = n;
	while (l <= r) {
		if (a[l].s == a[r].s) {
			if (a[l].x > a[r].x) {
				a[l].x -= a[r].x;
				r--;
			} else if (a[l].x < a[r].x) {
				a[r].x -= a[l].x;
				l++;
			} else {
				r--;
				l++;
			}
		} else {
			if (a[l].x > a[r].x) {
				a[l].x -= a[r].x;
				cnt += a[r].x;
				r--;
			} else if (a[l].x < a[r].x) {
				a[r].x -= a[l].x;
				cnt += a[l].x;
				l++;
			} else {
				cnt += a[r].x;
				r--;
				l++;

			}
		}
	}
	cout << cnt;
	return 0;
}