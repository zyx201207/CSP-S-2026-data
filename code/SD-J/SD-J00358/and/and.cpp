#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+2;
int n, m, a[N], f[N];
//bool vis[N];
//int cnt, ans=-1;
//void dfs(int k) {
//	cnt = 0;
//	if(k > m) {
//		cnt = f[1];
//		for(int i=2; i<=n; i++) {
//			cnt &= f[i];
//		}
//		ans = max(ans, cnt);
//	}
//	for(int i=1; i<=n; i++) {
//		if(vis[i] == 0) {
//			vis[i] = 1;
//			f[k] = a[i];
//			dfs(k+1);
//			vis[i] = false;
//		}
//	}
//}
int cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	int ans = a[1];
	sort(a+1,a+n+1,cmp);
	for(int i=2; i<=m; i++) ans &= a[i];
	cout << ans <<'\n';
	return 0;
}
/*
5 3
31 3 1 15 7
*/
