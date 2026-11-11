#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int c1, s1, c2, s2, i, j, a, m;
	cin >> i >> j >> a >> m;
	char b, n;
	c1 = i;
	c2 = j;
	if (i == j) {
		cout << '1' ;
	} else {
		cout << '0' ;
	}
	s1 = a + b;
	s2 = m + n;
	if (a == m) {
		cout << '1';
	} else {
		cout << '0';
	}
	if (b = 'A') {
		cout << '1';
	}
	if (b = 'B') {
		cout << '1';
	}
	if (b = 'C') {
		cout << '1';
	}
	if (b = 'D') {
		cout << '1';
	}
	if (b = 'F') {
		cout << '1';
	} else {
		cout << '0';
	}



	if (b = 'A', n = 'B') {
		cout << '1' ;
	} else if (b = 'B', n = 'C') {
		cout << '1' ;
	} else if (b = 'D', n = 'F') {
		cout << '1' ;
	} else if (b = 'F', n = 'D') {
		cout << '1' ;
	} else if (b = 'C', n = 'B') {
		cout << '1' ;
	} else if (b = 'B', n = 'A') {
		cout << '1' ;
	} else {
		cout << '0';
	}



	return 0;
}
