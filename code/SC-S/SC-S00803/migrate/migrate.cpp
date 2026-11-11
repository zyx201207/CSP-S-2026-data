#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
const ll inf = 1e9;
int n, f[N], lef[N], rig[N];
ll d, a[N], g[N], tmp[N];
inline void calc(int st){
    f[st] = 0, g[st] = 1;
    tmp[0] = 1;
    for (int i=st+1, j=st;i<=n;++i){
        while (j<lef[i]){
            if (g[j]) tmp[f[j]] -= g[j];
            ++j;
        }
        if (j!=i&&g[j]) {
            f[i] = f[j]+1, g[i] = tmp[f[j]]>2?inf:tmp[f[j]];
            tmp[f[i]] += g[i];
        }
        else f[i] = inf, g[i] = 0;
    }
    for (int i=max(st, lef[n]);i<=n;++i) if (g[i]) tmp[f[i]] = 0;
}
namespace force{
    void work(){
        // fprintf(stderr, "force\n");
        ll ans = 0;
        for (int i=1;i<=n;++i){
            calc(i);
            for (int j=i;j<=n;++j) ans += g[j]==2;
        }
        cout << ans << '\n';
    }
}
namespace solA{
    inline bool chk(){
        for (int i=1;i<n;++i) if (a[i+1]-a[i]!=a[2]-a[1]) return 0;
        return 1; 
    }
    void work(){
        // fprintf(stderr, "solA\n");
        calc(1);
        int sum = 0;
        for (int i=1;i<=n;++i) sum += g[i]==2;
        ll ans = 0;
        for (int i=1;i<=n;++i) {
            ans += sum, sum -= g[n-i+1]==2;
        }
        cout << ans << '\n';
    }
}
namespace solB{
    int g[N];
    inline bool chk(){
        for (int i=1;i<=n;++i) if (a[i]-a[1]<=d&&a[n]-a[i]<=d) return 1;
        return 0;
    }
    void work(){
        // fprintf(stderr, "solB\n");
        for (int i=1;i<=n;++i) g[i] = 0;
        for (int i=1;i<=n;++i) ++g[lef[i]];
        ll ans = 0;
        for (int i=1;i<=n;++i){
            int tmp = rig[i];
            if (tmp==i||tmp==i+1) continue;
            ans += g[tmp-1];
        }
        cout << ans << '\n';
    }
}
void solve(){
    cin >> n >> d;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1, j=1;i<=n;++i){
        while (j<n&&a[j+1]-a[i]<=d) ++j;
        rig[i] = j;
    }
    for (int i=n, j=n;i>=1;--i){
        while (j>1&&a[i]-a[j-1]<=d) --j;
        lef[i] = j;
    }
    if (solA::chk()) solA::work();
    else if (solB::chk()) solB::work();
    else force::work();
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int c, t; cin >> c >> t;
    while (t--) solve();
    return 0;
}