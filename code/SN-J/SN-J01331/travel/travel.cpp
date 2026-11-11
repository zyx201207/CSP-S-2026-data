#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string a, b, c, d; 
int main() {
	freopen("travel.in", "r", stdin); freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b >> c >> d;
	if (a != c) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	if (b.substr(0, 2) != d.substr(0, 2)) {
		cout << "000";
		return 0;
	}
	cout << 1;
	char L = b[2], R = d[2];
	bool lt = ('A' <= L && L <= 'C' && 'A' <= R && R <= 'C');
	bool rt = ('D' <= L && L <= 'F' && 'D' <= R && R <= 'F');
	bool same_side = (lt || rt);
	if (!same_side) {
		cout << "00";
		return 0;
	}
	cout << 1;
	if ((lt && abs(R - L) == 1) || (rt && abs(R - L) == 2)) cout << 1;
	else cout << 0;
	return 0;
}
