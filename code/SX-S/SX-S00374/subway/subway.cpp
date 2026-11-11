#include <bits/stdc++.h>
using namespace std;
int c;
int m, n;
long long w[50005];
int k[505];
int link_l[505][50005];
int link_s[50005][505];
long long t[505][50005], T;
int d;
int q;
int x, y;
int number;
long long minn = 0x7fffffff;
bool record[50005];

void dfs_common(int NowS, int step) {
	if (step > minn)
		return;
	if (NowS == y)
		minn = step;
	if (NowS == y)
		return;
	for (int i = 1; i <= link_s[NowS][0]; i++) {
		for (int j = 1; j <= link_l[link_s[x][i]][0]; j++) {
			if (record[link_l[link_s[x][i]][j]] == 0) {
				record[link_l[link_s[x][i]][j]] = 1;
				dfs_common(link_l[link_s[x][i]][j], step + t[NowS][link_s[x][i]] + t[link_l[link_s[x][i]][j]][link_s[x][i]]);
				record[link_l[link_s[x][i]][j]] = 0;
			}
		}
	}
}

void dfs_A(int NowS, int step) {
	if (step > minn)
		return;
	if (NowS == y)
		minn = step;
	if (NowS == y)
		return;
	for (int i = 1; i <= link_s[NowS][0]; i++) {
		for (int j = 1; j <= link_l[link_s[x][i]][0]; j++) {
			if (record[link_l[link_s[x][i]][j]] == 0) {
				record[link_l[link_s[x][i]][j]] = 1;
				dfs_A(link_l[link_s[x][i]][j], step + t[NowS][link_s[x][i]] + t[link_l[link_s[x][i]][j]][link_s[x][i]]);
				record[link_l[link_s[x][i]][j]] = 0;
			}
		}
	}
}

void dfs_B(int NowS, int step) {
	if (step > minn)
		return;
	if (NowS == y)
		minn = step;
	if (NowS == y)
		return;
	for (int i = 1; i <= link_s[NowS][0]; i++) {
		for (int j = 1; j <= link_l[link_s[x][i]][0]; j++) {
			if (record[link_l[link_s[x][i]][j]] == 0) {
				record[link_l[link_s[x][i]][j]] = 1;
				dfs_B(link_l[link_s[x][i]][j], step + 1);
				record[link_l[link_s[x][i]][j]] = 0;
			}
		}
	}
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> number;
			link_l[i][link_l[i][0]++] = number;
			link_s[number][link_s[number][0]++] = i;
			cin >> t[i][j];
			T = t[i][j];
		}
	}
	if (c >= 7 && c <= 11) {
		while (q--) {
			cin >> x >> y;
			minn = 0x7fffffff;
			memset(record, 0, sizeof(record));
			record[x] = 1;
			dfs_A(x, 0);
			cout << minn + w[x] + w[y] << endl;
		}
	} else if (c >= 12 && c <= 19) {
		while (q--) {
			cin >> x >> y;
			minn = 0x7fffffff;
			memset(record, 0, sizeof(record));
			record[x] = 1;
			dfs_B(x, 0);
			cout << minn*T + w[x] + w[y] << endl;
		}
	} else if (c >= 20 && c <= 21) {
		while (q--) {
			cin >> x >> y;
			minn = 0x7fffffff;
			if (link_s[x][1] == link_s[y][1]) {
				cout << w[x] + t[x][link_s[x][1]] + t[x][link_s[y][1]] + w[y] << endl;
				continue;
			} else {
				for (int i = 1; i <= link_l[link_s[x][1]][0]; i++) {
					minn = min(minn, t[x][link_s[x][1]] + t[i][link_s[x][1]] + t[i][link_s[y][1]] + t[y][link_s[y][1]]);
				}
				cout << minn + w[x] + w[y] << endl;
			}
		}
	} else if (c >= 22 && c <= 23) {
		while (q--) {
			cin >> x >> y;
			minn = 0x7fffffff;
			memset(record, 0, sizeof(record));
			record[x] = 1;
			dfs_common(x, 0);
			cout << minn + w[x] + w[y] << endl;
		}
	} else {
		while (q--) {
			cin >> x >> y;
			minn = 0x7fffffff;
			memset(record, 0, sizeof(record));
			record[x] = 1;
			dfs_common(x, 0);
			cout << minn + w[x] + w[y] << endl;
		}
	}
	return 0;
}
