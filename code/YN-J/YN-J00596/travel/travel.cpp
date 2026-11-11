#include <bits/stdc++.h>
using namespace std;
bool same1 = false, same2 = false, same3 = false, same4 = false;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == 17 && c2 == 17) {
		same1 = true;
		int a1 = s1.end(), a2 = s2.end();
		s1.pop(s1.end());
		s2.pop(s2.end());
		if (s1 == s2) {
			same2 = true;
			if ((a1 <= 'C' && a2 <= 'C') || (a1 >= 'D' && a2 >= 'D')) {
				same3 = true;
				if ((a1 - 'A' == a2 - 'B') || (a1 - 'B' == a2 - 'B')) {
					same4 = true;
				}
			}
		}

	}
	cout << same1 << same2 << same3 << same4;
	return 0;
}