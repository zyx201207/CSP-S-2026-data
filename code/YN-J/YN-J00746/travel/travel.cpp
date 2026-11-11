#include <bits/stdc++.h>
using namespace std;
string c_1, s_1, c_2, s_2, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if (c_1 == c_2) {
		ans += "1";
	} else {
		ans += "0";

	}
	int flag = 0;
	string ss_1 = s_1.substr(0, 2);
	string ss_2 = s_2.substr(0, 2);
	if (ans[0] == '1') {
		if (ss_1 == ss_2) {
			ans += "1";
		} else {
			ans += "0";
		}
	} else {
		ans += "0";
	}

	if (ans[1] == '1') {
		if ((s_1[2] <= 'C' && s_2[2] <= 'C') || (s_1[2] > 'C' && s_1[2] <= 'F' && s_2[2] > 'C' && s_2[2] <= 'F')) {
			ans += "1";
		} else {
			ans += "0";
		}
	} else {
		ans += "0";
	}

	int flagg = 0;
	if (ans[2] == '1') {
		if (abs(s_1[2] - s_2[2]) == 1) {
			if ((s_1[2] == 'C' && s_2[2] == 'D') || (s_1[2] == 'D' && s_2[2] == 'C')) {
				ans += "0";
			} else {
				ans += "1";
			}
			flagg = 1;
		}
	}

	if (flagg == 0) {
		ans += "0";
	}
	cout << ans;
	return 0;
}
