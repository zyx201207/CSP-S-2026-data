#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2e5 + 5;
long long a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == n) {
		int cnt = a[1];
		for (int i = 2; i <= n; i++) {
			cnt &= a[i];
		}
		cout << cnt;
	} else if (m == 1) {
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			if (maxx < a[i])
				maxx = a[i];
		}
		cout << maxx;
	} else if (m == 2) {
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int m = a[i] & a[j];
				if (maxx < m) {
					maxx = m;
				}
			}
		}
		cout << maxx;
	} else if (m == n - 1) {
		int minn = 0x3f3f3f3f;
		int idx = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] < minn)
				minn = a[i], idx = i;
		}
		int cnt;
		bool f = 0;
		if (idx == 1)
			cnt = a[2];
		else
			cnt = a[1], f = 1;
		if (f) {
			for (int i = 2; i <= n; i++) {
				if (idx != i)
					cnt &= a[i];
			}
		} else {
			for (int i = 3; i <= n; i++) {
				if (idx != i)
					cnt &= a[i];
			}
		}
		cout << cnt;
	}
	return 0;
}