#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, n;
ll d;
ll x[1000006];
bool mp[5005][5005];
ll ans = 0;
int q[100005], hh, tt, dis[5005], tmes[5005], res;

void bfs(int s) {
	hh = 1;
	tt = 0;
	q[++tt] = s;
	dis[s] = 0;
	while (hh <= tt) {
		int u = q[hh++];
		for (int i = u + 1; i <= n; i++) {
			if (!mp[u][i])
				break;
			if (dis[i] != 1145141919) {
				if (tmes[i] == 1)
					--res;
				if (dis[i] == dis[u] + 1)
					tmes[i]++;
				if (tmes[i] == 1)
					++res;
//				cout << i << " ";
				continue;
			}
			q[++tt] = i;
			dis[i] = dis[u] + 1;
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _ = 1;
	cin >> c >> _;
	while (_--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (c <= 10) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (abs(x[j] - x[i]) <= d)
						mp[i][j] = 1;
					else
						break;
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dis[j] = 1145141919;
					tmes[j] = 0;
				}
				res = 0;
				bfs(i);
//				cout << "\n";
				ans += res;
			}
			cout << ans << "\n";
		} else if (c == 13 || c == 14) {
			int imp;
			for (int i = 1; i <= n; i++) {
				if (abs(x[1] - x[i]) <= d && abs(x[n] - x[i]) <= d) {
					imp = i;
					break;
				}
			}
			for (int i = 1; i < imp; i++) {
				if (abs(x[imp + 1] - x[i]) <= d) {
					if (abs(x[imp + 2] - x[i]) <= d)
						continue;
					ans += n - imp - 1;
				}
			}
			for (int i = imp + 1; i <= n; i++) {
				if (abs(x[imp - 1] - x[i]) <= d) {
					if (abs(x[imp - 2] - x[i]) <= d)
						continue;
					ans += imp - 2;
				}
			}
			cout << ans << "\n";
//		} else if (c==11 || c==12){
//			int dd=x[2]-x[1];

//		}
			else {
				cout << 0 << "\n";
			}
		}
	}
	/*
	0 2
	4 2
	1 2 3 4
	5 2
	1 2 3 4 5

	0 1
	5 2
	1 2 3 4 5
	*/