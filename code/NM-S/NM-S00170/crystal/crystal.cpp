#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500100], ans = 1;
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for ( int i = 1; i <= n; i++ )
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for ( int i = 1; i <= n; i++ ){
    	int cnt = 0, x = i - 1;
    	while(cnt <= m && x >= 1)
			cnt = cnt * 2 + a[x + 1] - a[x--];
		ans = max(ans, i - x);
	}
    printf("%lld\n", ans);
    return 0;
}
