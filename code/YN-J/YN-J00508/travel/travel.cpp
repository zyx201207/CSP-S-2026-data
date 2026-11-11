#include <bits/stdc++.h>
using namespace std;
long long h1, h2;
string a, b;
bool z1 = 0, z2 = 0, z3 = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> h1 >> a;
	cin >> h2 >> b;
	if (h1 == h2) {
		cout << 1;
		z1 = 1;
	} else {
		cout << 0;
	}
	if (a[0] == b[0] && a[1] == b[1] && z1 == 1) {
		cout << 1;
		z2 = 1;
	} else {
		cout << 0;
	}
	if (((long long)a[2] <= 67 && (long long)b[2] <= 67) || (((long long)a[2] >= 68 && (long long)a[2] <= 69)
	        && (long long)b[2] >= 68
	        && (long long)b[2] <= 69)) {
		if (z2 == 1) {
			cout << 1;
			z3 = 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	if ((a[2] + 1 == b[2] || a[2] - 1 == b[2]) || (a[2] == 'D' && b[2] == 'F') || (a[2] == 'F' && b[2] == 'D')) {
		if (z3 == 1) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}

	return 0;
}
