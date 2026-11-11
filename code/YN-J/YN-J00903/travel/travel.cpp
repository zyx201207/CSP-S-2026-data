#include <bits/stdc++.h>
using namespace std;
#define endl '/n'
string c1, c2, s1, s2;
int n1, n2;
char a1, a2;

signed main() {
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1000";
	} else {
		cout << "0000";
	}
	return 0;
}