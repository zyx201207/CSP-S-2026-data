#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
const int MAXN = 505;
inline void fre(){
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    return ;
}
int c, n, m, d, q;
int w[MAXN], k[MAXN];
int a[MAXN][MAXN];
int t[MAXN][MAXN];
int qd, zd;
int fa[MAXN];
int dp[MAXN][MAXN];
inline int minn(int a, int b){
    if (a < b) return a;
    return b;
}
signed main()
{
    fre();
    scanf ("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    memset (dp, 0x3f3f3f3f, sizeof(dp));
    for (rg int i = 1; i <= m; i++){
        scanf ("%lld", &w[i]);
        dp[i][i] = 0;
    }
    for (rg int i = 1; i <= n; i++){
        scanf ("%lld", &k[i]);
        for (rg int j = 1; j <= k[i]; j++){
            scanf ("%lld%lld", &a[i][j], &t[i][j]);
        }
    }
    for (rg int i = 1; i <= n; i++){
        for (rg int j = 1; j < k[i]; j++){
            for (rg int l = j + 1; l <= k[i]; l++){
                dp[a[i][j]][a[i][l]] = minn(dp[a[i][j]][a[i][l]], t[i][j] + t[i][l]);
            }
        }
    }
    for (rg int i = 1; i < m; i++){
        for (rg int j = i + 1; j <= m; j++){
            for (rg int l = i + 1; l < j; l++){
                dp[i][j] = minn(dp[i][j], dp[i][l] + dp[l][j]);
            }
        }
    }
    while (q--){
        scanf ("%lld%lld", &qd, &zd);
        printf ("%lld\n", dp[qd][zd] + w[qd] + w[zd]);
    }
    return 0;
}
