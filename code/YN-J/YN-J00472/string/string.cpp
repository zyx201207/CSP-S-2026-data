#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 50;
char a[N];

int c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> a[i];
	}
	int num = 0;
	int r = n, l = 1;
	int sum = 0;
	while (r >= l) {
		int num = abs(c[r] - c[l]);
		if (c[r] == c[l]) {
			if (a[r] != a[l]) {
				sum += c[r];
			}
			c[r] = 0;
			c[l] = 0;
		} else {
			int nn = 0;
			if (c[r] > c[l]) {
				c[r] = num;
				nn = c[l];
				c[l] = 0;


			} else if (c[r] < c[l]) {
				c[l] = num;
				nn = c[r];
				c[r] = 0;
			} else {
				c[l] = 0;
				c[r] = 0;
			}
			if (a[r] != a[l]) {
				sum += nn;
			}
		}
		if (c[r] == 0) {
			r--;
		}
		if (c[l] == 0) {
			l++;
		}
	}
	cout << sum;
	return 0;
}
