#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a1, a2, b1, b2;
ll x;
ll y;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	if (a1 == b1) {
		cout << 1;
		x = 1;
	} else {
		cout << 0;
		x = 0;
	}
	ll s1 = int(a2[0]) - '0';
	s1 = s1 * 10 + int(a2[1]) - '0';
	ll s2 = int(b2[0]) - '0';
	s2 = s2 * 10 + int(b2[1]) - '0';
//	cout << s1 << " " << s2;
	if (s1 == s2 && x == 1) {
		cout << 1;
		x = 2;
	} else {
		cout << 0;
		x = 0;
	}
	ll s3 = int(a2[2]);
	ll s4 = int(b2[2]);
	if (s3 <= 67 && s4 <= 67 && x == 2 || s3 >= 68 && s3 >= 68 && x == 2) {
		cout << 1;
		x = 3;
	} else {
		cout << 0;
		x = 0;
	}
	if (abs(s3 - s4) == 1 && x == 3) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}
