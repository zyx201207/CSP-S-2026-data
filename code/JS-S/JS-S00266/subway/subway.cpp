#include <bits/stdc++.h>
#define int unsigned long long
#define gc getchar
const int N = 5e5 + 10;

using namespace std;
namespace Sol{

int rd(){
    char c = gc(); int re = 0;
    while(c < '0' || c > '9') c = gc();
    while(c >= '0' && c <= '9')
        re = re * 10 + c - '0', c = gc();
    return re;
}

int a[510][510], w[N];
struct XL{int v, t;};
vector<XL> g[N];

void main(){
    #ifdef LOCAL
    freopen("subway7.in", "r", stdin);
    freopen("x.out", "w", stdout);
    #else
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(a, 0x3f, sizeof a);
    int C = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    for(int i=1; i<=m; i++) w[i] = rd();
    for(int i=1, k; i<=n; i++){
        k = rd();
        for(int v, t; k; k--) 
            v = rd(), t = rd(), g[v].push_back({i, t});
    }
    for(int i=1; i<=n; i++) a[i][i] = 0;
    for(int i=1, u, v, tu, tv; i<=m; i++){
        for(auto p1: g[i]){
            u = p1.v, tu = p1.t;
            for(auto p2: g[i])
                v = p2.v, tv = p2.t,
                a[u][v] = min(a[u][v], tu+tv);
        }
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++) cout << a[i][j] << ' ';
    //     cout << '\n';
    // }
    for(int x, y, u, v, tu, tv, re; q; q--){
        x = rd(), y = rd(), re = a[0][0];
        for(auto p1: g[x]){
            u = p1.v, tu = p1.t;
            for(auto p2: g[y])
                v = p2.v, tv = p2.t,
                re = min(a[u][v]+tu+tv, re);
        }
        cout << re + w[x] + w[y] << '\n';
    }
}

}signed main(){Sol::main();}