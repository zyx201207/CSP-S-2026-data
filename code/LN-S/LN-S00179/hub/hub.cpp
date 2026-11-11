#include <bits/stdc++.h>
using namespace std;

template <typename T> bool ckmx(T &x, T y){return (x < y) ? (x = y, 1) : 0;}
template <typename T> bool ckmn(T &x, T y){return (x > y) ? (x = y, 1) : 0;}
typedef long long ll;

const int N = 1e6 + 5;

int n, k;
vector<int> son[N];
struct Edge{
    int u, v;
} e[N];
bool in[N];
int dis[N];

namespace dsu{
    int fa[N];
    void init(){
        for(int i = 1; i <= n; i++) fa[i] = i;
    }
    int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
}

void solveb(){
    int ans = 1e9;
    for(int s = 0; s < (1 << n); s++){
        if(__builtin_popcount(s) != k) continue;
        for(int i = 1; i <= n; i++)
            in[i] = ((s >> (i - 1)) & 1);
        dsu::init();
        for(int i = 1; i <= n - 1; i++){
            if(in[e[i].u] && in[e[i].v]){
                dsu::fa[dsu::find(e[i].u)] = dsu::find(e[i].v);
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(in[i] && dsu::fa[i] == i) cnt++;
        }
        if(cnt > 2) continue;
        queue<int> q;
        for(int i = 1; i <= n; i++)
            if(in[i]) dis[i] = 0, q.push(i);
            else dis[i] = -1;
        int tot = 0;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            ckmx(tot, dis[u]);
            for(auto v : son[u])
                if(dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
        }
        ckmn(ans, tot);
    }
    cout << ans << '\n';
}

void solveA(){
    int m = n / 2;
    cout << ((m - k + 3) / 4 + 1) << '\n';
}

int q[N], h, t;
void solve(){
    int ans = 1e9;
    for(int i = 1; i <= n; i++) dis[i] = -1;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            dis[i] = dis[j] = 0;
            h = 1, t = 0;
            q[++t] = i;
            q[++t] = j;
            int tot = 0;
            while(h <= t){
                auto u = q[h++];
                ckmx(tot, dis[u]);
                if(tot >= ans) break;
                for(auto v : son[u])
                    if(dis[v] == -1){
                        dis[v] = dis[u] + 1;
                        q[++t] = v;
                    }
            }
            // cerr << i << ' ' << j << ' ' << tot << '\n';
            for(int i = 1; i <= t; i++)
                dis[q[i]] = -1;
            ckmn(ans, tot);
        }
    }
    cout << ans << '\n';
}

void clear(){
    for(int i = 1; i <= n; i++)
        son[i].clear();
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(0);
    int c, T = 1;
    cin >> c >> T;
    while(T--){
        cin >> n >> k;
        clear();
        for(int i = 1; i <= n - 1; i++){
            int u, v;
            cin >> u >> v;
            son[u].push_back(v);
            son[v].push_back(u);
            e[i] = {u, v};
        }
        if(c <= 3) solveb();
        else if(c >= 13 && c <= 14) solveA();
        else if(c == 7 || c == 11 || c == 12) solve();
        else solve();
    }
    return 0;
}