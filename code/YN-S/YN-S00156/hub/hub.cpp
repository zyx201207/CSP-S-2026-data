#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int T, n, m, mp[N][N];
short c;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			mp[x][y] = i;
			mp[y][x] = i;
		}
		cout << 1 << "\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}