#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	bool flag4 = false;
	if (c1 == c2) {
		flag1 = true;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			flag2 = true;
			if (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
			        || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))) {
				flag3 = true;
				if ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'F')) {
					flag4 = true;
				} else {
					cout << "1110";
					return 0;
				}
			} else {
				cout << "1100";
				return 0;
			}
		} else {
			cout << "1000";
			return 0;
		}
	} else {
		cout << "0000";
		return 0;
	}
	cout << "1111";
	return 0;
}