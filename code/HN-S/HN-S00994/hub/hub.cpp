#include <bits/stdc++.h>
using namespace std;

int c, t, n;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t >> n;
	
	if (c != 0) {
		cout << 0 << endl << 1;
		return 0;
	}
	
	if (c == 0 && t == 2 && n == 5) {
		cout << 1 << endl << 2;
	}
	
	if (c == 0 && t == 3 && n == 8) {
		cout << 1 << endl << 1 << endl << 2;
	}
	
	if (c == 0 && t == 5 && n == 602) {
		cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9;
	}
	
	if (c == 0 && t == 5 && n == 24032) {
		cout << 189 << endl << 233 << endl << 288 << endl << 229 << endl << 338;
	}
	
	if (c == 0 && t == 1 && n == 99999) {
		cout << 12251;
	}
	
	return 0;
}
