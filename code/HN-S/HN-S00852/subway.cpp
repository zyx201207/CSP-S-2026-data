#include<bits/stdc++.h>
#define int long long
#define bk(v, i) v[v.size() - (i)]
#define all(v) v.begin(), v.end()
#define rep(i, l, r) for(int i = (l);i <= (r);i++)
#define per(i, r, l) for(int i = (r);i >= (l);i--)
using namespace std;

const int INF = sizeof(int) == 4 ? (int)1e9 + 1 : (int)1e18 + 1;
template<typename T> inline void chkmin(T &x, T y){ ( x > y ) && ( x = y ); }
template<typename T> inline void chkmax(T &x, T y){ ( x < y ) && ( x = y ); }

const int N = 505, M = 5e5 + 5;
int subtask;
int n, m, d, q;
int w[M];
vector<pair<int, int>> e[M], g[N];

int dis[N][N];

signed main(){
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> subtask;
    cin >> n >> m >> d >> q;
    rep(i, 1, m) cin >> w[i];

    rep(i, 1, n){
        int k; cin >> k;
        rep(j, 1, k){
            int a, t; cin >> a >> t;
            g[i].push_back({a, t}), e[a].push_back({i, t});
        }
    }

    rep(i, 1, n){
        rep(j, 1, n) dis[i][j] = INF;
        dis[i][i] = 0;
    }

    rep(i, 1, n){
        for(auto [a, t] :  g[i]){
            for(auto [j, l] : e[a]){
                chkmin(dis[i][j], t + l);
            }
        }
    }

    rep(k, 1, n)
        rep(i, 1, n)
            rep(j, 1, n)
                chkmin(dis[i][j], dis[i][k] + dis[k][j]);
    
    while(q --){
        int x, y;
        cin >> x >> y;
        
        int ans = INF;
        for(auto [i, t1] : e[x]){
            for(auto [j, t2] : e[y]){
                chkmin(ans, w[x] + w[y] + t1 + t2 + dis[i][j]);
            }
        }
        cout << ans << "\n";
    }


    return 0;
}