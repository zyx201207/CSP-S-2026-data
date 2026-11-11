#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
short c;
int n, m, d, q, w[N], mp[25][25];

struct edge {
	int ll[25], now = 1, t[25];
} station[N];

void solve(int v, int x, int y) {
	int sum = 0;
	sum += w[x];
	sum += w[y];
	if (mp[x][y] != 0) {
		sum += station[x].t[mp[x][y]];
		sum += station[y].t[mp[x][y]];
		cout << sum << "\n";
		return;
	} else if (mp[y][x] != 0) {
		sum += station[x].t[mp[y][x]];
		sum += station[y].t[mp[y][x]];
		cout << sum << "\n";
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (mp[x][i] != 0 && mp[y][i] != 0) {
			sum += station[i].t[mp[x][i]];
			sum += station[i].t[mp[y][i]];
			sum += station[x].t[mp[x][i]];
			sum += station[y].t[mp[y][i]];
			cout << sum << "\n";
			return;
		}
		if (mp[i][x] != 0 && mp[i][y] != 0) {
			sum += station[i].t[mp[i][x]];
			sum += station[i].t[mp[i][y]];
			sum += station[x].t[mp[i][x]];
			sum += station[y].t[mp[i][y]];
			cout << sum << "\n";
			return;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int s = 1; s <= n; s++) {
		int stt;
		cin >> stt;
		for (int i = 1; i <= stt; i++) {
			int x, y;
			cin >> x >> y;
			station[x].ll[station[x].now] = s;
			station[x].now++;
			station[x].t[s] = y;
		}
		for (int i = 1; i <= stt; i++) {
			for (int j = i + 1; j <= stt; j++) {
				mp[i][j] = s;
			}
		}
	}
	for (int r = 1; r <= q; r++) {
		int x, y;
		cin >> x >> y;
		solve(r, x, y);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}