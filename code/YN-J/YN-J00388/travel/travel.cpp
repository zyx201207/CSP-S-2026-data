#include <bits/stdc++.h>
using namespace std;
string cx_1, cx_2, zw_1, zw_2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	bool flag = 1;
	cin >> cx_1 >> zw_1 >> cx_2 >> zw_2;
	if (cx_1 == cx_2) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	string s_1, s_2;
	s_1 = zw_1.substr(0, 2);
	s_2 = zw_2.substr(0, 2);
	if (s_1 == s_2 && flag == 1) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if (((zw_1[2] <= 'C' && zw_2 <= "c") || (zw_1[2] >= 'D' && zw_2[2] >= 'D')) && flag == 1) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	int x = zw_1[2] - zw_2[2], ans;
	ans = abs(x);
	if (ans == 1 && flag == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}