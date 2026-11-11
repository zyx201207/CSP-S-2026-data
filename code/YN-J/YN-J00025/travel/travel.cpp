#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int a1[10], a2[10];
char x, y;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	} else {
		for (int i = 0; i < 2; i++) {
			a1[i] = s1[i];
			a2[i] = s2[i];
		}
		int flag = 0;
		for (int i = 0; i < 2; i++) {
			if (a1[i] != a2[i])
				flag = 1;
		}
		if (flag == 1) {
			cout << "1000";
			return 0;
		} else {
			x = s1[2];
			y = s2[2];
			if (((x > 'A' || x == 'A') && (x < 'C' || x == 'C') && (y > 'A' || y == 'A') && (y < 'C' || y == 'C') || (x > 'D'
			        || x == 'D') && (x < 'F' || x == 'F') && (y > 'D' || y == 'D') && (y < 'F' || y == 'F'))) {
				if ((x == 'F' && y == 'D') || (x == 'D' && y == 'F') || (x == 'A' && y == 'B') || (x == 'B' && y == 'A') || (x == 'C'
				        && y == 'B') || (x == 'B' && y == 'C')) {
					cout << "1111";
					return 0;
				} else {
					cout << "1110";
					return 0;
				}
			} else {
				cout << "1100";
				return 0;
			}
		}
	}




	return 0;
}