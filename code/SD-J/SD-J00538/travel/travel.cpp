#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool hhh1(char c1, char c2) {
	if (c1 == 'A') {
		if (c2 == 'B' || c2 == 'C') return 1;
		else return 0;
	}
	if (c1 == 'B') {
		if (c2 == 'A' || c2 == 'C') return 1;
		else return 0;
	}
	if (c1 == 'C') {
		if (c2 == 'A' || c2 == 'B') return 1;
		else return 0;
	}
	if (c1 == 'D') {
		if (c2 == 'F') return 1;
		else return 0;
	}
	if (c1 == 'F') {
		if (c2 == 'E') return 1;
		else return 0;
	}
}
bool hhh2(char c1, char c2) {
	if (c1 == 'A' && c2 == 'C' || c1 == 'C' && c2 == 'A') return 0;
	else return 1;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		char tx1 = s1[0], ty1 = s1[1];
		char tx2 = s2[0], ty2 = s2[1];
		if (tx1 == tx2 && ty1 == ty2) {
			cout << 1;
			if (hhh1(s1[2], s2[2])) {
				cout << 1;
				if (hhh2(s1[2], s2[2])) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
