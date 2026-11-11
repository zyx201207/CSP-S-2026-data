#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 5e5 + 10;
LL n, m, c[N], a[N], p[N], v[N], nxt;
bool vis[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (LL i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (LL j = 1; j <= n; j++) {
		memset(vis, 0, sizeof vis);
		memset(p, 0, sizeof p);
		for (LL i = j; i <= n; i++) {
			if (vis[a[i]]) {
				for (LL k = p[a[i]] + 1; k <= nxt; k++) {
					vis[v[k]] = false;
					v[k]=0;
				}
				nxt = p[a[i]];
			} else {
				vis[a[i]] = true;
				p[a[i]] = ++nxt;
				v[nxt] = a[i];
			}
		}
		for (LL i = 1; i <= nxt; i++) {
			c[v[i]]++;
		}
	}
	for (LL i = 1; i <= m; i++) {
		cout << c[i] << " "; 
	}
	return 0;
}
