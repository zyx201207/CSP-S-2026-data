#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
const int N = 5e3 + 10;
int c,t,n,d,a[N],f[N][N],cnt[N][N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(i != j) f[i][j] = INF,cnt[i][j] = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++)
                if(abs(a[j] - a[i]) <= d) f[i][j] = f[j][i] = cnt[i][j] = cnt[j][i] = 1;
        for(int k = 1;k <= n;k++)
            for(int i = 1;i <= n;i++)
                for(int j = 1;j <= n;j++)
                    if(f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j],cnt[i][j] = cnt[i][k] * cnt[k][j];
                    else if(f[i][k] + f[k][j] == f[i][j]) cnt[i][j] += cnt[i][k] * cnt[k][j];
        int ans = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++)
                if(cnt[i][j] == 2) ans++;
        cout << ans << "\n";
    }
    return 0;
}
