#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;



int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int lenn1 = s1.length(), lenn2 = c1.length();
	for (int i = 0; i < lenn2; i++) {
		if (c1[i] != c2[i]) {
			cout << 0  << 0 << 0  << 0;
			return 0;
		}
	}
	for (int i = 0; i < lenn1 - 1; i++) {
		if (s1[i] != s2[i]) {
			cout << 1000;
			return 0;
		}
	}

	char fir = s1[lenn1 - 1], sec = s2[lenn1 - 1] ;
	if ((fir == 'A' || fir == 'B' || fir == 'C') && (sec == 'D' || sec == 'E')) {
		cout << 1  << 1 << 0  << 0;
		return 0;
	}
	if (!(((fir == 'A') && (sec == 'B')) || ((fir == 'B') && (sec == 'A' || sec == 'C')) || ((fir == 'C') && (sec == 'B'))
	        || ((fir == 'D') && (sec == 'F')) || ((fir == 'F') && sec == 'D'))) {
//		cout << fir << " " << fir + 1 << " " << sec << " " << sec - '0' << endl;
		cout << 1  << 1 << 1  << 0;
		return 0;

	}

	cout << 1 << 1 << 1 << 1;
	return 0;
}