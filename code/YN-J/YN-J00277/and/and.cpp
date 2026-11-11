#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
int n, m, a[N], maxx = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		sort(a + 1, a + n + 1);
		cout << a[n] << '\n';
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				int num = a[i];
				num &= a[j];
				maxx = max(num, maxx);
			}
		}
		cout << maxx << '\n';
		return 0;
	}
	if (m == 3) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				int num = a[i];
				num &= a[j];
				for (int k = 1; k <= n; k++) {
					if (k == i || k == j) {
						continue;
					}
					int num1 = num;
					num1 &= a[k];
					maxx = max(num1, maxx);
				}
			}
		}
		cout << maxx << '\n';
		return 0;
	}
	if (m == 4) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				int num = a[i];
				num &= a[j];
				for (int k = 1; k <= n; k++) {
					if (k == i || k == j) {
						continue;
					}
					int num1 = num;
					num1 &= a[k];
					for (int k1 = 1; k1 <= n; k1++) {
						if (k1 == i || k1 == j || k1 == k) {
							continue;
						}
						int num2 = num1;
						num2 &= a[k1];
						maxx = max(num2, maxx);
					}
				}
			}
		}
		cout << maxx << '\n';
		return 0;
	}
	if (m == 5) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				int num = a[i];
				num &= a[j];
				for (int k = 1; k <= n; k++) {
					if (k == i || k == j) {
						continue;
					}
					int num1 = num;
					num1 &= a[k];
					for (int k1 = 1; k1 <= n; k1++) {
						if (k1 == i || k1 == j || k1 == k) {
							continue;
						}
						int num2 = num1;
						num2 &= a[k1];
						for (int k2 = 1; k2 <= n; k2++) {
							if (k2 == i || k2 == j || k2 == k || k2 == k1) {
								continue;
							}
							int num3 = num2;
							num3 &= a[k2];
							maxx = max(num3, maxx);
						}
					}
				}
			}
		}
		cout << maxx << '\n';
		return 0;
	}


	return 0;
}