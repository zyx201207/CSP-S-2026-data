#include <bits/stdc++.h>
using namespace std;
string n, m, n1, m1;
string s = "ABCDF";

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> n1 >> m >> m1;
	int num = s.find(n1[2]);
	int mum = s.find(m1[2]);

	if (n == m) {
		cout << 1;

	} else {
		cout << 0;
	}

	if (n1[0] == m1[0] && n1[1] == m1[1] && n == m) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (n1[0] == m1[0] && n1[1] == m1[1] && n == m && (num <= 2 && mum < 3) && (mum <= 2 && num < 3)) {
		cout << 1;
	} else {
		cout << 0;
	}

	if ((num - mum == 1 || mum - num == 1) && n1[0] == m1[0] && n1[1] == m1[1] && n == m && (num <= 2 && mum < 3)
	        && (mum <= 2 && num < 3)) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}