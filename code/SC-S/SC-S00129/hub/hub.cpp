#include<bits/stdc++.h>
#define fi first
#define se second
#define lowbit(x) ((x) & (-(x)))
using namespace std;
typedef long long ll;
const int N = 4040, inf = 1e9;
inline ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')
          f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
inline void write(ll x){
    if(x < 0){
        x = -x;
        putchar('-');
    }
    if(x > 9)
      write(x / 10);
    putchar(x % 10 + '0');
}
int c, T, n, k, cnt, now;
int mxdep[N], dep[N], dfn[N], siz[N], son[N], top[N], fa[N];
int dp[N][N], g[N], f[N];
vector<int> E[N];
inline void add(int u, int v){
    E[u].push_back(v);
}
inline void init(int u){
    f[0] = mxdep[u] - dep[u];
    f[1] = 0;   
    now = 1;
}
inline void merge(int v){
    for(int i = 1; i <= min(now + siz[v], k); ++i)
      g[i] = inf;
    for(int i = now; i >= 1; --i)
      for(int j = 0; i + j <= k && j <= siz[v]; ++j)
        g[i + j] = min(g[i + j], max(f[i], dp[v][j] + (j == 0)));
    now += siz[v];
    for(int i = 1; i <= min(now + siz[v], k); ++i)
      f[i] = g[i];    
    // cerr << v << ' ' << dp[v][1] << '\n';
}
inline void dfs(int u, int f){
    siz[u] = 1;
    mxdep[u] = dep[u];
    for(auto v : E[u]){
        if(v == f)
          continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        siz[u] += siz[v];
        mxdep[u] = max(mxdep[u], mxdep[v]);
        if(siz[v] > siz[son[u]])
          son[u] = v;
    }
    for(int i = 0; i <= min(siz[u], k); ++i)
      dp[u][i] = inf;
    dp[u][0] = mxdep[u] - dep[u];
    dp[u][1] = 0;
    int now = 1;
    for(auto v : E[u]){
        if(v == f)
          continue;
        for(int i = 1; i <= min(now + siz[v], k); ++i)
          g[i] = inf;
        for(int i = now; i >= 1; --i)
          for(int j = 0; i + j <= k && j <= siz[v]; ++j)
            g[i + j] = min(g[i + j], max(dp[u][i], dp[v][j] + (j == 0)));
        now += siz[v];
        for(int i = 1; i <= min(now + siz[v], k); ++i)
          dp[u][i] = g[i];
    }
}
inline void dfs2(int u, int k){
    top[u] = k;
    dfn[u] = ++cnt;
    if(!son[u])
      return ;
    dfs2(son[u], k);
    for(auto v : E[u]){
        if(v == fa[u] || v == son[u])
          continue;
        dfs2(v, v);
    }
}
inline int LCA(int u, int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]])
          swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
inline int dis(int u, int v){
    return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}
inline void solve(){
    cnt = 0;
    n = read(), k = read();
    for(int i = 1; i <= n; ++i)
      E[i].clear(), son[i] = 0;
    for(int u, v, i = 1; i < n; ++i){
        u = read(), v = read();
        add(u, v);
    }
    dfs(1, 1);
    dfs2(1, 1);
    // cerr << dp[1][3] << '\n';
    int ans = inf;
    for(int u = 1; u <= n; ++u){
        for(int v = 1; v <= n; ++v){
            if(u == v)
              continue;
            int mx = 0;
            for(int x = 1; x <= n; ++x){
                if(dfn[u] <= dfn[x] && dfn[x] <= dfn[u] + siz[u] - 1)
                  continue;
                if(dfn[v] <= dfn[x] && dfn[x] <= dfn[v] + siz[v] - 1)
                  continue;
                mx = max(mx, min(dis(x, u), dis(x, v)));
            }
            int mn = inf;
            for(int l = 0; l <= k; ++l){
                if(l <= siz[u] && k - l <= siz[v]){
                    mn = min(mn, max(dp[u][l] + (l == 0), dp[v][k - l] + (k == l)));
                    // if(max(dp[u][l], dp[v][k - l]) == 1)
                    //   cerr << "?? " << u << ' ' << v << ' ' << l << ' ' << mx << ' ' << dp[u][l] << ' ' << dp[v][k - l] << '\n';
                }
            }
            mx = max(mx, mn);
            // if(mx == 1)
            //   cerr << u << ' ' << v << ' ' << mn << '\n';
            ans = min(ans, mx);
        }
    }
    // cerr << dp[3][1] << '\n';
    for(int u = 1; u <= n; ++u){
        int lst = u;
        for(int v = fa[u]; v; v = fa[v]){
            init(v);
            for(auto h : E[u])
              if(h != fa[v] && h != lst)
                merge(h);
            int mx = (dep[u] - dep[v]) >> 1;
            for(int x = 1; x <= n; ++x){
                if(dfn[u] <= dfn[x] && dfn[x] <= dfn[u] + siz[u] - 1)
                  continue;
                if(dfn[v] <= dfn[x] && dfn[x] <= dfn[v] + siz[v] - 1)
                  continue;
                mx = max(mx, min(dis(x, u), dis(x, v)));
            }
            int mn = inf;
            for(int l = 1; l < k; ++l){
                if(l <= siz[u] && k - l <= siz[v]){
                    mn = min(mn, max(dp[u][l] + (l == 0), f[k - l] + (k == l)));
                    // if(mn == 1)
                    //   cerr << u << ' ' << v << ' ' << l << ' ' << k << ' ' << mx << ' ' << dp[u][l] << ' ' << f[k - l] << '\n';
                }
            }
            mx = max(mx, mn);
            // if(mx == 1)
            //   cerr << u << ' ' << v << '\n';
            ans = min(ans, mx);
            lst = v;
        }
    }
    write(ans);
    putchar('\n');
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    c = read(), T = read();
    while(T--)
      solve();
    return 0;
}
/*
g++ hub.cpp -o hub -std=c++14 -O2 -Wall

./hub < hub1.in > hub1.out
./hub < hub2.in > hub2.out
./hub < hub3.in > hub3.out
./hub < hub4.in > hub4.out
./hub < hub5.in > hub5.out
./hub < hub6.in > hub6.out

diff hub1.out hub1.ans
diff hub2.out hub2.ans
diff hub3.out hub3.ans
diff hub4.out hub4.ans
diff hub5.out hub5.ans
diff hub6.out hub6.ans
*/