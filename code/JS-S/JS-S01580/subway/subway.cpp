#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 5;
int c,n,m,d,q,w[N],dis[505][505],vis[505];
struct platform{
    int line,tm;
};
vector<platform> sta[N];
struct edge {
    int v,w;
};
vector<edge> g[505];
struct node {
    int v,dis;
};
bool operator > (node a,node b) {
    return a.dis < b.dis;
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1;j <= k; j++) {
            int a,t;
            cin >> a >> t;
            if(sta[a].size()) {
                for(int h = 0; h < sta[a].size(); h++) {
                    g[i].push_back({sta[a][h].line,sta[a][h].tm + t});
                    g[sta[a][h].line].push_back({i,sta[a][h].tm + t});
                }
            }
            sta[a].push_back({i,t});
        }
    }
    for(int i = 1;i<= n;i++) {
        for(int j = 1; j <= n;j++) {
            dis[i][j] = 0x3f3f3f3f3f3f;
        }
    }
    for(int i = 1; i<= n;i++) {
        for(int j = 1; j<= n; j++) {
            vis[j]= 0;
        }
        dis[i][i] = 0;
        priority_queue<node,vector<node>,greater<node> > pq;
        pq.push({i,0});
        while(!pq.empty()) {
            int u = pq.top().v;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(int j = 0; j < g[u].size(); j++) {
                int v = g[u][j].v,w = g[u][j].w;
                if(dis[i][v] > dis[i][u] + w) {
                    dis[i][v] = dis[i][u] + w;
                    pq.push({v,dis[i][v]});
                }
            } 
        }
    }
    while(q--) {
        int x,y;
        cin >> x >> y;
        int minn = 0x3f3f3f3f3f3f;
        for(int i = 0; i < sta[x].size(); i++) {
            for(int j = 0; j < sta[y].size();j++) {
                int sum = dis[sta[x][i].line][sta[y][j].line] + w[x] + w[y] + sta[x][i].tm + sta[y][j].tm;
                if(sum < minn) {
                    minn = sum;
                }
            }
        }
        cout << minn <<"\n";
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/