//by.pcx
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N = 2e5 + 5;
int n;

struct node {
	int st, ed;
	char c;
} a[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	int now = 0, st;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		cin >> x >> c;
		st = now + 1;
		now += x;
		a[i] = {st, now, c};
	}
	int mid = (now + 1) / 2, len = now, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].ed > mid)
			continue;
		for (int j = 1; j <= n; j++) {
			if (a[j].ed <= mid)
				continue;
			int x = len + 1 - a[j].ed;
			int y = len + 1 - max(a[j].st, mid + (len % 2));
			if (a[i].st <= x && a[i].ed >= x) {
				if (a[i].c != a[j].c) {
					ans += (y - x + 1);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
