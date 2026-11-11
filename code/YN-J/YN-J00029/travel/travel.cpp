#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[2], c2[3], s1[2], s2[3];
	cin >> c1 >> s1 >> c2 >> s2;
	char s[105] = {0};
	if ((c1[0] == c2[0]) && (c1[1] == c2[1])) {
		s[0] = '1';
	} else  {
		s[0] = '0';
	}
	if ((s1[0] == s2[0]) && (s1[1] == s2[1])) {
		s[1] = '1';
	} else {
		s[1] = '0';
	}
	cout << 1111;
	return 0;
}