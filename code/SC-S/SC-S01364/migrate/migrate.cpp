#include <bits/stdc++.h> 
#define ll long long 
#define rep(i, j, k) for (int i = j; i <= k; i++) 
#define dow(i, j, k) for (int i = j; i >= k; i--) 

const int N = 2e6 + 5; 

int OP, T; 
int n; 
ll d, x[N]; 
int nxt[N]; 
int dis[N], cnt[N]; //1:1 2:2 3:3/4/...

signed main() {
	freopen("migrate.in", "r", stdin); 
	freopen("migrate.out", "w", stdout); 
	
	scanf("%d%d", &OP, &T); 
	while (T--) {
		scanf("%d%lld", &n, &d); 
		rep(i, 1, n) scanf("%lld", x + i); 
		int j = 0; 
		rep(i, 1, n) {
			while (j + 1 <= n && x[j + 1] - x[i] <= d) j++; 
			nxt[i] = j; 
		}
		int ans = 0; 
		dow(r, n, 1) {
			rep(i, 1, n) dis[i] = cnt[i] = 0; 
			dow(l, r, 1) {
				if (nxt[l] >= r) {
					dis[l] = 1; cnt[l] = 1; 
				} else {
					dis[l] = dis[nxt[l]] + 1; 
					cnt[l] = cnt[nxt[l]]; 
					if (nxt[l] - 1 >= l && nxt[l] - 1 > 0 && dis[nxt[l] - 1] == dis[nxt[l]]) cnt[l] += cnt[nxt[l] - 1]; 
					if (nxt[l] - 2 >= l && nxt[l] - 2 > 0 && dis[nxt[l] - 2] == dis[nxt[l]]) cnt[l] += cnt[nxt[l] - 2]; 
				}
				if (cnt[l] == 2) ans++; 
			}
		}
		printf("%d\n", ans); 
	}
	
	return 0; 
}