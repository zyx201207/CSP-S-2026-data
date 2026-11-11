#include<bits/stdc++.h>
#define FL(a, b, c) for(int a = (b), a##end = (c); a <= a##end; ++a)
#define FR(a, b, c) for(int a = (b), a##end = (c); a >= a##end; --a)
#define endl '\n'
#define vt vector
#define int long long
using namespace std;
constexpr int N = 1000 + 10;
int n, K, dep[N], mdep[N], siz[N];
vt<int> dp[3][N][N];
vector<int> e[N];
inline void cmin(int&a, int b){if(a > b)a = b;}
void dfs(int x, int f){
    // cerr << x << " " << f << endl;
    dep[x] = dep[f] + 1, siz[x] = 1, mdep[x] = dep[x];
    for (int v : e[x])
        if (v != f)
            dfs(v, x);
    // cerr << "*" << dp[1][x][0].size() << endl;
    dp[1][x][0][1] = 0, dp[0][x][1][0] = 1;
    for(int v : e[x])if(v != f){
        FL(i, 0, mdep[x] - dep[x] + 1)
            FL(s1, 0, 2)
            {
                FL(j, 0, min(siz[x], K))
                {
                    if(dp[s1][x][i][j] == 1e9)
                            continue;
                    FL(k, 0, mdep[v] - dep[v] + 1)
                    FL(l, 0, min(siz[v], K)) FL(s2, 0, 2)
                    {
                        // cerr << "****?" << s1 << " " << i << " " << j << endl;
                        // cerr << mdep[v] << " " << k << " " << l << endl;  
                        if(dp[s2][v][k][l] == 1e9)
                            continue;
                        // cerr << "*FDA";
                        if (s1 + s2 - (!k && !i) > 2)
                            continue;
                        if(!s1 && j)
                            continue;
                        if(!s2 && l)
                            continue;   
                        if (l + j > K)
                            continue;
                        // cerr << x << " " << s1 + s2 - (!k && !i) << " " << max(i, k) << " " << j + l << endl;
                        // cerr << max(i, k) << " " << j << " " << l << " " << s1 << " " << s2 << " " << i << " " << j << endl;
                        cmin(dp[s1 + s2 - (!k && !i)][x][max(i, k + 1)][j + l], max(dp[s1][x][i][j], dp[s2][v][k][l]));
                        // cerr << "*";
                    }
                }
        }
        // cerr << "?" << endl;
        mdep[x] = max(mdep[v], mdep[x]), siz[x] += siz[v];
    }
    // cerr << x  << "*" << endl;
}
void ___(){
    int u, v;
    cin >> n >> K;
    FL(i, 1, n)
    e[i].clear();
    FL(i, 2, n)cin >> u >> v, e[u].emplace_back(v), e[v].emplace_back(u);
    FL(i, 0, n)FL(j, 0, n) FL(k, 0, 2) dp[k][i][j].resize(K + 1, 1e9);
    dfs(1, 0);
    int ans = 1e9;
    // cerr << "?";
    FL(i, 1, 2)FL(k, 0, mdep[1]) FL(w, 1, K)if(dp[i][1][k][w] <= 1e9)cmin(ans, max(dp[i][1][k][w], k));
    cout << ans - 1 << endl;
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
        ___();
}