#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct pp {
	string cx;
	string zw;
};
pp r;
pp x;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r.cx >> r.zw;
	cin >> x.cx >> x.zw;
	bool flag = 0;
	if (r.cx == x.cx && r.cx != "01" && r.cx != "16" && x.cx != "01" && x.cx != "16" ) {
		cout << 1;
		flag = 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if (r.zw[0] == x.zw[0] && r.zw[1] == x.zw[1] && flag) {
		cout << 1;
		flag = 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if ( flag && ((r.zw[2] == 'A' || r.zw[2] == 'B' || r.zw[2] == 'C') && ((x.zw[2] == 'A'
	              || x.zw[2] == 'B' || x.zw[2] == 'C'))) || ((r.zw[2] == 'D' || r.zw[2] == 'F') && ((x.zw[2] == 'D'
	                      || x.zw[2] == 'F')))) {
		cout << 1;
		flag = 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if (flag && ((r.zw[2] == x.zw[2] + 1 || r.zw[2] == x.zw[2] - 1) || (r.zw[2] == x.zw[2] + 2
	             || r.zw[2] == x.zw[2] - 2))) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}