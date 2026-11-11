#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2, cnt1, cnt2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i <= 1; i++) {
		cnt1 += s1[i];
		cnt2 += s2[i];
	}
	char x = s1[2], y = s2[2];
	if (c1 == c2) {
		cout << 1;
	} else cout << 0;
	if (c1 == c2) {
		if (cnt1 == cnt2) {
			cout << 1;
		} else cout << 0;
	} else cout << 0;
	if (c1 == c2) {
		if (cnt1 == cnt2) {
			if ((x >= 'D' and y >= 'D') or (x <= 'C' and y <= 'C')) {
				cout << 1;
			} else cout << 0;
		} else cout << 0;
		
	} else cout << 0;
	if (c1 == c2) {
		if (cnt1 == cnt2) {
			if ((x >= 'D' and y >= 'D') or (x <= 'C' and y <= 'C')) {
				if (x + 1 == y or x - 1 == y) {
					cout << 1;
				} else cout << 0;
			} else cout << 0;
		} else cout << 0;
		
	} else cout << 0;
	return 0;
} 
