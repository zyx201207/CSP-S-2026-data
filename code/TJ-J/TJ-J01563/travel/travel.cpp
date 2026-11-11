#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, s1, b, s2;
	cin >> a >> s1 ;
	cin >> b >> s2;
	if (a == b) {
		cout << "1";
		cout << "11";
		if (s1 == s2) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "1";
		cout << "11";
		if (s2 == s1) {
			cout << "1";
		} else {
			cout << "0";
		}
	}

	return 0;
}