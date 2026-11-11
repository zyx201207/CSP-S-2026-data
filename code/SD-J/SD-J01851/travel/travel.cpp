#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("travel.in" , "r" , stdin);
	freopen ("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string rc , rs , xc , xs;
	cin >> rc >> rs >> xc >> xs;
	
	if (rc == xc) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
//	cout << endl;
	int lenr = rs.size();
	int lenx = xs.size();
	char r = rs[lenr - 1];//A
	char x = xs[lenx - 1];//B
	string rid , xid;
	for (int i = 0; i < lenr - 1; i++) {
		rid += rs[i];
		xid += xs[i];
	}
	if (rid == xid) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	int flag = 0;
	if ((r > 'C' && x > 'C') || (r <= 'C' && x <= 'C')) {
		cout << 1;
		flag = 1;
	} else {
		cout << "00";
		return 0;
	}
	if (flag == 1) {
		if (abs (int(r - x)) == 1) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}
