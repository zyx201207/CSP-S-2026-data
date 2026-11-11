#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string shu1 = "", shu2 = "", zi1 = "", zi2 = "";
	shu1 += s1[0] + s1[1], shu2 += s2[0] + s2[1], zi1 += s1[2], zi2 += s2[2];
	if (c1 == c2) {
		cout << 1;
		if (shu1 == shu2) {
			cout << 1;
			if (((zi1 <= "C" && zi1 >= "A") && (zi2 <= "C" && zi2 >= "A")) || ((zi1 <= "E" && zi1 >= "D") && (zi2 <= "E"
			        && zi2 >= "D"))) {
				cout << 1;
				char a = zi1[0], b = zi2[0];
				int c = a, d = b;
				if (c + 1 == d || c - 1 == d) {
					cout << 1;
				} else {
					cout << 0;
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