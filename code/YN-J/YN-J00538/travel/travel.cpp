#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string n, m, s_1, s_2, s_3 = "", s_4 = "";
	cin >> n >> s_1 >> m >> s_2;
	if (n == m) {
		cout << "1";
	} else {
		cout << "0" << "0" << "0" << "0";
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		s_4 += s_2[i];
		s_3 += s_1[i];
	}
	if (s_3 == s_4) {
		cout << "1";
	} else {
		cout << "0" << "0" << "0";
		return 0;
	}
	s_3 = s_1[2];
	s_4 = s_2[2];
	if ((s_4 == "A" || s_4 == "B" || s_4 == "C") && (s_3 == "D" || s_3 == "F")) {
		cout << "0" << "0";
		return 0;
	}
	if ((s_3 == "A" || s_3 == "B" || s_3 == "C") && (s_4 == "D" || s_4 == "F")) {
		cout << "0" << "0";
		return 0;
	}
	cout << "1" ;
	if (s_3 == "D" || s_3 == "F") {
		cout << '1';
		return 0;
	}
	if (s_3 > s_4) {
		if (s_3[0] - 1 == s_4[0]) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		if (s_4[0] - 1 == s_3[0]) {
			cout << "1";
		} else {
			cout << "0";
		}
	}
	return 0;
}