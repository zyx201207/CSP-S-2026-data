#include<bits/stdc++.h>
using namespace std;
#define kskblzdjd return 0;
const int N = 8020;
int a[N][N];
long long mapp[N];
long long c, T, py = INT_MAX;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--) {
		long long n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> mapp[i];
			py = min(py, mapp[i]);
		}
		if (py <= 0) {
			for (int i = 1; i <= n; i++) {
				mapp[i] +=1-py;
			}
		}
		memset(a, 0x3f3f3f, sizeof a);
		for (int i = 1; i <= N; i++) {
			a[i][i] = 0;
		}
		sort(mapp + 1, mapp + n + 1);
		for (int i = 1; i <= n; i++) {
			int id = i - 1;
			while (mapp[i] - mapp[id] <= d && id >= 1 && id != 0) {
				a[mapp[i]][mapp[id]] = a[mapp[id]][mapp[i]] = 1;

				id--;
			}
			id = i + 1;
			while (mapp[id] - mapp[i] <= d && id <= mapp[n] && id != n + 1) {
				a[mapp[i]][mapp[id]] = a[mapp[id]][mapp[i]] = 1;

				id++;
			}
		}
		long long zmjjkk = 0;
		for (int u = 1; u <= mapp[n]; u++) {


			for (int v = u + 1; v <= mapp[n]; v++) {
				long long num = 1;
				for (int k = u + 1; k < v; k++) {
					if (a[u][k] + a[k][v] < a[u][v]) {
						a[u][v] = a[v][u] = a[u][k] + a[k][u];
						num = 1;
					} else if (a[u][k] + a[k][v] == a[u][v] && u != v) {
						num++;
					}
				}
				if (num == 2) {
					zmjjkk++;
				}
			}
		}
		cout << zmjjkk << "\n";

	}
	kskblzdjd
}