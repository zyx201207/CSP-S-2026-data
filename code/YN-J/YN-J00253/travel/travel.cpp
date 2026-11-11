//2026.10.31  zyb  travel
#include <bits/stdc++.h>
using namespace std;
int c1, c2, l1, l2;
char s1, s2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> l1 >> s1 >> c2 >> l2 >> s2;
	if (s1 == 'D')
		s1 = 'E';
	if (s2 == 'D')
		s2 = 'E';
	if (c1 != c2) {
		cout << "0000\n";
	} else if (l1 != l2) {
		cout << "1000\n";
	} else if (min(s1, s2) < 'D' && max(s1, s2) > 'D') {
		cout << "1100\n";
	} else {
		cout << "111";
		cout << (abs((int)s1 - s2) == 1) << '\n';
	}
	return 0;
}