#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int r, x;
	string rz, xz;
	cin >> r >> rz >> x >> xz;
	
	if(r == x) {
		cout << '1';
	} else {
		cout << "0000";
		return 0;
	}
	if(rz[0] == xz[0] && rz[1] == xz[1]) {
		cout << '1';
		if(rz[2] >= 'A' && rz[2] <= 'C' && xz[2] >= 'A' && xz[2] <= 'C') {
			cout << '1';
			if(rz[2] - xz[2] == 1 || xz[2] - rz[2] == 1) {
				cout << '1';
			} else {
				cout << '0';
			}
		} else if(rz[2] >= 'D' && rz[2] <= 'F' && xz[2] >= 'D' && xz[2] <= 'F') {
			cout << '1';
			if(rz[2] - xz[2] == 1 || xz[2] - rz[2] == 1) {
				cout << '1';
			} else {
				cout << '0';
			}
		} else {
			cout <<"00";
		}
	} else {
		cout << "000";
	}
	
	return 0;
}