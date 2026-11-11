#include <bits/stdc++.h>
#define int long long
#define L(i, a, b) for(int i = a;i <= b;i ++ ) 
using namespace std;
const int N = 2e4 + 5, M = 5e5 + 5;
int a[205][N], t[205][N], k[N], w[N], nxt[205][N];
int a1[3][M], t1[3][M], nxt1[3][M];
int CSP, n, m, d, q;
vector<int> g[N];
int num[N]; // every station includes ways
int x, y, ans;
void task2021(){
    L(lhy, 1, q){
        cin >> x >> y;
        int opx = 0, opy = 0;
        bool stoo = 0;
        L(op, 1, 2){
            int f1 = 0, f2 = f1;
            L(i, 1, k[op]){
                if(a1[op][i] == x) f1 = 1, opx = op;
                if(a1[op][i] == y) f2 = 1, opy = op;
            }
            if(f1 && f2) {cout << w[x] + t1[op][x] + t1[op][y] + w[y] << endl; stoo = 1; break;}
        }
        if(stoo) continue;
        int bas = w[x] + t1[opx][x] + t1[opy][y] + w[y], answ = LONG_LONG_MAX;
        // cout << "::" << w[x] << ' ' << t[opx][x] << ' ' << t[opy][y] << ' ' << w[y] << endl;
        L(i, 1, m){
            if(num[i] == 2){
                // cout << "::" << i << endl;
                answ = min(ans, bas + t1[opx][i] + t1[opy][i]);
            }
        }
        cout << answ << endl;
    }
}
void dfs(int u, int op, int dis){
    if(u == y){
        dis += t[op][y];
        ans = min(ans, dis);
        return ;
    }
    if(!u) return ;
    if(dis > ans) return ;
    dfs(nxt[op][u], op, dis);
    for(auto v : g[u]){
        if(v == op) continue;
        dfs(nxt[v][u], v, dis + t[op][u] + t[v][u]);
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> CSP >> n >> m >> d >> q;
    L(i, 1, m) cin >> w[i];
    if(CSP == 20 || CSP == 21){
        L(i, 1, n){
            cin >> k[i];
            L(j, 1, k[i]) cin >> a1[i][j] >> t1[i][a1[i][j]], num[a1[i][j]] ++ , g[a1[i][j]].push_back(i), nxt[i][a1[i][j - 1]] = a1[i][j];
        }
        task2021();
        return 0;
    }
    L(i, 1, n){
        cin >> k[i];
        L(j, 1, k[i]) cin >> a[i][j] >> t[i][a[i][j]], num[a[i][j]] ++ , g[a[i][j]].push_back(i), nxt[i][a[i][j - 1]] = a[i][j];
    }
    
    while(q -- ){
        cin >> x >> y;
        if(x > y) swap(x, y);
        ans = LONG_LONG_MAX;
        for(auto i : g[x]) dfs(x, i, w[x] + w[y] + t[i][x]);
        cout << ans << endl;
    }
    return 0;
}