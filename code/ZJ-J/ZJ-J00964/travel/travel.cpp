#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		string r1 = s1.substr(0, 2), r2 = s2.substr(0, 2); 
		if (r1 == r2) {
			cout << 1;
			int k1 = s1[2] - 'A', k2 = s2[2] - 'A';
			if (k1 / 3 == k2 / 3) {
				cout << 1;
				if (abs(k1 - k2) == 1) {
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
	cout << endl;
	return 0;
}