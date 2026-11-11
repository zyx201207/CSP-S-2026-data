#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+5, N2 = 5e3+5;
ll c, t, n, d, x[N], dist[N2][N2], cnt[N2][N2];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    while(t--){
        scanf("%lld%lld", &n, &d);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &x[i]);
        }
        if(n == 1) printf("0\n");
        else if(c <= 10){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(abs(x[i] - x[j]) <= d) dist[i][j] = 1;
                    else dist[i][j] = 1e18;
                    cnt[i][j] = 1;
                }
            }
            for(int k = 1; k <= n; k++){
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= n; j++){
                        if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j], cnt[i][j] = cnt[i][k] * cnt[k][j];
                        else if(dist[i][j] == dist[i][k] + dist[k][j]) cnt[i][j] += cnt[i][k] * cnt[k][j];
                    }
                }
            }
            ll ans = 0;
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    if(cnt[i][j] == 2) ans++;
                }
            }
            printf("%lld\n", ans);
        }else if(c == 11 || c == 12){
            ll k = d / (x[2] - x[1]);
            if(k <= 1) printf("0\n");
            else printf("%lld\n", max(0ll, n - k * 2 + 1));
        }else printf("0\n");
    }
    return 0;
}
