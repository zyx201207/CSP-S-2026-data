#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[5010],dist[5010][5010],op[5010],dp[5010],s[5010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for ( ; t--; ) {
        scanf("%d%lld",&n,&d);
        for (int i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
            int l = 0, r = i;
            while (l + 1 != r) {
                int m = (l + r) / 2;
                if (0LL + a[i] - a[m] <= d)
                    r = m;
                else
                    l = m;
            }
            op[i] = r;
        }
        for (int i = 1; i <= n; i++)
            dist[i][i] = 0LL;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                if (op[j] == j)
                    dist[i][j] = dist[j][i] = 4500000000000000000LL;
                else
                    dist[i][j] = dist[j][i] = dist[i][max(i*1LL,op[j])] + 1;
            }
        long long ans = 0LL;
        for (int i = 1; i <= n; i++) {
            memset(dp,0LL,sizeof(dp));
            memset(s,0LL,sizeof(s));
            dp[i] = 1LL;
            s[i] = 1LL;
            for (int j = i + 1; j <= n; j++) {
                if (a[j] - a[i] <= d) {
                    dp[j] = 1LL;
                    s[j] = s[j-1] + dp[j];
                    continue;
                }
                int L = op[j];
                int l = op[j], r = j;
                while (l + 1 < r) {
                    int m = (l + r) / 2;
                    if (dist[m][j] < dist[L][j])
                        r = m;
                    else
                        l = m;
                }
                int R = l;
                dp[j] = min(s[R]-s[L-1],3LL);
                s[j] = s[j-1] + dp[j];
            }
            for (int j = i; j <= n; j++)
                if (dp[j] == 2)
                    ans++;
        }
        printf("%lld\n",ans);
    }
}
