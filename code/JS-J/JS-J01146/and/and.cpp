#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline int read();
inline void wt(int);
int n,m,a[200005],ans,dp[200005][2505],x;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n = read(),m = read();
    for(register int i = 1;i <= n;++i) a[i] = read();
    if(n == m){
        x = a[1];
        for(int i = 2;i <= n;i++) x &= a[i];
        wt(x);
        return 0;
    }
    for(int i = 1;i <= n;i++) dp[i][1] = max(a[i],dp[i - 1][1]);
    for(int i = 1;i <= n;i++){
        for(int j = 2;j <= m;j++){
            dp[i][j] = dp[i - 1][j];
            for(int k = j-1;k < i;k++) dp[i][j] = max(dp[i][j],dp[k][j - 1] & a[i]);
        }
    }
    ans = 0;
    for(int i = m;i <= n;i++){
        ans = max(ans,dp[i][m]);
    }
    wt(ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

inline int read(){
    register int r;register bool f = 1;register char c;
    while((c = getchar()) && !isdigit(c)) if(c == '-') f^=1;
    r = (c ^ 48);
    while((c = getchar()) && isdigit(c)) r = (r << 3) + (r << 1) + (c ^ 48);
    return r * (f ? 1 : -1);
}
inline void wt(int n){
    if(n < 0) putchar('-'),n = -n;
    if(n > 9) wt(n / 10);
    putchar(n % 10 + 48);
}
