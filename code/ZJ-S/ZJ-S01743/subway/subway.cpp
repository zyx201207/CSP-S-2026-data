#include<bits/stdc++.h>
#define FL(a, b, c) for(int a = (b), a##end = (c); a <= a##end; ++a)
#define FR(a, b, c) for(int a = (b), a##end = (c); a >= a##end; --a)
#define endl '\n'
#define fr first
#define se second
#define int long long
using namespace std;
constexpr int N = 5e5 + 10, M = 600;
vector<pair<int, int>> df[N];
int CCC, n, m, d, q, wfjfjj[N], L[N], R[N];
int W[M][M], tot, dis[M][M];
// pair<int, int>df[N];
inline bool cmin(int&x, int y){if(x > y)return x = y, 1;return 0;}
void add(int u, int v, int w){
    cmin(W[u][v], w);
    // cerr << u << " " << v << " " << w << endl;
    // U[++tot] = u, V[tot] = v, W[tot] = w, G[u]++;
}
void dij(int s){
    R[0] = 1;
    FL(i, 1, 501)
    L[i] = i - 1,
    R[i] = i + 1;
    dis[s][s] = 0;
    // priority_queue<pair<int, int>> q;
    // q.emplace(0, s);
    while(1){
        int x = 0, g = 1e18, y = R[0];
        while(y <= n){
            if( g > dis[s][y])g = dis[s][y], x = y;
            y = R[y];
        }
        FL(i, 1, n)
        if(!x)return;
        // cerr << d << " " << x << " " << q.size() << endl;
        // if(q.pop(), d != dis[s][x])continue;
        R[L[x]] = R[x], L[R[x]] = L[x];
        for (int i = R[0]; i <= n; i = R[i])
            cmin(dis[s][i], dis[s][x] + W[x][i]);
        // q.emplace(-dis[s][i], i);
        // cout << endl;
        // FL(i, G[x] + 1, G[x + 1])if(dis[s][v = e[i].fr - n] > dis[s][x] + (w = e[i].se))
        //     dis[s][v] = dis[s][x] + w, ;
    }
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    // freopen("1.out", "w", stdout);
    // auto st = clock();
    cin >> CCC >> n >> m >> d >> q;
    FL(i, 1, m)cin >> wfjfjj[i];
    FL(i, 1, n)
    FL(j, 1, n)
    W[i][j] = 1e18,
    dis[i][j] = 1e18;
    // int cnt = 0;
    FL(i, 1, n){
        int len, k, w;
        cin >> len;
        // cerr << n << " " << m << " " << d << " " << q << " " << wfjfjj[m] << endl;
        if(len == 1){cin >> k >> w;continue;}
        // cnt++;
        // cerr << "?" << cnt << endl;
        FL(j, 1, len){
            cin >> k >> w, df[k].emplace_back(i, w);
        }
    }
    FL(i, 1, m){
        for(auto&z : df[i])for(auto&y : df[i])if(z.fr != y.fr)
            add(z.fr, y.fr, z.se + y.se), add(y.fr, z.fr, z.se + y.se);
    }
    // cerr << cnt << endl;
    // FL(i, 1, cnt + m)G[i + 1] += G[i];
    // FL(i, 1, tot)e[G[U[i]]--] = {V[i], W[i]};
    // auto ed = clock();
    FL(i, 1, n)dij(i);
    // FL(i, 1, n)
    //     FL(j, 1, n) cout << dis[i][j] << " \n"[j == jend];
    // cerr << "*";
    FL(i, 1, q){
        int u, v, ans = 1e18;
        cin >> u >> v;
        if(u == v){cout << 0;continue;}
        // if(dis[u][u])dij(u);
        for(auto&a : df[u])for(auto&b : df[v])
            cmin(ans, a.se + b.se + dis[a.fr][b.fr]);
        // cout << ans << " ";
        cout << ans + wfjfjj[u] + wfjfjj[v] << endl;
    }
    
    // cerr << (ed - st) * 1.0 / CLOCKS_PER_SEC << endl;
}