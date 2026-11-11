#include <bits/stdc++.h>
using namespace std;
int c1, c2, ss, ss1;
char s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> ss >> s1 >> c2 >> ss1 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	} else
		cout << 1;
	if (ss != ss1) {
		cout << "000";
		return 0;
	} else
		cout << 1;
	if ((s1 <= 'C' && s2 <= 'C') || (s1 >= 'D' && s2 >= 'D'))
		cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if (max(s1, s2) - min(s1, s2) == 1 && max(s1, s2) != 'D')
		cout << 1;
	else if (max(s1, s2) - min(s1, s2) == 2 && max(s1, s2) == 'F')
		cout << 1;
	else
		cout << 0;
	return 0;
}