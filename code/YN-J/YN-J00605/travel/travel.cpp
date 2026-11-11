#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r", stdin);
	freopen("travel.out","w", stdout);
	string a1, a2, s1, s2;
	cin >> a1 >> a2 >> s1 >> s2;

	if (a1 == s1) {
		if (a2 - s2 == 1 || s2 - a2 == 1) {
			cout << 1111;
			return 0;
		} else {
			cout << 1110;
			return 0;
		}
	} else {
		cout << 0000;
	}

	return 0;
}
