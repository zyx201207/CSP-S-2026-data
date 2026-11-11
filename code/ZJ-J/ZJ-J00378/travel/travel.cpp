#include <bits/stdc++.h>
using namespace std;
string rno, rst, xno, xst;
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	cin >> rno >> rst >> xno >> xst;
	
	if (rno == xno) {
		cout << 1;
		if (rst.substr (0, 2) == xst.substr (0, 2)) {
			cout << 1;
			if (((rst[2] >= 'A' && rst[2] <= 'C')
		  		&& (xst[2] >= 'A' && xst[2] <= 'C'))) {
					cout << 1;
					if (abs (rst[2] - xst[2]) == 1) {
						cout << 1;
					} else {
						cout << 0;
					}
			} else if (((rst[2] == 'D' || rst[2] == 'F')
		  		&& (xst[2] == 'D' || xst[2] == 'F'))) {
					cout << "11";
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}

	fclose (stdin);
	fclose (stdout);
	return 0;
} 