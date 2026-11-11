#define NDEBUG
#include<bits/stdc++.h>
#ifdef NDEBUG
#define print(...) void()
#else
#define print(...) void(fprintf(stderr, __VA_ARGS__))
#endif
#define up(i,l,r) for (int i=l; i<=r; ++i)
#define dn(i,r,l) for (int i=r; i>=l; --i)
using ll = long long; using namespace std;
const int N = 505, M = 5e5+5, D = 23;
int C, n, m, d, Q;
ll G[N][N];
int psub[M], sub[M][D], T[M][D], W[M];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> C >> n >> m >> d >> Q;
    up (i, 1, m) cin >> W[i];
    up (i, 1, n){
        int k;
        cin >> k;
        while (k--){
            int x, t;
            cin >> x >> t;
            int p=++psub[x];
            sub[x][p]=i, T[x][p]=t;
        }
    }
    memset(G, 0x3f, sizeof G);
    up (i, 1, n) G[i][i]=0;
    up (i, 1, m)
        up (j, 1, psub[i]) up (k, 1, psub[i]) G[sub[i][j]][sub[i][k]]=min(
            G[sub[i][j]][sub[i][k]], 1ll*T[i][j]+T[i][k]);
    up (k, 1, n) up (i, 1, n) up (j, 1, n) G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    up (i, 1, n) up (j, 1, n) print("G[%d][%d]=%d\n", i, j, G[i][j]);
    while (Q--){
        int x, y;
        cin >> x >> y;
        ll ans=1e18;
        up (i, 1, psub[x]) up (j, 1, psub[y]) ans=min(ans,T[x][i]+T[y][j]+G[sub[x][i]][sub[y][j]]),
        print("%d->%d->%d->%d: %lld\n", x, sub[x][i], sub[y][j], y, T[x][i]+T[y][j]+G[sub[x][i]][sub[y][j]]);
        cout << ans+W[x]+W[y] << "\n";
    }
    return 0;
}