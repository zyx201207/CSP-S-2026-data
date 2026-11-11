#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

struct Node {
	ll int len;
	char c;
} a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].len >> a[i].c;
	}
	ll int l = 1, r = n, ans = 0;
	while (l < r) {
		if (a[l].c == a[r].c) {
			if (a[l].len == a[r].len) {
				l++;
				r--;
			} else if (a[l].len > a[r].len) {
				a[l].len -= a[r].len;
				r--;
			} else {
				a[r].len -= a[l].len;
				l++;
			}
		} else {
			if (a[l].len == a[r].len) {
				ans += a[l].len;
				l++;
				r--;
			} else if (a[l].len > a[r].len) {
				ans += a[r].len;
				a[l].len -= a[r].len;
				r--;
			} else {
				ans += a[l].len;
				a[r].len -= a[l].len;
				l++;
			}
		}
	}
	cout << ans;
	return 0;
}