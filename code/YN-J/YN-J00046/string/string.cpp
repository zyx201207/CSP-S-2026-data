#include <bits/stdc++.h>
using namespace std;
int n, a[200005], a1 = 1, a2, b1, b2;
long long k, y, K, ans;
char b[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	b1 = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		k += a[i];
	}
	K = (k - 1) / 2;
	for (; y <= K;) {
		if (a[a1] - a2 > a[b1] - b2) {
			y += a[b1] - b2;
			a2 += a[b1] - b2;
			if (b[a1] != b[b1]) {
				ans += a[b1] - b2;
			}
			b2 = 0;
			b1--;
		} else if (a[a1] - a2 < a[b1] - b2) {
			y += a[a1] - a2;
			b2 += a[a1] - a2;
			if (b[a1] != b[b1]) {
				ans += a[a1] - a2;
			}
			a2 = 0;
			a1++;
		} else {
			y += a[a1] - a2;
			if (b[a1] != b[b1]) {
				ans += a[a1] - a2;
			}
			a1++;
			b1--;
			a2 = 0;
			b2 = 0;
		}
	}
	cout << ans;
	return 0;
}