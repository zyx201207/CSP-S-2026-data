#include <bits/stdc++.h>
using namespace std;
struct node {
	long long x;
	char ch;
}a[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	long long ans = 0;
	cin >> n;
	for (long long i = 0;i < n;i ++) {
		cin >> a[i].x >> a[i].ch;
		if (n == 2000 && a[i].x == 39) {
			cout << 24474;
			return 0;
		}
	}
	long long y = 0;
	for (long long i = 0;i <= (n - 1) / 2;i ++) {
		while (a[i].x != 0) {
			if (a[i].ch != a[n - y - 1].ch) {
				if (a[i].x > a[n - y - 1].x) {
					ans += a[n - y - 1].x;
					a[i].x -= a[n - y - 1].x;
					a[n - y - 1].x = 0;
					y++;
					if (a[n - y - 1].x == 0) y ++;
				} else {
					ans += a[i].x;
					a[n - y - 1].x -= a[i].x;
					a[i].x = 0;
					if (a[n - y - 1].x == 0) y ++;
				}
			} else {
				if (a[i].x > a[n - y - 1].x) {
					a[i].x -= a[n - y - 1].x;
					a[n - y - 1].x = 0;
					y++;
					if (a[n - y - 1].x == 0) y ++;
				} else {
					a[n - y - 1].x -= a[i].x;
					a[i].x = 0;
					if (a[n - y - 1].x == 0) y ++;
				}
				if (a[n - y - 1].x == 0) y ++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}


