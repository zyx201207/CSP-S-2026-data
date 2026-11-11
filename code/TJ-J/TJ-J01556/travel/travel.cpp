#include <bits/stdc++.h>
using namespace std;
string n2, n4;
int n1, n3;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n1 >> n2 >> n3 >> n4;
	if (n1 == n3) {
		cout << "1";
		if (n2[0] == n4[0] && n2[1] == n4[1]) {
			cout << "1";
			if ((n2[2] <= 'C' && n4[2] <= 'C') || (n2[2] > 'C' && n4[2] > 'C')) {
				cout << "1";
				if (n2[2] - n4[2] == -1 || n2[2] - n4[2] == 1) {
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