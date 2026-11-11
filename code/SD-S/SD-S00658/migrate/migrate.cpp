#include <iostream>
#define int long long
using namespace std;
const int maxn = 2e6 + 5 , inf = 5e18;
int x[maxn] , pre[maxn] , nxt[maxn] , linepre[maxn] , linenxt[maxn] , sp[maxn] , sn[maxn];
void solve() {
	int n , d , ans = 0 ; cin >> n >> d;
	for(int i = 1 ; i <= n ; i ++) cin >> x[i] , sp[i] = sn[i] = 0;
	x[0] = -inf , x[n + 1] = inf;
	int pos = 0;
	for(int i = 1 ; i <= n ; i ++) {
		while(x[i] - x[pos] > d) ++ pos; 
		pre[i] = pos;
	} pos = n + 1;
	for(int i = n ; i >= 1 ; i --) {
		while(x[pos] - x[i] > d) -- pos;
		nxt[i] = pos;
	} for(int i = 1 ; i <= n ; i ++) 
		linepre[i] = (x[i] - x[i - 1] <= d && x[i + 1] - x[i - 1] > d) ? linepre[i - 1] : i;
	for(int i = n ; i >= 1 ; i --)
		linenxt[i] = (x[i + 1] - x[i] <= d && x[i + 1] - x[i - 1] > d) ? linenxt[i + 1] : i;
	for(int i = 1 ; i <= n ; i ++) sp[i] = sp[i - 1] + (i - linepre[i] + 1);
	for(int i = n ; i >= 1 ; i --) sn[i] = sn[i + 1] + (linenxt[i] - i + 1);
	for(int i = 1 ; i <= n - 3 ; i ++) {
		int p1 = i , p2 = i + 1 , p3 = i + 2 , p4 = i + 3;
		ans += (sp[pre[p4] - 1] - sp[pre[p3] - 1]) * (sn[nxt[p1] + 1] - sn[nxt[p2] + 1]); 
	} cout << ans << endl; 
}
signed main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios :: sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
	int c , t ; cin >> c >> t; 
	while(t --) solve();
	return 0; 
} 
