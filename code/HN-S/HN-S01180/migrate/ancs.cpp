#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, inf = 1e18;
int op,lst[N],nxt[N],n,d,a[N],p,suf[N],pre[N],T;
void init () {
	lst[1] = p = 1;
	for (int i = 2; i <= n; i++) {
		while (a[i] - a[p] > d) p++;	
		lst[i] = p, suf[p]++;
	}
	nxt[n] = p = n;
	for (int i = n - 1; i >= 1; i--) {
		while (a[p] - a[i] > d) p--;
		nxt[i] = p, pre[p]++;
	}
}
void work () {
	int ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	init();
	for (int i = 1; i <= n; i++) 
		if (lst[nxt[i]] == i) 
			pre[nxt[i]] += pre[i];
	for (int i = n; i >= 1; i--) 
		if (nxt[lst[i]] == i) 
			suf[lst[i]] += suf[i];
	
	for (int i = 1; i <= n - 3; i++) {
		if (a[i+3] - a[i] <= d) continue;
		if (a[i+2] - a[i] > d) continue;	
		if (a[i+3] - a[i+1] > d) continue;	
		ans += (pre[i] * suf[i+3] + suf[i+3] + pre[i] + 1);	
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) pre[i] = suf[i] = 0; 
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate4.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);	
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
0 1
5 2
1 2 3 4 5

*/
