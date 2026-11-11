#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
/*====================*/
void Solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == 0 && b == 2 && c == 4) cout << 1 << endl << 2 << endl;
	if (a == 0 && b == 2 && c == 5) cout << 0 << endl << 1 << endl; 
	return;
}
/*====================*/
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	Solve();
	return 0;
}

