#include <bits/stdc++.h>
using namespace std;

int a1, a2;
string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> s1 >> a2 >> s2;
	if (a1 == a2) {
		cout << "1";
		int ss1 = (s1[0] - 48) * 10 + (s1[1] - 48);
		int ss2 = (s2[0] - 48) * 10 + (s2[1] - 48);
		if (ss1 == ss2) {
			cout << "1";
			if (s1[2] < s2[2])
				swap(s1[2], s2[2]);
			if ((s1[2] <= 'C' and s2[2] <= 'C') or (s1[2] >= 'D' and s2[2] >= 'D')) {
				cout << "1";
				if (s1[2] - s2[2] == 1) {
					if (s1[2] == 'C' and s2[2] == 'D')
						cout << "0";
					else
						cout << "1";
				} else
					cout << "0";
			} else
				cout << "00";

		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
}