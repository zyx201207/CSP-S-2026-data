#include <bits/stdc++.h>
using namespace std;




int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int l1 = l(s1), l2 = l(s2);
	if (c1 == c2)
		cout << 1;
	else if (c1 != c2) {
		cout << 0;
	}
	if (l1 == l2) {
		cout << 1;
		if (s1[2] - 'A' <= 2 && s2[2] - 'A' <= 2)
			cout << 1;
		else if (s1[2] - 'D' <= 1 && s2[2] - 'D' <= 1)
			cout << 1;
		else
			cout << 0;
	} else if (l1 != l2)
		cout << 0;
	if (s1[2] == 'C' && s2[2] == 'D' || s2[2] == 'C' && s1[2] == 'D')
		cout << 0;
	else if (s1[2] + 1 == int(s2[2]) || s2[2] + 1 == int(s1[2]))
		cout << 1;
	else if (s1[2] + 1 != int(s2[2]) || s2[2] + 1 != int(s1[2]))
		cout << 0;
	return 0;
}