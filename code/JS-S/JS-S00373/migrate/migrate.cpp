//WA and TLE automation
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
int n, C;
const int N = 2e6+5;
ll d, x[N];
ll dis[N], cnt[N];
void solve() {
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    //sort(x+1, x+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++) {
        memset(dis, 0x3f, sizeof(dis));
        for(int j=i;j<=n;j++) {
            for(int k=j+1;k<=n;k++) {
                if(x[k]-x[j]>d) break;
                if(dis[k]> dis[j]+x[k]-x[j]) {
                    dis[k] = dis[j]+x[k]-x[j];
                    cnt[k] = 1;
                }
                if(dis[k]== dis[j]+x[k]-x[j]) cnt[k]++;
            }
        }
        for(int j=i;j<=n;j++) if(cnt[j]==2) ans++;
    }
    cout<<ans<<'\n';
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>C>>t;
    while(t--) solve();
    return 0;
}