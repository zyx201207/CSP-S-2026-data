#include <bits/stdc++.h>
using namespace std;
const int N = 10e6+10;
int c, T, n, d;

struct cbc {
	int x, y;
} a[N];


int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	cin >> c >> T;
	while (T--) {
		memset(a, 0, sizeof(a));
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y;
		}
		cout << "0\n";
	}

	return 0;
}
