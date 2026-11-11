#include <bits/stdc++.h>
#define int long long
using namespace std;
char a, b, c, d;
int r, l, x, s;


signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b >> c >> d;
	
	if (a == c) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	if (b <= 0 && b >= 18) {
		r += b;
	} else if (d <= 0 && d >= 18) {
		l += d;
	} else if (r == l) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	if (r == l && b - d == 1) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	if (b - d == 1) {
		cout << "1";
	}  else {
		cout << "0";
	}
	
	return 0;
}
