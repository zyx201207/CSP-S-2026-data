#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 5e3 + 5;
ll a[N];
int n;
ll d;
const int MAX = 0x3f3f3f3f;
int minD(int u, int v){
    for(int i = 1; u <= v; i++){
        const int nxt = std::upper_bound(a + 1, a + n + 1, a[u] + d) - a - 1;
        if(nxt >= v) return i;
        else u = nxt;
    }
    return MAX;
}
int dis[N][N];
ll cnt[N];
int qp[N], qd[N];
int fr = 1, tl = 0;
bool check(int u, int v){
    fr = 1, tl = 0;
    for(int i = u; i <= v; i++) cnt[i] = 0;
    qp[++ tl] = u;
    qd[tl] = 0;
    cnt[u] = 1;
    while(fr <= tl){
        const int pre = qp[fr], ds = qd[fr ++];
        if(ds > dis[u][pre]) break;
        for(int i = pre + 1; i <= v; i++){
            if(a[i] - a[pre] > d) break;
            qp[++ tl] = u;
            qd[tl] = ds + 1;
            cnt[tl] += cnt[pre];
        }
    }
    return cnt[v] == 2;
}
void solve(){
    scanf("%d %lld", &n, &d);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            dis[i][j] = minD(i, j);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 2; j <= n; j++){
            cnt += check(i, j);
        }
    }
    printf("%d\n", cnt);
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while(t--) solve();
    
    return 0;
}