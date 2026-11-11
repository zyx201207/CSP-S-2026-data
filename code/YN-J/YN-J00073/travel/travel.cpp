#include <bits/stdc++.h>
using namespace std;
char a[10], b[10], x[10], y[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdin);
	string a1, b1, x1, y1, n, m, n1, m1;
	char n2, m2;
	int p = 3, q = 1;
	cin >> a1 >> b1 >> x1 >> y1;
	if (a1 == x1) {
		cout << '1';
	} else {
		cout << '0';
	}
	for (int i = 0; i <= p; i++) {
		b[i];
		if (b[i] >= '0' && b[i] <= '9') {
			n += b[i];
		}
	}
	for (int i = 0; i <= p; i++) {
		y[i];
		if (y[i] >= '0' && y[i] <= '9') {
			m += y[i];
		}
	}
	if (n == m) {
		cout << '1';
	} else {
		cout << '0';
	}
	for (int i = 0; i <= p; i++) {
		b[i];
		if (b[i] >= 'A' && b[i] <= 'Z') {
			n1 += b[i];
		}
	}
	for (int i = 0; i <= p; i++) {
		y[i];
		if (y[i] >= 'A' && y[i] <= 'Z') {
			m1 += y[i];
		}
	}
	if (n1 == m1) {
		cout << '1';
	} else {
		cout << '0';
	}
	for (int i = 0; i <= p; i++) {
		b[i];
		if (b[i] >= 'A' && b[i] <= 'Z') {
			n2 += b[i];
		}
	}
	for (int i = 0; i <= p; i++) {
		y[i];
		if (y[i] >= 'A' && y[i] <= 'Z') {
			m2 += y[i];
		}
	}
	if (  q = n2 - m2  ) {
		cout << '1';
	} else {
		cout << '0';
	}

	return 0;
}