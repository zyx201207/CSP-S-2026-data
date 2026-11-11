#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int c[5];
string s[5];
string a[5];

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c[1] >> s[1] >> c[2] >> s[2];
	switch(s[1][2]) {
		case 'A':
			a[1] = "l1";
			break;
		case 'B':
			a[1] = "l2";
			break;
		case 'C':
			a[1] = "l3";
			break;
		case 'D':
			a[1] = "r1";
			break;
		case 'F':
			a[1] = "r2";
			break;
	}
	switch(s[2][2]) {
		case 'A':
			a[2] = "l1";
			break;
		case 'B':
			a[2] = "l2";
			break;
		case 'C':
			a[2] = "l3";
			break;
		case 'D':
			a[2] = "r1";
			break;
		case 'F':
			a[2] = "r2";
			break;
	}
	if (c[1] == c[2]) {
		cout << '1';
	}
	else {
		cout << "0000";
		return 0;
	}
	if (s[1][0] == s[2][0] && s[1][1] == s[2][1]) {
		cout << '1';
	}
	else {
		cout << "000";
		return 0;
	}
	if (a[1][0] == a[2][0]) {
		cout << '1';
	}
	else {
		cout << "00";
		return 0;
	}
	if (abs((int)(a[1][1]) - (int)(a[2][1])) == 1) {
		cout << '1';
	}
	else {
		cout << '0';
	}
	return 0;
}
