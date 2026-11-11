#include <bits/stdc++.h>
using namespace std;
string a, a1, b, a2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> a1 >> b >> a2;
	if (a == b) {
		cout << 1;
		if (a1[0] == a2[0] && a1[1] == a2[1]) {
			cout << 1;
			if (a1[2] >= 'A' && a1[2] <= 'C' && a2[2] >= 'A' && a2[2] <= 'C') {
				cout << 1;
				if (a1[2] == 'A' && a2[2] == 'B') {
					cout << 1;
				} else if (a2[2] == 'A' && a1[2] == 'B') {
					cout << 1;
				} else if (a2[2] == 'C' && a1[2] == 'B') {
					cout << 1;
				} else if (a1[2] == 'C' && a2[2] == 'B') {
					cout << 1;
				} else {
					cout << 0;
				}
			} else if (a1[2] >= 'D' && a1[2] <= 'F' && a2[2] >= 'D' && a2[2] <= 'F') {
				cout << 11;
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