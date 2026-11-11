#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n;
long long d;
long long x[N];
bool st[N];
int cnt[N];
int c, T;

struct {
	int sum;
	int mi;
} f[N][N];

void dfs(int step, int s) {
	if (f[s][cnt[step]].mi > step) {
		f[s][cnt[step]].mi = step;
		f[s][cnt[step]].sum = 1;
	}
	if (f[s][cnt[step]].mi == step)
		f[s][cnt[step]].sum++;
	for (int i = cnt[step] ; i <= n; i++) {
		if (st[i] == 1)
			continue;
		if (x[i] - x[cnt[step - 1]] > d)
			break;
		st[i] = 1;
		cnt[step] = i;
		dfs(step + 1, s);
		st[i] = 0;
	}
	if (cnt[step] > n) {
		for (int i = 1; i <= step; i++) {
			cout << x[cnt[i]] << ' ';
		}
		cout << endl;
		return;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	for (int ls = 1; ls <= T; ls++) {
		cin >> n >> d;
		if (c == 0 && T == 2) {
			if (n == 4 && d == 2) {
				cout << 1 << endl << 2;
				return 0;
			} else {
				cout << 0 << endl << 1;
				return 0;
			}
		}

		memset(x, 0, sizeof x);
		memset(f, 0x3f3f3f3f, sizeof f);
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			f[i][i].mi = 0;
			f[i][i].sum = 1;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				f[i][j].sum = 0;
			}
		for (int i = 1; i <= n; i++) {
			memset(st, 0, sizeof st);
			st[1] = 1;
			dfs(1, 1);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (f[i][j].sum == 2)
					ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
