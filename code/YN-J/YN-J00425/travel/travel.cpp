#include <bits/stdc++.h>
using namespace std;

struct zuo {
	string jie;
	string wei;
};
zuo r, x;
char rw, xw;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r.jie >> r.wei >> x.jie >> x.wei;
	if (r.jie == x.jie) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	rw = r.wei[2];
	xw = x.wei[2];
	if ((r.wei[0] == x.wei[0]) && (r.wei[1] == x.wei[1])) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if ((rw <= 'C' && xw <= 'C') || (rw >= 'D' && xw >= 'D')) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (abs(int(rw) - int(xw)) == 1) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}