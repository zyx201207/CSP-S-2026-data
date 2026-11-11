#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool a = false, b = false, c = false, d = false;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a = (! c1.compare(c2));
	b = (a && ((s1.at(0) == s2.at(0)) && (s1.at(1) == s2.at(1))));
	if (s1.at(2) == 'A' || s1.at(2) == 'B' || s1.at(2) == 'C') {
		c = b && (s2.at(2) == 'A' || s2.at(2) == 'B' || s2.at(2) == 'C');
	}
	else {
		c = b && (s2.at(2) == 'D' || s2.at(2) == 'F');
	}
	if (c) {
		switch (s1.at(2)) {
			case 'A': {
				d = (s2.at(2) == 'B');
				break;
			}
			case 'B': {
				d = (s2.at(2) == 'A' || s2.at(2) == 'C');
				break;
			}
			case 'C': {
				d = (s2.at(2) == 'B');
				break;
			}
			case 'D': {
				d = (s2.at(2) == 'F');
				break;
			}
			case 'F': {
				d = (s2.at(2) == 'D');
				break;
			}
		}
	}
	printf("%d%d%d%d\n", a, b, c, d);
	return 0;
}
