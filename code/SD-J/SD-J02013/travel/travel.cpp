#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			char t1 = s1[2], t2 = s2[2];
			if (((t1 == 'F' || t1 == 'D') && (t2 == 'F' || t2 == 'D')) ||
				((t1 == 'A' || t1 == 'B' || t1 == 'C') && (t2 == 'A' || t2 == 'B' || t2 == 'C'))) {
				cout << "1";
				if (!((t1 == 'A' && t2 == 'C') || (t2 == 'A' && t1 == 'C'))) cout << "1";
				else cout << "0";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}
