#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int MAXN = 3e5 + 5;

int n, m;
int a[N];
int t[MAXN];
bool vis[MAXN];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int i = 1;
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		bool s = 1;
		memset(vis, false, sizeof(vis));
		for (int j = 1; j <= n; j++) {
			if (a[j] == a[i] && i != j) {
				for (int k = i; k <= n; k++) {
					if (vis[a[k]] == false) {
						t[a[k]]++;
						vis[a[k]] = true;
					}
				}
				s = 0;
			}
			if (s == 0) {
				break;
			}
		}
		if (s == 1) {
			for (int k = 1; k <= n; k++) {
				if (vis[a[k]] == false) {
					t[a[k]]++;
					vis[a[k]] = true;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << t[i] << " ";
	}
	return 0;
}