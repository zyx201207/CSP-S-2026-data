#include <bits/stdc++.h>
using namespace std;

struct travel {
	int cxh;
	string zwh;
};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	travel a, b;
	cin >> a.cxh >> a.zwh >> b.cxh >> b.zwh;
	if (a.cxh == b.cxh) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (a.zwh[0] == b.zwh[0] && a.zwh[1] == b.zwh[1]) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (a.zwh[2] == 'A' && b.zwh[2] == 'B' || a.zwh[2] == 'A' && b.zwh[2] == 'C' || a.zwh[2] == 'B' && b.zwh[2] == 'A'
	        || a.zwh[2] == 'B' && b.zwh[2] == 'C' || a.zwh[2] == 'C' && b.zwh[2] == 'A' || a.zwh[2] == 'C' && b.zwh[2] == 'B') {
		cout << 1;
	} else if (a.zwh[2] == 'D' && b.zwh[2] == 'F' || a.zwh[2] == 'F' && b.zwh[2] == 'D') {
		cout << 1;
	} else {
		cout << 0;
	}
	if (a.zwh[2] == 'A' && b.zwh[2] == 'B' || a.zwh[2] == 'B' && b.zwh[2] == 'A' || a.zwh[2] == 'B' && b.zwh[2] == 'C'
	        || a.zwh[2] == 'C' && b.zwh[2] == 'B') {
		cout << 1;
	} else if (a.zwh[2] == 'D' && b.zwh[2] == 'F' || a.zwh[2] == 'F' && b.zwh[2] == 'D') {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}