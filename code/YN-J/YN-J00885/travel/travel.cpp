#include <bits/stdc++.h >
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2, a1;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		a1[1] = '1';
	else
		a1[1] = '0';
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
		a1[2] = '1';
	else
		a1[2] = '0';
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) {
		if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C' && s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
			a1[3] = '1';
		else if (s1[2] == 'E' || s1[2] == 'F' && s2[2] == 'E' || s2[2] == 'F')
			a1[3] = '1';
	} else
		a1[3] = '0';
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && abs(s1[2] - s2[2]) == 1)
		a1[4] = '1';
	else
		a1[4] = '0';
	for (int i = 1; i <= 4; i++) {
		cout << a1[i];
	}
	return 0;
}