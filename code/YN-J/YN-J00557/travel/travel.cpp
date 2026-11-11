#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;

signed main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		string t1 = s1.substr(0, 2);
		string t2 = s2.substr(0, 2);
		if (t1 == t2) {
			char h1 = s1[2];
			char h2 = s2[2];
			if ((h1 == 'A' && h2 == 'B') || (h1 == 'A' && h2 == 'C') || (h1 == 'B' && h2 == 'A') || (h1 == 'B' && h2 == 'C')
			        || (h1 == 'C' && h2 == 'A') || (h1 == 'C' && h2 == 'B') || (h1 == 'D' && h2 == 'F') || (h1 == 'F' && h2 == 'D')) {
				if ((h1 == 'A' && h2 == 'B') || (h1 == 'B' && h2 == 'A') || (h1 == 'B' && h2 == 'C') || (h1 == 'C' && h2 == 'B')
				        || (h1 == 'D' && h2 == 'F') || (h1 == 'F' && h2 == 'D')) {
					cout << "1111";
				} else {
					cout << "1110";
				}
			} else {
				cout << "1100";
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}