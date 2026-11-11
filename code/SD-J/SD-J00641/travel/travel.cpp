#include <bits/stdc++.h>
using namespace std;
string cr, sr, cx, sx;
int r_l, x_l, n;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cr >> sr >> cx >> sx;
	if (cr == cx) {
		cout << "1";
		n++;
	}else {
		cout << "0000";
		return 0;
	}
	r_l = (sr[0] - '0') * 10 + sr[1] - '0';
	x_l = (sx[0] - '0') * 10 + sx[1] - '0';
	if (r_l == x_l) {
		cout << "1";
		n++;
	}else {
		cout << "000";
		return 0;
	}
	if (sr[2] >= 'D' && sx[2] >= 'D' || sr[2] <= 'C' && sx[2] <= 'C') {
		cout << "1";
		n++;
	}else {
		cout << "00";
		return 0;
	}
	if (n == 3 && (sr[2] - 1 == sx[2] || sr[2] + 1 == sx[2])) {
		cout << "1";
	}else {
		cout << "0";
	}
	return 0;
}
