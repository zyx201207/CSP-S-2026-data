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
const int N = 2e6+5;
int n; ll d, A[N]; int R[N];
ll f[N][3];
ll get(int u, int l, int r){
    int t=max(r-l,0);
    if (l>=u) return t;
    if (r>=u) return f[u][0]+t;
    if (r>=u-1) return f[u][1]+t;
    return f[u][2]+t;
}
void work(){
    cin >> n >> d;
    up (i, 1, n) cin >> A[i];
    A[0]=-4e18;
    up (i, 1, n){
        for (R[i]=R[i-1]; R[i]<=n&&A[R[i]]-A[i]<=d; ++R[i]);
        --R[i];
    }
    up (i, 1, n) up (j, 0, 2) f[i][j]=0;
    dn (u, n, 2) if (R[u]>u){
        f[u][0]=get(R[u],max(u,R[u-1]), R[u]);
        f[u][1]=get(R[u],max(u,R[u-1]), R[u-1]);
        f[u][2]=get(R[u],max(u,R[u-2]), R[u-1]);
    }
    ll ans=0;
    up (u, 1, n) ans+=get(R[u],u,u);
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int C, T;
    cin >> C >> T;
    while (T--) work();
    return 0;
}