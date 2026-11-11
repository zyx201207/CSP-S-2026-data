#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, n, m, d, t;
const int M = 5e5+1000;
struct node{
    int to;
    ll w;
};
//subway mouth
//subway stand room
//subway stand shelf
int m_r[M];
int cnt[M];
vector<node> g[M];
priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
ll dis[M];
bool vis[M];
inline void dj(int x){
    memset(vis,false ,sizeof(vis));
    for(int i = 1;i <= m+n;i++) dis[i] = 1e14;
    while(!q.empty()) q.pop();
    q.push({0, x});
    dis[x] = 0;
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0;i < g[u].size();i++){
            int v = g[u][i].to;
            int w = g[u][i].w;
            if(dis[u]+w <= dis[v]){
                dis[v] = dis[u]+w;
                q.push({dis[v], v});
            }
        }
    }
}
ll mymap[505][505];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int ls;
    cin >> ls >> n >> m >> d >> t;
    for(int i = 1;i <= m;i++){
        scanf("%d", &m_r[i]);
    }
    int k;
    int u;
    ll w;
    for(int i = 1;i <= n;i++){
        scanf("%d", &k);
        for(int j = 1;j <= k;j++){
            scanf("%d%lld", &u, &w);
            cnt[u]++;
            g[u].push_back({m+i, w});
            g[m+i].push_back({u, w});
        }
    }
    int x, y;
    for(int i = 1;i <= n;i++){
        dj(m+i);
        for(int j = 1;j <= n;j++){
            mymap[i][j] = dis[m+j];
        }
    }
    /*
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << i << " " << j << ": " << mymap[i][j] << endl;
        }
    }
    cout << endl;
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < g[i].size();j++){
            cout << i << " " << g[i][j].to << " " << g[i][j].w << endl;
        }
    }
    cout << endl;
    //*/
    while(t--){
        scanf("%d%d", &x, &y);
        ll minn = 1e17;
        for(int i = 0;i < g[x].size();i++){
            for(int j = 0;j < g[y].size();j++){
                minn = min(minn, mymap[g[x][i].to-m][g[y][j].to-m]+g[x][i].w+g[y][j].w);
            }
        }
        //cout << minn << endl;
        printf("%lld\n", minn+m_r[x]+m_r[y]);
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
