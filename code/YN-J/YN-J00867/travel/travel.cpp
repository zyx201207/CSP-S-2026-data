#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
string c1, s1, c2, s2;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	// be sure to delete any "//" on this line!!!!!!!!
	// be sure to change the file name
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			char a1 = s1[2], a2 = s2[2];
			if (a1 < 'D' == a2 < 'D') {
				cout << 1;
				if (abs(a2 - a1) == 1)
					cout << 1;
				else
					cout << 0;
			} else
				cout << "00";

		} else
			cout << "000";
	} else
		cout << "0000";

	cout << "\n";
	return 0;
}