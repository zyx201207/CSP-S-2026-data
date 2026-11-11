#include <bits/stdc++.h>
using namespace std;
int a[300000];
int t[300000];
int vis[300000];
int n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (vis[j] != 0) {
				for (int z = vis[j]; z <= j - 1; z++) {
					vis[z] = 0;
				}
			} else {
				vis[j] = j;
			}
		}
		for (int j = i; j <= n; j++) {
			if (vis[j] == 1) {
				t[j]++;
			}
			vis[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << t[i] << " ";
	}
}