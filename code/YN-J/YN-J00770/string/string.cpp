#include <bits/stdc++.h>
using namespace std;
long long n, l, s;
char a[10000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		char y;
		cin >> x >> y;
		for (int j = 0; j < x; j++) {
			a[l] = y;
			l++;
		}
	}
	for (int i = 0; i < l / 2 + 1; i++) {
		if (a[i] != a[l - i - 1]) {
			a[i] = a[l - i - 1];
			s++;
		}
	}
	cout << s;
	return 0;
}