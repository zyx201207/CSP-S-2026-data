#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
int c, t, n, d, a[N];
int sum, ans;

void dfs(int now, int go) {
	if (now == go) {
		sum++;
		return ;
	}
	for (int i = now + 1; i <= go; i++) {
		if (a[i] - a[now] <= d)
			dfs(i, go);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (c <= 10) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					sum = 0;
					dfs(i, j);
					if (sum == 2)
						ans++;
				}
			}
		} else if (c <= 12) {
			if (a[2] - a[1] > d)
				ans = 0;
			else {
				int num = d / (a[2] - a[1]);
				if (num == 1)
					ans = 0;
				else
					ans = n - 2;
			}
		} else if (c <= 14)
			ans = n - 2;
	}
	return 0;
}