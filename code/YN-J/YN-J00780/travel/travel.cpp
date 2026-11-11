#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s, s1, s2, s3;
	cin >> s >> s1 >> s2 >> s3;
	if (s == s2) {
		cout << 1;
		if (s1[0] == s3[0] && s1[1] == s3[1]) {
			cout << 1;
			if ((s1[2] >= 'A' && s1[2] <= 'C') && (s3[2] >= 'A' && s3[2] <= 'C')) {
				cout << 1;
				int a = int(s1[2]);
				int b = int(s3[2]);
				if (abs(a - b) == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else if ((s1[2] >= 'D' && s1[2] <= 'F') && (s3[2] >= 'D' && s3[2] <= 'F')) {
				cout << 1;
				int a = int(s1[2]);
				int b = int(s3[2]);
				if (abs(a - b) == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;

		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}