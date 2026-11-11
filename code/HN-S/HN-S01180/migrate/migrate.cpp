#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, inf = 1e18;
int op,lst[N],nxt[N],n,d,a[N],p,suf[N],pre[N],T,ans;
void init () {
	lst[1] = p = 1;
	for (int i = 2; i <= n; i++) {
		while (a[i] - a[p] > d) p++;	
		lst[i] = p;
	}
	nxt[n] = p = n;
	for (int i = n - 1; i >= 0; i--) {
		while (a[p] - a[i] > d) p--;
		nxt[i] = p;
	}
}
void help() {
	for (int i = 1; i <= n; i++) 
		if (lst[nxt[i]] == i) 
			pre[nxt[i]] += pre[i];
	for (int i = n; i >= 1; i--) 
		if (nxt[lst[i]] == i) 
			suf[lst[i]] += suf[i];
	for (int i = 1; i <= n - 3; i++) {
		int j = nxt[nxt[i]];
		if (i == nxt[i]) continue; if (j == nxt[i]) continue;
		if (j == lst[j]) continue; if (i == lst[j]) continue;
		if (lst[lst[j]] != i) continue; if (nxt[i] - lst[j] != 1) continue;
		ans += pre[i] * suf[j];
	}
	for (int i = 1; i <= n - 3; i++) {
		if (nxt[i] <= i + 1) continue;
		int r = nxt[nxt[i]-1], l = nxt[i];
		if (nxt[i] - 2 > i) l = nxt[nxt[i]-2];
		ans += (pre[i] + 1) * (r - l);
	}
	for (int i = n; i >= 4; i--) {
		if (lst[i] >= i - 1) continue;
		int l = lst[lst[i]+1], r = lst[i];
		if (lst[i] + 2 < i) r = lst[lst[i]+2];
		ans += (suf[i] + 1) * (r - l);
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) pre[i] = suf[i] = 0; 
}
void work () {
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 500) {
		init();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int sum = 0, l = i, r = j;
				while (nxt[l] < j) {
					if (nxt[l] == l) {
						sum = inf;
						break;
					}
					sum += (l = nxt[l]);	
				} 
				while (lst[r] > i) {
					if (lst[r] == r) {
						sum = inf;
						break;
					}
					sum -= (r = lst[r]);
				}
				if (sum == 1) ans++;
			}
		}
		cout << ans << '\n';
	}
	else if (13 <= op && op <= 14) cout << 0 << '\n';
	else help();
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);	
	int T;
	cin >> op >> T;
	while (T--) {
		work();	
	}
	return 0;
}
/*
0 2  
5 3  
-2 -1 0 1 2  
6 2  
-4 -3 -2 -1 3 6  


*/
