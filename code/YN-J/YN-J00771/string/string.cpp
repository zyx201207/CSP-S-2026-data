#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200001], max1 = 0;

int mm(int x, int o) {
	int p = a[x];
	for (int i = x + 1; i <= n; i++) {
		if (o < m) {
			p = a[o] & mm(p, o);
		} else {
			return p;
		}
	}

}

int main() {
//	freopen("string4.in", "r", stdin);
//	freopen("string4.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int y;
		y = mm(i, o);
		if (y > max1) {
			max1 = y;
		}
	}
	cout << max1;
	return 0;
}