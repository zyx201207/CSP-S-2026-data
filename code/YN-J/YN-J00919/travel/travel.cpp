#include <bits/stdc++.h>
using namespace std;
#define long long
#define endl '\n'
char c1, c2;
string s1[6], s2[6];

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 ;
	for (int i = 0; i <= 2; i++) {
		cin >> s1[i];
	}
	cin >> c2;
	for (int i = 0; i <= 2; i++) {
		cin >> s2[i];
	}
	if (c1 == c2) {
		cout << 1;
	}
	int a;
	for (int i = 1; i <= 2; i++) {
		if (s1[i] != s2[i]) {
			cout << 0;
			a = 0;
			break;
		} else if (i == 2) {
			cout << 1;
			a = 1;
		} else {
			continue;
		}
	}
	if (a == 1 && ((s1[2] == 'F' && s2[2] == 'D') || (s2[2] == 'F' &&
	               s1[2] == 'D') || ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') &&
	                                 s2[2] != 'F' && s2[2] != 'D'))) {
		cout << 1;
		int b = 1;
	} else {
		cout << 0;
		int b = 0;
	}
	if (b == 1 && (s1[2] == 'D' || s1[2] == 'F' || s1[2] == 'B' || s2[2] == 'B')) {
		cout << 1;
	}
	return 0;
}