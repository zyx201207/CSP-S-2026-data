#include <bits/stdc++.h>
using namespace std;

int main() {
	preopen("travel.in", "r", stdin)
	preopen("travel.out", "w", stdout)
	int n1, m1;
	string n2, m2;
	cin >> n1 >> n2 >> m1 >> m2;
	if (n1 == m1) {
		cout << "1";
		if (n2[0] == m2[0] && n2[1] == m2[1]) {
			cout << "1";
			if (n2[2] <= 'c' && m2[2] <= 'c') {
				cout << "1";
				if (n2[2] + 1 == m2[2]) {
					cout << "1";
				} else if (m2[2] + 1 == n2[2]) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else if (n2[2] >= 'D' && m2[2] >= 'D') {
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
}