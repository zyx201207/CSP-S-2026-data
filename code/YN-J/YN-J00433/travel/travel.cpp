#include <iostream>
using namespace std;
int oa, ta;
string os, ts;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> oa >> os >> ta >> ts;
	if (oa == ta) {
		if (os[0] == ts[0] && os[1] == ts[1]) {
			if (os[2] < 'D' && ts[2] < 'D' || os[2] >= 'D' && ts[2] >= 'D') {
				if (abs(os[2] - ts[2]) == 1 || os[2] == 'D' && ts[2] == 'F' || os[2] == 'F' && ts[2] == 'D') {
					cout << 1111;
				} else {
					cout << 1110;
				}
			} else {
				cout << 1100;
			}
		} else {
			cout << 1000;
		}
	} else {
		cout << "0000";
	}
	return 0;
}