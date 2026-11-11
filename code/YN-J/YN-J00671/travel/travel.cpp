#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
		a[1] = 1;
	} else {
		a[1] = 0;
	}
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
		a[2] = 1;
	} else {
		a[2] = 0;
	}

	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) {
		if (a[1] == a[2]) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && a[1] == a[2]) {
		if (s1[2] == 'D' && s2[2] == 'C' || s2[2] == 'D' && s1[2] == 'C') {
			cout << "0";
		} else if (s1[2] == 'D' && s2[2] == 'F' || s2[2] == 'D' && s1[2] == 'F') {
			cout << "1";
		} else if (abs(int(s1[2]) - int(s2[2])) == 1) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}
	return 0;
}