#include <bits/stdc++.h>
#define int long long
using namespace std;

int c1, c2;
string a, b;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> a >> c2 >> b;
	if (c1 != c2) {
		cout << "0000";
	} else if (a[0] != b[0] || a[1] != b[1]) {
		cout << "1000";
	} else if ((a[2] <='C') != (b[2] <= 'C')) {
		cout << "1100";
	} else if ((a[2] != 'B') && (b[2] != 'B') && (a[2] <= 'C')) {
		cout << "1110";
	} else {
		cout << "1111";
	}
	return 0;
} 
