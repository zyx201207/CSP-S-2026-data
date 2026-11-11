#include <bits/stdc++.h>
using namespace std;
string c1, c2, c3, c4;
bool f, f2, f3, f4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1 == c3) {
		f = 1;
	}
	if (f && c2[0] == c4[0] && c2[1] == c4[1]) {
		f2 = 1;
	}
	if (f2 && ((c2[2] <= 'C' && c4[2] <= 'C') || (c2[2] >= 'D' && c2[2] <= 'F' && c4[2] >= 'D' && c4[2] <= 'F'
	           && c2[2] != 'E' && c4[2] != 'E'))) {
		f3 = 1;
	}
	if (f3 && (c2[2] >= 'D' || c2[2] == 'B' || c4[2] == 'B')) {
		f4 = 1;
	}
	cout << f << f2 << f3 << f4;
	return 0;
}