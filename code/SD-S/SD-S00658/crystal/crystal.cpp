#include <iostream>
#include <algorithm> 
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn] , sum[maxn];
signed main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios :: sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
	int n , m , ans = 0 ; cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i ++) sum[i] = sum[i - 1] + a[i];
	int pos = 1;
	for(int i = 1 ; i <= n ; i ++) {
		while(a[i] * (i - pos + 1) - sum[i] + sum[pos - 1] > m) ++ pos;
		ans = max(ans , i - pos + 1); 
	} cout << ans << endl;
	return 0;
} 
