#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main() {	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int a1 = (c1[0] - '0') * 10 + (c1[1] - '0');
	int b1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int c1 = (s1[2] - 'A' + 1);
	if (c1 == 4) c1 = 5;
	int d1 = (c1 <= 3 ? 0 : 1);
	
	int a2 = (c2[0] - '0') * 10 + (c2[1] - '0');
	int b2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	int c2 = (s2[2] - 'A' + 1);
	if (c2 == 4) c2 = 5;
	int d2 = (c2 <= 3 ? 0 : 1);
	
	if (a1 == a2) {
		cout << 1;
		if (b1 == b2) {
			cout << 1;
			if (d1 == d2) {
				cout << 1 << (abs(c1 - c2) == 1 ? 1 : 0) << endl;
			} else
				cout << "00" << endl;
		} else
			cout << "000" << endl;
	} else
		cout << "0000" << endl;
	return 0;
}
