#include <bits/stdc++.h>
using namespace std;

typedef int ll;

ll INF = 0x3f3f3f3f;

ll a, a1;
string c1, c2;
string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> a >> s1 >> c2 >> a1 >> s2;

	if (c1 != c2) {
		cout << "0000";
	} else {
		cout << "1";

		ll c = s1[0];
		ll c2 = s2[0];
		ll c3 = s1[1];
		ll c4 = s2[1];

		a = c * 10 + c3;
		a1 = c2 * 10 + c4;

		if (a == a1) {
			cout << 1;

			if (s1[2] <= 'C' && s2[2] <= 'C') {
				cout << "1";

				ll b = s1[2];
				ll b1 = s2[2];
				if (b - 1 == b1 || b + 1 == b1) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else if (s1[2] <= 'F' && s1[2] > 'C' && s2[2] <= 'F' && s2[2] > 'C') {
				cout << "1";

				ll b = s1[2];
				ll b1 = s2[2];
				if (b - 1 == b1 || b1 + 1 == b) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	}

	return 0;
}