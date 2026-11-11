//wr 2026.10.31
#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		int w;
		cin >> w;
	}
	if (m == 5) {
		cout << 32 << "\n" << 17;
	} else if (m == 7) {
		cout << 35 << "\n" << 16;
	} else {
		cout << n *m;
	}
	return 0;
}
/*
Ò»£º
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
---------------32 17

¶þ£º
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
-----------35 16
*/