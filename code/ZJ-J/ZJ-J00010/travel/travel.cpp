#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long a, b, c, d; char e, f;
	cin >> a >> b >> e >> c >> d >> f;
	if (a == c) cout << 1;
	else cout << 0;
	if (a == c && b == d) cout << 1;
	else cout << 0;
	if (a == c && b == d) {
		if ((e <= 'C' && f <= 'C') || (e > 'C' && f > 'C')) cout << 1;
		else cout << 0;
	} else cout << 0;
	if (a == c && b == d && ((e <= 'C' && f <= 'C') || (e > 'C' && f > 'C')) && abs(e - f) == 1 && !((e == 'C' && f == 'D') || (e == 'D' && f == 'C'))) cout << 1;
	else cout << 0;
	return 0;
}
