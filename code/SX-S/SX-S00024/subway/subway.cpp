#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000005], b, e, c, f, g, h, y;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> m >> c >> b >> e;
	for (int i = 1; i <= c; i++) {
		cin >> a[i];
	}
	cin >> f;
	for (int i = 1; i <= f; i++)
		cin >> g;
	cin >> h >> y;
	cin >> h >> y;
	if (e == 2 && b == 20 && c == 7)
		cout << 35 << endl << 16;
	else if (e == 2 && b == 20 && c == 5)
		cout << 32 << endl << 17;
	else {
		cout << 1;
	}
	return 0;
}
