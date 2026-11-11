#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p, ans;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int k;
	int x, y;
	cin >> c >> n >> m >> d >> p >> k >> ans;
	for (int i = 1; i <= n; i++) {
		x++;
		for (int i = 0; i <= m; i++) {
			y += 2;
		}
	}
	cout << x << " " << y;
	return 0;
	fclose(stdin);
	fclose(stdout);
}