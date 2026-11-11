#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int t[200005];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1; i <= n; i++) {
//		int tmp = a[i];
//		for (int j = 32; j >= 0; j--) {
//			if (tmp == 0) {
//				break;
//			}
//			if ((tmp >> j) & 1 == 1) {
//				t[i][j] = 1;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= 8; j++) {
//			cout << t[i][j] << ' ';
//		}
//		cout << endl;
//	}
	int k = 0;
	for (int i = 32; i >= 0; i--) {
		if (a[1] >> i == 1) {
			k = i;
			break;
		}
	}
	int ans = -2e9;
	for (int i = k; i >= 0; i--) {
		memset(t, 0, sizeof t);
		int x = 1;
		for (int j = 1; j <= n; j++) {
			if ((a[j] >> i) & 1 == 1) {
				t[x++] = a[j];
				//cout << x << ' ';
			}
			//int t = (a[j] >> i);
			//cout << t << ' ';
		}
		x--;
		//cout <<  x << endl;
		int tmp = t[1];
		for (int j = 2; j <= max(m, x); j++) {
			tmp &= t[j];
		}
		//cout << tmp << endl;
		ans = max(ans, tmp);
	}
	cout << ans;
	return 0;
}