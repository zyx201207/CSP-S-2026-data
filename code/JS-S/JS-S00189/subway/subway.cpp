#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 550, M = 20005;
int c, n, m, d, q;
int w[M], k[N], x[M], y[M];
int a[N][M], t[N][M];

struct Station{
    int w;
    int t[N];
} s[M];

struct Edge{
    int v, w;
    int t;
    bool operator < (const Edge & A) const { return w > A.w; }
} ;
vector<Edge> mp[M];

int dis[M];
bool vis[M];

void work1(){
    for(int i = 1; i <= q; i++){
        int start = x[i], ed = y[i];
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        priority_queue<Edge> e;
        dis[start] = 0, vis[start] = 1;
        e.push({start, 0, 0});
        while(!e.empty()){
            auto tmp = e.top(); e.pop();
            for(auto to : mp[tmp.v]){
                if(vis[to.v]) continue ;
                int cost = 0;
                if(tmp.t == 0){
                    cost += s[to.v].t[to.t] + s[tmp.v].t[to.t];
                }
                else{
                    if(tmp.t == to.t) cost = 0;
                    else cost += s[tmp.v].t[to.t] + s[to.v].t[to.t];//huan cheng
                }
                if(dis[to.v] > dis[tmp.v] + cost) {
                    dis[to.v] = dis[tmp.v] + cost;
                    if(tmp.t == to.t) e.push({to.v, dis[to.v], tmp.t});
                    else e.push({to.v, dis[to.v], to.t});
                    vis[to.v] = 1;
                }
            }
        }
        cout << dis[ed] + w[start] + w[ed] << endl;
    }
    return ;
}

void work2(){
    for(int i = 1; i <= q; i++){
        int start = x[i], ed = y[i];
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        priority_queue<Edge> e;
        dis[start] = 0, vis[start] = 1;
        e.push({start, 0, 0});
        while(!e.empty()){
            auto tmp = e.top(); e.pop();
            for(auto to : mp[tmp.v]){
                if(vis[to.v]) continue ;
                int cost = s[tmp.v].t[to.t] + s[to.v].t[to.t];
                if(dis[to.v] > dis[tmp.v] + cost) {
                    dis[to.v] = dis[tmp.v] + cost;
                    e.push({to.v, dis[to.v], to.t});
                    vis[to.v] = 1;
                }
            }
        }
        cout << dis[ed] + w[start] + w[ed] << endl;
    }
    return ;
}

void work3(){
    work1();
}

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){ 
        cin >> w[i];
        s[i].w = w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            if(j > 1){
                int u = a[i][j], v = a[i][j - 1];
                mp[u].push_back({v, 0, i});
                mp[v].push_back({u, 0, i});
            }
            s[a[i][j]].t[i] = t[i][j];
        }
    }
    for(int i = 1; i <= q; i++) 
        cin >> x[i] >> y[i];
    
    if(c <= 6){
        work1();
    }
    else if(c <= 11){
        work2();
    }
    else{
        work3();
    }
    return 0;
}
