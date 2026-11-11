#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> c1 >> s1 >> c2 >> s2;
	int r1 = (c1[0] - '0') * 10 + (c1[1] - '0');
	int x1 = (c2[0] - '0') * 10 + (c2[1] - '0');
	if(r1 == x1) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	int r2 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int x2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(r2 == x2) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	int r3 = (s1[2] - 'A');
	int x3 = (s2[2] - 'A');
	if(r3 < 3 && x3 < 3) {
		if(abs(r3 - x3) == 1) {
			cout << "11";
		} else {
			cout << "10";
		}
	} else if(r3 >= 3 && x3 >= 3) {
		cout << "11";
	} else {
		cout << "00";
	}
}