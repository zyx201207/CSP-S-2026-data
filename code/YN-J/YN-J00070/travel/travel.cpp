#include <bits/stdc++.h>
using namespace std;
string cr, cx, xr, xx;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> xr >> cr;
	cin >> xx >> cx;
	int l = cr.size() - 1;
	int p1 = (cr[0] - '0') * 10 + cr[1] - '0';
	int p2 = (cx[0] - '0') * 10 + cx[1] - '0';
	int d1 = (xr[0] - '0') * 10 + xr[1] - '0';
	int d2 = (xx[0] - '0') * 10 + xx[1] - '0';
	if	(xr == xx) {
		cout << "1";
		if (p1  == p2) {
			cout << "1";
			if ((cr[l] <= 'C' && cx[l] <= 'C') || (cr[l] >= 'D' && cx[l] >= 'D')) {
				cout << "1";
				if (cr[l] + 1 == cx[l] || cr[l] - 1 == cx[l] )
					cout << "1";
				else
					cout << "0";
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";



	return 0;
}
