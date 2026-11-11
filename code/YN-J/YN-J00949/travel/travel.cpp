#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n, m;
	int n1, m1;
	char a, b;
	cin >> n >> n1 >> a;
	cin >> m >> m1 >> b;
	for (int i = 1; i <= 6; i++) {
		if (a == 'A') {
			a = 1;
		} else if (a == 'B') {
			a = 2;
		} else if (a == 'C') {
			a = 3;
		} else if (a == 'D') {
			a = 4;
		} else if (a == 'F') {
			a = 5;
		}
		if (b == 'A') {
			a = 1;
		} else if (b == 'B') {
			b = 2;
		} else if (b == 'C') {
			b = 3;
		} else if (b == 'D') {
			b = 4;
		} else if (b == 'F') {
			b = 5;
		}
	}
	if (n == m) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (n1 == m1) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0;
		return 0;
	}
	if (a + b != 7) {
		cout << 1;
	} else {
		cout << 0 ;
	}
	int t = 0;
	if (a - b == 1 || b - a == 1) {
		t++;
	}
	if (a + b == 7) {
		cout << 0;
		return 0;
	}
	if (t == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
