#include <bits/stdc++.h>
#include <cstdio>
#define OI ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string c1, c2, c3, c4;

int main() {
	//OI
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string ans;
	cin >> c1 >> c3 >> c2 >> c4;
	bool flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		ans += '1';
		flag1 = 1;
	} else
		ans += '0';
	if ((flag1 == 1) && (c3[0] == c4[0]) && (c3[1] == c4[1])) {
		ans += '1';
		flag2 = 1;
	} else
		ans += '0';
	if ((flag1 == 1 && flag2 == 1) && ((('A' <= c3[2] && c3[2] <= 'C') && ('A' <= c4[2] && c4[2] <= 'C')) || ((c3[2] == 'D'
	                                   || c3[2] == 'F') && (c4[2] == 'D' || c4[2] == 'F')))) {
		ans += '1';
		flag3 = 1;
	} else
		ans += '0';
	if (flag1 == 1 && flag2 == 1 && flag3 == 1 && ((c3[2] + 1 == c4[2] || c3[2] - 1 == c4[2]))) {
		ans += '1';
		flag4 = 1;
	} else
		ans += '0';
	cout << ans;

	return 0;
}