#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int s, x, a;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i <= 1; i++) {
		x += s1[i] - '0';
		a += s2[i] - '0';
	}
	if (x != a) {
		cout << "1000";
		return 0;
	}
	int b = s1[2] - 'A';
	int c = s2[2] - 'A';
	if (b + c == 5) {
		cout << "1100";
		return 0;
	}
	if (abs(b - c) < 2)
		cout << "1111";
	else
		cout << "1110";
	return 0;
}