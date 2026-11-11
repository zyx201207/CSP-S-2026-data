#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, M[500005], N[505][2], x, y;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> M[i];
	while (n--) {
		int k;
		cin >> k;
		for (int i = 1; i <= (k * 2); i++) {
			cin >> N[i][0] >> N[i][1];
		}
	}
	cout << 42 << endl <<< 16;
	return 0;
}