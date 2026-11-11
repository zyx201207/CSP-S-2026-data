#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int a[N], m, n, c, b;
int s(int x) {
	if (x > 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					x = max(a[i] & a[j] & x, x);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				x = max(a[i] & a[j], x);
			}
		}
	}
	if (m > 2) {
		m--;
		return s(x);
	}
	return x;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	b = s(b);
	cout << b;
	return 0;
}