#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000001], vis[1000001], j = 1, o[1000001], dis[1000001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (j <= n) {
		for (int i = j; i <= n; i++) {
			if (vis[a[i]] == 0) {
				vis[a[i]] = 1;
				dis[a[i]] = i;
			} else {
				for (int l = dis[a[i]]; l < i; l++) {
					vis[a[l]] = 0;
				}
				vis[a[i]] = 1;
				dis[a[i]] = i;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (vis[a[i]] == 1) {
				vis[a[i]] = 0;
				o[a[i]]++;
			}
		}
		j++;
	}
	for (int i = 1; i <= m; i++) {
		cout << o[i] << " ";
	}
	return 0;
}