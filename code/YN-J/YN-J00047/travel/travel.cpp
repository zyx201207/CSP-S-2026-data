#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool a[4];

bool b(char x, char y) {
	int a = 0, b = 0;
	if (x == 'A' || x == 'B' || x == 'C')
		a = 1;
	if (y == 'A' || y == 'B' || y == 'C')
		b = 1;
	if (a == b)
		return 1;
	else
		return 0;
}

bool c(char x, char y) {
	if (x + 1 == y || x - 1 == y)
		return 1;
	else
		return 0;

}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		a[0] = 1;
		if (s1[1] == s2[1]) {
			a[1] = 1;
			if (b(s1[2], s2[2])) {
				a[2] = 1;
				if (c(s1[2], s2[2]))
					a[3] = 1;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		cout << a[i];
	return 0;
}