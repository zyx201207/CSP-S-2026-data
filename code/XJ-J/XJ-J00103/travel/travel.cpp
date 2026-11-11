#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1, c2;
	int s1, s2, s3, s4;
	cin >> s1 >> s2 >> c1 >> s3 >> s4 >> c2;
	if (s1 != s3) {
		cout << "0000";
		return 0;
	}
	else cout << "1";
	if (s2 != s4) {
		cout << "000";
		return 0;
	}
	else cout << "1";
	if ((c1 >= 'D' && c2 <= 'C') || (c1 <= 'C' && c2 >= 'D')) {
		cout << "00";
		return 0;
	}
	else cout << "1";
	if ((c1 == 'A' && c2 == 'C') || (c1 == 'C' && c2 == 'A')) {
		cout << "0";
		return 0;
	}
	else cout << "1";
	return 0;
}
