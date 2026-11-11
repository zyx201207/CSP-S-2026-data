#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string x, y;
	string a, b;
	cin >> x >> a >> y >> b;
	bool f1 = true, f2 = true, f3 = true;
	if (x == y)
		cout << 1;
	else {
		cout << 0;
		f1 = false;
	}
	if (f1 && a[1] == b[1])
		cout << 1;
	else {
		cout << 0;
		f2 = false;
	}
	if (f1 && f2 && ((a[2] >= 'A' && a[2] <= 'C' && b[2] >= 'A' && b[2] <= 'C') || ((a[2] == 'D' || a[2] == 'F')
	                 && (b[2] == 'D' || b[2] == 'F'))))
		cout << 1;
	else {
		cout << 0;
		f3 = false;
	}
	if (f1 && f2 && f3 && ((a[2] == 'A' && b[2] == 'B') || (a[2] == 'B' && (b[2] == 'A' || b[2] == 'C')) || (a[2] == 'C'
	                       && b[2] == 'B') || (a[2] == 'D' && b[2] == 'F') || (a[2] == 'F' && b[2] == 'D')))
		cout << 1;
	else
		cout << 0;
	return 0;
}