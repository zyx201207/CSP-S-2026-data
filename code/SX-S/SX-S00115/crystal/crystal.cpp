#include <bits/stdc++.h>
using namespace std;

struct shibc {
	int zhi;
	long long zongcha;
};
int n;
long long m, ans = 0, ansans = 0;
shibc a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long x = m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].zhi;
	}
	for (int i = 1; i <= n; i++) {
		a[i].zongcha = a[i - 1].zongcha + abs(a[i + 1].zhi - a[i].zhi);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[j].zongcha - a[i].zongcha <= m) {
				ans++;
				m -= a[j].zongcha - a[i].zongcha;

			} else {
				m = x;
				ansans = max(ans, ansans);
				ans = 0;
			}
		}
	}
	cout << ansans;
	return 0;
}
