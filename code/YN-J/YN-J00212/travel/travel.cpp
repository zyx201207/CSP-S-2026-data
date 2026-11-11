#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b, c, d;

int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b >> c >> d;

	//1
	if (a != c) {
		cout << "0000";
		return 0;
	}

	string s1 = b.substr (0, 2);
	string s2 = d.substr (0, 2);

	//2
	if (s1 != s2) {
		cout << "1000";
		return 0;
	}

	//3
	if (b[2] == 'D' || b[2] == 'F') {
		if (d[2] != 'D' && d[2] != 'F') {
			cout << "1100";
			return 0;
		}
	} else {
		if (d[2] == 'D' || d[2] == 'F') {
			cout << "1100";
			return 0;
		}
	}

	//4
	if (b[2] == 'D' || b[2] == 'F') {
		if (d[2] != 'D' && d[2] != 'F') {
			cout << "1110";
			return 0;
		} else {
			cout << "1111";
			return 0;
		}
	} else {
		if (b[2] == 'B' || d[2] == 'B') {
			cout << "1111";
			return 0;
		} else {
			cout << "1110";
			return 0;
		}
	}

	return 0;
}