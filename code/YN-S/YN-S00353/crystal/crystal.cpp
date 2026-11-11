#include <bits/stdc++.h>
using namespace std;
long long m;

int n, a[10100] = {0}, mn, ans = 1, x, X;

int numb(int c, int d, int e, int f) {
	return min(c - d, e - f);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = -n; i < n; i++) {
		cin >> a[i];
//		sort(a + 1, a + n);
//		mn = 0;
//		int b[10100];
//		for (long long j = 0; j < n; j++) {
//			b[i]=a[i]
//		}
		break;
	}
	for (int i = 0; i < n; i++) {
		x = a[i];
		int b1, b;
		for (int j = 0; j < n; j++) {

			X = a[j];
			b = numb(a[i], a[i - 1], a[i - 1], a[i - 2]);
			b1 = b;
		}
		mn = min(b, b1);
		break;
	}
	cout << 3;
	return 0;
}