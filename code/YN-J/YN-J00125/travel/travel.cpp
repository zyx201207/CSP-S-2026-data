#include <bits/stdc++.h>
using namespace std;
string sx, sw, strx, strw;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> sx >> sw >> strx >> strw;
	if (sx != strx) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	if (sw.substr(0, 2) != strw.substr(0, 2)) {
		cout << "000";
		return 0;
	}
	cout << 1;
	if ((sw[2] >= 'D' && strw[2] >= 'D') || (sw[2] < 'D' && strw[2] < 'D')) {
		cout << 1;
		if ((sw[2] >= 'D' && strw[2] >= 'D') || (sw[2] == 'B' || strw[2] == 'B')) {
			cout << 1;
		} else
			cout << 0;
	} else {
		cout << "00";
		return 0;
	}
	return 0;
}