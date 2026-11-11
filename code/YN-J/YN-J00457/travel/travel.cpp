#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string c_1, s_1, c_2, s_2;
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	bool flag = 1, pai = 1;
	for (int i = 0; i < 2; i++) {
		if (c_1[i] != c_2[i]) {
			flag = 0;
		}
		if (s_1[i] != s_2[i]) {
			pai = 0;
		}
	}

	if (flag == 1) {
		cout << 1;
		if (pai == 1) {
			cout << 1;
			if (s_1[2] == 'A' || s_1[2] == 'B' || s_1[2] == 'C' && s_2[2] == 'A' || s_2[2] == 'B' || s_2[2] == 'C') {
				cout << 1;
				if (s_1[2] == 'A' && s_2[2] == 'B' || s_1[2] == 'B' && s_2[2] == 'A' || s_1[2] == 'B' && s_2[2] == 'C'
				        || s_1[2] == 'C' && s_2[2] == 'B' ) {
					cout << 1;
				} else {
					cout << "0";
				}
			} else if (s_1[2] == 'D' || s_1[2] == 'E' && s_2[2] == 'D' || s_2[2] == 'E') {
				cout << "11";

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