#include <bits/stdc++.h>
using namespace std;
const int N = 2050;
int a[N][50];
int n, m;
int b[N];

void rjz(int k, int x) {
	int t = 0;
	while (x > 0) {
		a[k][++t] = x % 2;
		x /= 2;
	}
	a[k][0] = t;
}

int sjz() {
	int m = 1;
	int t = 0;
	for (int i = 1; i <= n; i++) {
		t += a[2001][i] * m;
		m *= 2;
	}
	return t;
}

int main(void) {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++) {
		rjz(i, b[i]);
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= a[i][0]; j++) {
//			cout << a[i][j];
//		}
//		cout << endl;
//	}
	int t1 = n;
	for (int i = 1; i <= a[t1][0]; i++) {
		bool b = 1;
		for (int k = t1; k >= t1 - m + 1; k--) {
			if (a[k][i] == 0) {
				b = 0;
				break;
			}
		}
		if (b) {
			a[2001][i] = 1;
		} else {
			a[2001][i] = 0;
		}
	}
	int ans = sjz();
	cout << ans;
	return 0;
}