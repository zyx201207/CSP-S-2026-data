#include <bits/stdc++.h>
using namespace std;

int main() {
	preopen("string.in", "r", stdin)
	preopen("string.out", "w", stdout)
	int x, y, n = 0, m = 0;
	string a = "";
	char z;
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> y >> z;
		m += y;
		for (int j = 0; j < y; j++) {
			a = a + z;
		}
	}
	for (int i = 0; i < m / 2; i++) {
		if (a[i] != a[m - i]) {
			n++;
		}
	}
	cout << n;
}