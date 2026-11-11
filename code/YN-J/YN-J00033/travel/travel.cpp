#include <bits/stdc++.h>
using namespace std;
char r[6], x[6];
char sum[5];

int main() {
	freopen("travel.in", "w", stdin);
	freopen("travel.out", "r", stdout);
	for (int i = 1; i <= 4; i++) {
		sum[i] = '0';
	}
	char e;
	for (int i = 1; i <= 5; i++) {
		cin >> e;
		r[i] = e;
	}
	for (int i = 1; i <= 5; i++) {
		cin >> e;
		x[i] = e;
	}
	int xiang = 0;
	if (r[1] == x[1]) {
		xiang = 1;
		if (r[2] == x[2]) {
			xiang = 1;
		} else {
			xiang = 0;
		}
	}
	int pai = 1, ce = 0;
	if (r[3] == x[3]) {
		if (r[4] == x[4]) {
			if (r[5] <= 'C' && x[5] <= 'C') {
				ce = 1;
			} else {
				if (r[5] >= 'D' && x[5] >= 'D') {
					ce = 1;
				} else {
					ce = 0;
				}
			}
		} else {
			pai == 0;
		}
	}
	int m = abs(x[5] - r[5]);
	if (xiang == 1) {
		sum[1] = '1';
	}
	if (pai == 1) {
		sum[2] = '1';
	}
	if (ce == 1) {
		sum[3] = '1';
		if (m == 1) {
			sum[4] = '1';
		}
	}
	for (int i = 1; i <= 4; i++) {
		cout << sum[i];
	}
	return 0;
}