#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, w, q, p;
	cin >> s >> w >> q >> p;
	if (s == q) {
		cout << "1";
		if ((w[0] == p[0]) && (w[1] == p[1])) {
			cout << "1";
			if ((w[2] >= 'D' && p[2] >= 'D') || (w[2] <= 'C' && p[2] <= 'C')) {
				cout << "1";
				if (abs(w[2] - p[2]) == 1) {
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
	} else {
		cout << "0000";
	}
	return 0;
}
