#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", "stdin");
	freopen("travel.out", "w", "stdout");
	int a, b;
	string s, s1;
	cin >> a >> s >> b >> s1;
	if (a == b) {
		cout << 1;
		if (s[0] == s1[0] && s[1] == s1[1]) {
			cout << 1;
			if (s[2] >= 'A' && s[2] <= 'C' && s1[2] >= 'A' && s1[2] <= 'C') {
				cout << 1;
				if (int(s[2]) == s1[2] - 1 || int(s[2]) == s1[2] + 1)
					cout << 1;
				else
					cout << 0;
			} else if (s[2] == 'D' && s1[2] == 'F')
				cout << 1 << 1;
			else if (s[2] == 'F' && s1[2] == 'D')
				cout << 1 << 1;
			else
				cout << 0 << 0;
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}