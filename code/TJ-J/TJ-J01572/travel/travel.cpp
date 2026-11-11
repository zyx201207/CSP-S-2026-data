#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	long long n, m;
	string a, b;
	cin >> n >> a >> m >> b;
	if (a[2] == 'F') {
		a[2] = 'E';
	}
	if (b[2] == 'F') {
		b[2] = 'E';
	}
	if (n != m) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	if (!(a[0] == b[0] && a[1] == b[1])) {
		cout << "000";
		return 0;
	}
	cout << "1";
	if (!((a[2] >= 'A' && a[2] <= 'C' && b[2] >= 'A' && b[2] <= 'C') || (a[2] >= 'D' && a[2] <= 'E' && b[2] >= 'D'
	        && b[2] <= 'E'))) {
		cout << "00";
		return 0;
	}
	cout << "1";
	if (abs(a[2] - b[2]) != 1) {
		cout << "0";
		return 0;
	}
	cout << "1";
	return 0;
}