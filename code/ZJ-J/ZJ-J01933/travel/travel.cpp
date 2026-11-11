#include <bits/stdc++.h>
using namespace std;
string c_1 = "", s_1 = "", c_2 = "", s_2 = "";
bool check1() {
	if (c_1 == c_2) return 1;
	else return 0;
}
bool check2() {
	if (s_1[0] == s_2[0] && s_1[1] == s_2[1]) return 1;
	else return 0;
}
bool check3() {
	if (s_1[2] <= 'C' && s_2[2] <= 'C') return 1;
	if (s_1[2] >= 'D' && s_2[2] >= 'D') return 1;
	return 0;
}
bool check4() {
	if (s_1[2] <= 'C' && s_2[2] <= 'C'&&abs(s_1[2] - s_2[2]) == 1) return 1;
	if (s_1[2] >= 'D' && s_2[2] >= 'D'&&abs(s_1[2] - s_2[2]) == 2) return 1;
	return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if (check1()) {
		cout << "1";
		if (check2()) {
			cout << "1";
			if (check3()) {
				cout << "1";
				if (check4()) {
					cout << "1";
				} else cout << "0";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}