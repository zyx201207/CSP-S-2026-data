#include<bits/stdc++.h>
using namespace std;

bool MST;
string c1, s1, c2, s2;
struct node {
	int x, y;
	void ck(string s) {
		int _x = s[0] - '0', _y = s[2] - 'A' + 1;
		_x *= 10;
		_x += s[1] - '0';
		x = _x, y = _y;
	}
} a, b;
void solve_() {
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		a.ck(s1);
		b.ck(s2);
		if (a.x == b.x) {
			if ((a.y <= 3 && b.y <= 3) || (a.y >= 4 && b.y >= 4)) {
				if (abs(a.y - b.y) == 1) {
					cout << "1111\n";
				} else {
					cout << "1110\n";
				}
			} else {
				cout << "1100\n";
			}
		} else {
			cout << "1000\n";
		}
	} else {
		cout << "0000\n";
	}
}
bool MED;
signed main() {
//	cerr << abs(&MST - &MED) / 1024 / 1024 << "MB\n";
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve_();
	return 0;
}
