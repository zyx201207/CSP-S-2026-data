#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			if (int(s1[2]) >= 65 && int(s1[2]) <= 67 && int(s2[2]) >= 65 && int(s2[2]) <= 67) {
				cout << 1;
			} else if (int(s1[2]) == 68 || int(s1[2]) <= 70 || int(s2[2]) == 68 || int(s2[2]) <= 70) {
				cout << 1;
			} else {
				cout << 0;
			}
			if (s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1) {
				cout << 1;
			} else {
				cout << 0;
			}
		}
	} else {
		cout << 0;
	}
	return 0;
}