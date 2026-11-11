#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n, m;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	if (m == 1) {
		cout << a[1];
	} else {
		int b = 0;
		while (mx > 0) {
			mx >>= 1;
			b++;
		}
		if (b >= m) {
			cout << (1 << (b - m + 1)) - 1;
		} else {
			int ans = a[1];
			for (int i = 2; i <= m; i++) {
				int s = 0, bt = 0;
				int j = a[i];
				while (j > 0) {
					bt += (j & 1);
					j >>= 1;
					bt++;
				}
				if (bt != 1) {
					ans &= a[i];
				} else {
					m++;
				}
			}
			cout << ans;
		}
	}
	return 0;
} 
/*
8
i:   1   2   3   4   5   6   7   8
a:   0   1   2   3   4   5   6   7
e; 000 001 010 011 100 101 110 111

*/
