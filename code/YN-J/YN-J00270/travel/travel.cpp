#include <bits/stdc++.h>
using namespace std;
int c1, c2;
int p1, p2;
char s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1;
	cin >> p1;
	cin >> s1;
	cin >> c2;
	cin >> p2;
	cin >> s2;
	if (c1 == c2) {
		if (p1 == p2) {
			if (((s1 >= 'A' && s1 <= 'C') && (s2 >= 'A' && s2 <= 'C')) || ((s1 >= 'D' && s1 <= 'F') && (s2 >= 'D' && s2 <= 'F'))) {
				if (abs(s1 - s2) == 1) {
					cout << "1111";
				} else
					cout << "1110";
			} else
				cout << "1100";
		} else
			cout << "1000";
	} else
		cout << "0000";
	return 0;
}