#include <bits/stdc++.h>
using namespace std;
int a, b;
string al, bl;

int main() {
	cin >> a >> al >> b >> bl;
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	if (a == b) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	int ax = al[0] - '0';

	ax = ax * 10 + al[1] - '0';
	int bx = bl[0] - '0';

	bx = bx * 10 + bl[1] - '0';

	if (ax == bx) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	char ay = al[2];
	char by = bl[2];
	if (ay == 'A' || ay == 'B' || ay == 'C' && by == 'A' || by == 'B' || by == 'C' ) {
		cout << 1;
	} else if (ay == 'D' || ay == 'F' && by == 'D' || by == 'F') {
		cout << 1;
	} else {
		cout << '00';
		return 0;
	}
	if (ay == 'A' && by == 'B' || ay == 'B' && by == 'C' || ay == 'B' && by == 'A' || ay == 'C' && by == 'B' || ay == 'F'
	        && by == 'D' || ay == 'D' && by == 'F') {
		cout << 1;
	} else {
		cout << 0;
	}


	return 0;
}