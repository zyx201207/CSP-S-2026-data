#include <bits/stdc++.h>
#define int long long
using namespace std;
string a, b, c, d;
bool ok = 0;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c)
		cout << 1;
	else
		cout << 0;
	if (a == c && b[0] == d[0] && b[1] == d[1])
		cout << 1;
	else
		cout << 0;
	if (a == c && b[0] == d[0] && b[1] == d[1]) {
		if (b[2] == 'A')
			if (d[2] == 'B' || d[2] == 'C')
				cout << 1, ok = 1;
			else
				cout << 0;
		else if (b[2] == 'B')
			if (d[2] == 'A' || d[2] == 'C')
				cout << 1, ok = 1;
			else
				cout << 0;
		else if (b[2] == 'C')
			if (d[2] == 'B' || d[2] == 'A')
				cout << 1, ok = 1;
			else
				cout << 0;
		else if (b[2] == 'E')
			if (d[2] == 'F')
				cout << 1, ok = 1;
			else
				cout << 0;
		else if (b[2] == 'F')
			if (d[2] == 'E')
				cout << 1, ok = 1;
			else
				cout << 0;
	} else
		cout << 0;
	if (ok == 1) {
		if (b[2] == 'A') {
			if (d[2] == 'B')
				cout << 1;
			else
				cout << 0;
		} else if (b[2] == 'B') {
			if (d[2] == 'A' || d[2] == 'C')
				cout << 1;
			else
				cout << 0;
		} else if (b[2] == 'C') {
			if (d[2] == 'B')
				cout << 1;
			else
				cout << 0;
		} else if (b[2] == 'E') {
			if (d[2] == 'F')
				cout << 1;
			else
				cout << 0;
		} else if (b[2] == 'F') {
			if (d[2] == 'E')
				cout << 1;
			else
				cout << 0;
		}
	} else
		cout << 0;
	return 0;
}