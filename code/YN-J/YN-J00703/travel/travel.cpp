#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string an, a;
	string bn, b;
	cin >> an >> a;
	cin >> bn >> b;
	if (an == bn) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (an == bn && a[0] == b[0] && a[1] == b[1]) {
		cout << 1;
	} else {
		cout << 0;
	}
	if ((an == bn && a[0] == b[0] && a[1] == b[1] && ((a[2] >= 65 && a[2] <= 67) && b[2] >= 65 && b[2] <= 67 )
	        || ((a[2] == 68 || a[2] == 70) && (b[2] == 68 || b[2] == 70) )) ) {
		cout << 1;
	} else {
		cout << 0;
	}
	if ((an == bn && a[0] == b[0] && a[1] == b[1] && ((a[2] >= 65 && a[2] <= 67) && b[2] >= 65 && b[2] <= 67 )
	        || ((a[2] == 68 || a[2] == 70) && (b[2] == 68 || b[2] == 70))))  {
		if (max(int(a[2]), int(b[2])) - min(int(a[2]), int(b[2])) == 1 || a[2] == 68 && b[2] == 70) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}