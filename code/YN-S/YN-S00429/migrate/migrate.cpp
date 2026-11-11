#include <bits/stdc++.h>
using namespace std;
int a[1000010], b[1000010];
int n, d, temp = -1e9 - 10, minn = 1e9 + 10;
bool flag = true;

void dfs(int s, int jd, int id, int s1) {
	if (s == jd) {

		b[s1]++;
		minn = min(minn, s1);
		temp = max(temp, s1);
		return;
	}

	for (int i = id + 1; i <= n; i++) {
		if (s + d >= a[i] && a[i]  <= jd) {
			dfs(a[i], jd, id + 1, s1 + 1);
			if (!flag)
				return;
		} else if (s + d < a[id + 1]) {
			flag = false;
			return;
		}
	}
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int cnt = 0;
		cin >> n >> d;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				temp = -1e9 - 10;
				minn = 1e9 + 10;
				flag = true;
				dfs(a[i], a[j], i, 0);
				if (b[minn] == 2) {
					cout << i << " " << j << endl;
					cnt++;
				}
				memset(b, 0, sizeof(b));
			}
		}
		cout << cnt << endl;
	}
	return 0;
}