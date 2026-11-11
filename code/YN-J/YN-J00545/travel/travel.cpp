#include <bist/std.c++.h>
using namespace std;


int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1, s2;
	char a, b;
	int c1, c2;
	cin >> c1 >> s1 >> c2 >> s2;
	s1[3] = a;
	s2[3] = b;

	if (a1 == b1) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}

	if (s1[1] == s2[1] && s1[2] == s2[2]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}

	if ('A' <= a <= 'C' && 'A' <= b <= 'C' || 'D' <= a <= 'F' && 'D' <= b <= 'F') {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}

	if (a - 1 == b || a + 1 == b) {
		cout << "1";
	} else {
		cout << "1110";
		return 0;
	}

	return 0;
}