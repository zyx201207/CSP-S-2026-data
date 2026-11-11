#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	string aa1, aa2, bb1, bb2;
	cin >> aa1 >> aa2 >> bb1 >> bb2;
	int nn1 = (aa1[0] - '0') * 10 + (aa1[1] - '0');
	int nn2 = (bb1[0] - '0') * 10 + (bb1[1] - '0');
	int zz1 = (aa2[0] - '0') * 10 + (aa2[1] - '0');
	int zz2 = (bb2[0] - '0') * 10 + (bb2[1] - '0');
	char cc1 = aa2[2];
	char cc2 = bb2[2];
	if (nn1 == nn2) {
		cout << "1";
		if (zz1 == zz2) {
			cout << "1";
			if ((cc1 == 'D' || cc1 == 'F') && (cc2 == 'D' || cc2 == 'F')) {
				cout << "1";
				if ((cc1 == 'D' && cc2 == 'F') || (cc2 == 'D' && cc1 == 'F')) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else if ((cc1 == 'A' || cc1 == 'B' || cc1 == 'C') && (cc2 == 'A' || cc2 == 'B' || cc2 == 'C')) {
				cout << "1";
				if ((cc1 == 'A' && cc2 == 'B') || (cc1 == 'B' && (cc2 == 'B' || cc2 == 'C')) || (cc1 == 'C' && cc2 == 'B')) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
} 
