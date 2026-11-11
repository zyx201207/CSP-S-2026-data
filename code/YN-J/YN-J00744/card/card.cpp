#include <bits/stdc++.h>
using namespace std;
int a[100000], cnt[100000], vis[100000];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++)
			cnt[a[j]]++;
		for (int j = i; j <= n; i++) {
			vis[j] = j;
			for (int z = j + 1; z <= n; i++)
				if (a[z] == a[j] && z > vis[a[z]]) {
					for (int s = z - 1; s >= vis[z]; s--)
						cnt[a[s]]--;
					vis[a[z]] = z;
				}
		}
	}

	for (int i = 1; i <= m; i++)
		cout << cnt[i] << ' ';
	return 0;
}