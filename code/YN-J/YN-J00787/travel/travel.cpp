#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, p1, p2;
	char w1, w2;
	int flag = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		flag = 1;
	} else {
		cout << 0;
		flag = 0;
	}
	for (int i = 0; i < 2; i++) {
		p1 += s1[i];
		p2 += s2[i];
	}
//	cout << p1 << " " << p2;
	w1 = s1[2];
	w2 = s2[2];
	if (p1 == p2 && flag == 1) {
		cout << 1;
		flag = 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if ((int(w1) >= 65 && int(w1) <= 67 && int(w2) >= 65 && int(w2) <= 67) || (w1 == 'D' && w2 == 'F' || w1 == 'F'
	        && w2 == 'D') && flag == 1) {
		cout << 1;
		flag = 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if (flag == 1 && (w1 == 'A' && w2 == 'B' || w1 == 'B' && w2 == 'A' || w1 == 'B' && w2 == 'C' || w1 == 'C'
	                  && w2 == 'B' || w1 == 'D' && w2 == 'F' || w1 == 'F' && w2 == 'D')) {
		cout << 1;
		flag == 1;
	} else {
		cout << 0;
		flag = 0;
	}
	return 0;
}