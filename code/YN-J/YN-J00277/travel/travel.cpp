#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s, s1, n, m;
bool flg;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s >> n >> s1 >> m;
	if (s == s1) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (n[0] == m[0] && n[1] == m[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if ((n[2] <= 'C' && m[2] <= 'C') || (n[2] >= 'D' && n[2] <= 'F' && m[2] >= 'D' && m[2] <= 'F')) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (abs(n[2] - m[2]) == 1) {
		cout << "1";
	} else {
		cout << "0";
	}


	return 0;
}