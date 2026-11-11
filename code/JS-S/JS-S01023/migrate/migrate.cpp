#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;
const int N1 = 305;
#define int long long
int a[N],dp[N1][N1],dist[N1][N1];
int n,d,ans;
void solve1(){
    scanf("%lld%lld",&n,&d);
    for (int i = 1;i <= n;i++) scanf("%lld",a + i);
    memset(dp,0,sizeof(dp));
    memset(dist,0x3f,sizeof(dist));
    for (int i = 1;i <= n;i++){
        dist[i][i] = 0,dp[i][i] = 1;
        for (int j = 1;j <= n;j++){
            if (i == j) continue;
            if (abs(a[i] - a[j]) <= d) dist[i][j] = 1,dp[i][j] = 1;
        }
    }
    for (int k = 1;k <= n;k++){
        for (int i = 1;i <= n;i++){
            if (i == k) continue;
            for (int j = 1;j <= n;j++){
                if (i == j || k == j) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dp[i][j] = dp[i][k] * dp[k][j];
                } else if (dist[i][j] == dist[i][k] + dist[k][j]) dp[i][j] += dp[i][k] * dp[k][j];
            }
        }
    }
    ans = 0;
    for (int i = 1;i <= n;i++){
        for (int j = i + 1;j <= n;j++){
            // cerr << i << ' ' << j << ' ' << dp[i][j] << endl;
            if (dp[i][j] == 2) ans++;
        }
    }
    printf("%lld\n",ans);
}
void solve2(){
    scanf("%lld%lld",&n,&d);
    ans = 0;
    for (int i = 1;i <= n;i++) scanf("%lld",a + i);
    for (int i = 1;i < n - 1;i++){
        int l = max((int)(upper_bound(a + 1,a + n + 1,a[i] + d) - a - 1),i + 3ll);
        int r = min(lower_bound(a + 1,a + n + 1,a[i + 1] + d) - a - 1,upper_bound(a + 1,a + n + 1,a[i + 3] + d) - a - 2);
        ans += r - l + 1;
    }
    printf("%d\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    if (c <= 6){
        while(t--) solve1();
    } else if (c == 13 || c == 14){
        while(t--) solve2();
    }
    return 0;
}