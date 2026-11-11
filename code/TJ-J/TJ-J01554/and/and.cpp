#include <bits\stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n], b = 100000000, c = -1;;
	int aa[n + 1], si[n], co_ = -10;
	memset(aa, 0, sizeof(aa));
	memset(si, 0, sizeof(si));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < b)
			b = a[i];
		else if (a[i] > c)
			c = a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > b && a[i] < c) {
			cout << a[i];
			return 0;
		}
	}
	cout << c;
	return 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int co = 0, a1 = aa[i], a2 = aa[j];
			for (int k = 0; k < min(si[i], si[j]); k++) {
				if (a1 % 10 == a2 % 10 && a1 % 10 != 1) {
					co++;
				}
				a1 /= 10;
				a2 /= 10;
			}
			co_ = max(co, co_);
		}
	}
	cout << b;
	return 0;
}