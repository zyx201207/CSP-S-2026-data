#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 510, MAXM = 500010, INF = INT64_MAX;
int c,n,m,d,q;
int w[MAXM], k[MAXN];
// vector<int>a[MAXN], t[MAXN];
pair<int, int>Q[100010];

int dis[MAXN][MAXN];
int dist[MAXM + MAXN];
bool vis[MAXM + MAXN];
int tot = 0;

struct Node{
    vector< int >to, w;
}G[MAXN + MAXM];

void read() {
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j] = (i==j?0:INF);
        }
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            int x,y; cin >> x >> y;
            // a[i].push_back(x);
            // t[i].push_back(y);
            // CAUTION: tag begins from 0 !!!
            x += MAXN;
            G[ i ].to.push_back( x );
            G[ i ].w.push_back( y );
            G[ x ].to.push_back( i );
            G[ x ].w.push_back( y );
        }
    }
    for(int i=1;i<=q;i++){
        cin >> Q[i].first >> Q[i].second;
    }
}

void dijskra(int rot) {
    priority_queue< pair<int,int> >que;
    for(int i=1;i<=n;i++){
        dist[i] = INF;
        vis[i] = 0;
    }
    for(int i=MAXN+1;i<=MAXN+m;i++){
        dist[i] = INF;
        vis[i] = 0;
    }
    dist[rot] = 0;
    que.push( {0,rot} );
    while(!que.empty()){
        auto t = que.top();
        que.pop();
        int u = t.second;
        int d = -t.first;
        if( vis[u] )continue;
        vis[u] = 1;

        for(int i=0;i<G[u].to.size();i++){
            int v = G[u].to[i];
            int cost = G[u].w[i];
            if( dist[v] > d + cost ){
                dist[v] = d + cost;
                que.push( {-dist[v], v} );
            }
        }
    }
    for(int i=1;i<=n;i++){
        dis[rot][i] = dist[i];
    }
}

void solve(){
    // for(int i=MAXN+1;i<=MAXN+m;i++){
    //     cout << "P" << i << ": \n";
    //     for(auto x : G[i].to)
    //         cout << x << " ";
    //     cout << "\n";
    //     for(auto x : G[i].w)
    //         cout << x << " ";
    //     cout << "\n";
    // }
    for(int i=1;i<=n;i++){
        dijskra(i);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i=1;i<=q;i++){
        int ans = INF;
        int x = Q[i].first;
        int y = Q[i].second;
        for( int ii = 0; ii < G[MAXN+x].to.size(); ii++ ) {
            int u = G[MAXN+x].to[ii];
            int wu = G[MAXN+x].w[ii];
            for( int jj = 0; jj < G[MAXN+y].to.size(); jj++ ) {
                int v = G[MAXN+y].to[jj];
                int wv = G[MAXN+y].w[jj];
                ans = min(ans,dis[u][v]+wu+wv);
            }
        }
        cout << ans + w[x] + w[y] << "\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen( "subway.in", "r", stdin );
    freopen( "subway.out", "w", stdout );
    int T = 1;
    while( T-- ) {
        read();
        solve();
    }
    return 0;
}