#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b, o = 0;
	string s, d;
	cin >> a >> s >> b >> d;
	if (a == b) {
		cout << 1;
		if (s[0] == d[0] && s[1] == d[1]) {
			cout << 1;
			if ((s[2] == 'A' && (d[2] == 'B' || d[2] == 'C')) || (s[2] == 'B' && (d[2] == 'A' || d[2] == 'C')) || (s[2] == 'C'
			        && (d[2] == 'A' || d[2] == 'B'))) {
				cout << 1;
				if ((s[2] == 'A' && d[2] == 'B') || (s[2] == 'B' && d[2] == 'C'))
					cout << 1;
				else
					cout << 0;
			} else if ((s[2] == 'D' && d[2] == 'F') || (d[2] == 'D' && s[2] == 'F')) {
				cout << 11;
			} else
				cout << 0 << 0;
		} else
			cout << 0 << 0 << 0;
	} else
		cout << 0 << 0 << 0 << 0;
	return 0;
}