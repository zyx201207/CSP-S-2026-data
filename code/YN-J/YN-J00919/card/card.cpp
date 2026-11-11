#include <bits/stdc++.h>
using namespace std;
#define long long
#define endl '\n'
int n, m;

int a[1000000 + 1], t{5000}, b[1000000 + 1], c[5000];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int i = 1;
	sort(1 + b, b + 1 + n);
	while (i <= n) {
		//i是已进行的局数
		for (int j = i; j <= n; j++) {
			int e = a[j];
			t[e]++;
			if (t[e] > 1) {
				int l = i;
				while (a[l] != a[j] && l < j) {
					l++;
				}
				for (int h = l; h < j; h++) {
					t[h] = 0;
				}
			}
		}
		//去掉重复数字
		for (int j = 1; j <= max(b[1], b[4999]); j++) {
			if (t[j] = 1) {
				c[j]++;
			}
		}
	}
	for (int i = 1; i <= max(c[1], c[4999]); i++) {
		if (c[i] != 0) {
			cout << c[i] << " ";
		}
	}
	return 0;
}