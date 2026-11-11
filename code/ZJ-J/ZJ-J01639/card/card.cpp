#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+2;

int n, m;
int a[N];
int vis[N], ans[N];

signed main () {
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 3
	}
	
	if (m == 1) {
		cout << n;
		return 0;
	}
	
	for (int i = n; i >= 1; i--) {
		int x = a[i];
		if(vis[x]) {
			for (int j = i+1; j <= n; j++) {
				vis[a[j]] = 0;
				if (a[j] == x) break;
			}
		}
		vis[x] = 1;
		for (int i = 1; i <= m; i++) {
			ans[i] += vis[i];
		}
	}
	
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}

