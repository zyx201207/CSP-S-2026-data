#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n;
	cin >> a;
	cin >> m;
	cin >> b;
	if (n == m) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (a[0] == b[0] && a[1] == b[1]) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0;
		return 0;
	}
	if (a[2] == 'A' || a[2] == 'B' || a[2] == 'c' && b[2] == 'A' || b[2] == 'B' || b[2] == 'c') {
		cout << 1;
	} else if (a[2] == 'D' || a[2] == 'F' && a[2] == 'D' || a[2] == 'F') {
		cout << 1;
	} else {
		cout << 0 ;
	}
	if (a[2] + 1 == b[2] || a[2] - 1 == b[2]) {
		cout << 1;
	}
	if (a[2] == b[2]) {
		cout << 0;
	}
	return 0;
}