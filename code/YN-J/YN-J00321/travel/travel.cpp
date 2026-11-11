#include <bits/stdc++.h>
using namespace std;
string z, z1, h, h2, s, s1;

int q[4] = {0, 0, 0, 0};

bool f(char a, char b) {
	if (a == 'A' || a == 'B' || a == 'C' && b == 'A' || b == 'B' || b == 'C')
		return true;
	else if (a == 'D' || a == 'F' && b == 'D' || b == 'F')
		return false;
	else
		return false;
}

bool f1(char a1, char b1) {
	int x, x1;
	x = int(a1), x1 = int(b1);
	if (x - 1 == x1 || x + 1 == x1)
		return true;
	else
		return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> z >> h >> z1 >> h2;
	s = h.substr(0, 2);
	s1 = h2.substr(0, 2);
	if (z == z1) {
		q[0]++;
		if (s == s1) {
			q[1]++;
			if (f(h[2], h2[2])) {
				q[2]++;
				if (f1(h[2], h2[2])) {
					q[3]++;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (q[i] != 0)
			cout << "1";
		else
			cout << "0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}