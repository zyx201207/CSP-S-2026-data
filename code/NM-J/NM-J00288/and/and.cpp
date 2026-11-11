#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200100];
int f[2010][2010];
inline bool check1(int x){
    int y = 1;
    for ( int k = 1; ; k++ ){
        y *= 2;
        if ( y >= x ) break;
    }
    if ( x == y - 1 ) return true;
    else return false;
}
inline void education1(){
    int cnt = a[1] & a[2], ans;
    for ( int i = 3; i <= n; i++ )
        cnt &= a[i];
    for ( int i = 1; i <= n; i++ )
        ans = max(ans, cnt & a[i]);
    printf("%lld\n", ans);
    return;
}
inline void education2(){
    sort(a + 1, a + n + 1);
    printf("%lld\n", a[n - m + 1]);
    return;
}
inline void education3(){
    sort(a + 1, a + n + 1);
    int x;
    for ( int i = 1; i <= n; i++ )
        if ( a[i] == 2 || a[i] == 3 ) x++;
    if ( x < m ) printf("0\n");
    else printf("2\n");
    return;
}
inline void education4(){
    memset(f, 0, sizeof(f));
    int x = 0;
    for ( int i = 1; i <= n; i++ ){
    	x = max(x, a[i]);
    	f[i][1] = x;
	}
    for ( int i = 2; i <= n; i++ )
        for ( int j = 2; j <= min(i, m); j++ )
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] & a[i]);
    printf("%lld\n", f[n][m]);
    return;
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    int t1 = 1, t2 = 0;
    for ( int i = 1; i <= n; i++ ){
        scanf("%lld", &a[i]);
        t1 = check1(a[i])? 1: 0;
        t2 = max(t2, a[i]);
    }
    if ( m == n - 1 ) education1();
    else if ( t1 ) education2();
    else if ( t2 < 4 ) education3();
    else education4();
    return 0;
}
