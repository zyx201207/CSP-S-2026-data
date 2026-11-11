#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	int x;
	int y;
	int ax;
	int ay;
	char n;
	char m;
	cin >> x >> ax >> n >> y >> ay >> m;

	if (x == y) {
		cout << 1;
	}
	if (ax == ay) {
		cout << 1;
		if ((n == 'A' && m == 'B') || (n == 'A' && m == 'C') || (n == 'B' && m == 'C') || (n == 'B' && m == 'A') || (n == 'C'
		        && m == 'A') || (n == 'C' && m == 'B') || (n == 'D' && m == 'E') || (n == 'E' && m == 'D')) {
			cout << 1;
			if ((n - 1 == m or m - 1 == n) && (n != 'C' && m != 'D') && (n != 'D' && m != 'C')) {
				cout << 1;
			}
		}
	}
	return 0;
}