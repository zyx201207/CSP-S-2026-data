#include <bits/stdc++.h>
using namespace std;
int w[500005];
struct node {
    int a, t;
};
vector<node> g[500005];
struct route {
    int a, cost;
};
int t[500005];
vector<node>  a[505];
int vis[500005];
int bfs(int x, int y) {
    memset(vis, 0, sizeof(vis));
    queue<route> q;
    vis[x] = 1;
    q.push({x, t[x]});
    while(!q.empty()) {
        int ha = q.front().a, cost = q.front().cost;
        q.pop();
        if(ha == y) {
            return cost;
        }
        cost += t[ha];
        for(int i = 0 ; i < g[ha].size(); i++) {
            int na = g[ha][i].a;
            if(!vis[na]) {
                q.push({na, cost + a[ha][na].t});
                vis[na] = 1;
            }
        }
    }
}
struct node2 {
    int x, step;
};
vector<int> ls[500005];
vector<node> ls2[500005];
int bfs2(int x,int y) {
    memset(vis,0, sizeof(vis));
    queue<node2> q;
    q.push({x, 0});
    vis[x] = 1;
    while(!q.empty()) {
        int hx = q.front().x, step = q.front().step;
        if(hx == y) {
            return step;
        }
        for(int i = 0; i < ls[hx].size(); i++) {
            int nx = ls[hx][i];
            if(!vis[nx]) {
                q.push({nx, step + 1});
                vis[nx] = 1;
            }
        }
        q.pop();
    }

}
/*
daddadasdad
*/
int bfs3(int x, int y) {
    memset(vis, 0, sizeof(vis));
    queue<route> q;
    vis[x] = 1;
    q.push({x, t[x]});
    while(!q.empty()) {
        int ha = q.front().a, cost = q.front().cost;
        q.pop();
        if(ha == y) {
            return cost;
        }
        cost += t[ha];
        for(int i = 0 ; i < ls2[ha].size(); i++) {
            int na = ls2[ha][i].a;
            if(!vis[na]) {
                q.push({na, cost + ls2[ha][i].t});
                vis[na] = 1;
            }
        }
    }
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
int main() {
    int c, n, m, d, q;
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    int T;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >>k;
        a[i].resize(k+1);
        vector<int> sta;
        vector<node> sta2;
        for(int j = 1; j <= k; j++) {
            int ai, ti;
            cin >> ai >> ti;
            if(i == ai) t[i] = ti;
            sta.push_back(ai);
            sta2.push_back({ai, ti});
            T = ti;
            a[i][ai]= {ai, ti};
            if(j >= 2) {
                g[ai].push_back({a[a[i].size() - 2][ai].a, ti});
                g[a[a[i].size() - 2][ai].a].push_back({ai, ti});
            }
        }
        for(int i = 1; i < sta.size(); i++) {
            ls[sta[i]].push_back(sta[i - 1]);
            ls[sta[i - 1]].push_back(sta[i]);
            ls2[sta2[i].a].push_back({sta2[i - 1].a, sta2[i - 1].t});
            ls2[sta2[i - 1].a].push_back({sta2[i].a, sta2[i].t});
        }

    }
    if(d <= 2 || (7 <= c && c <= 11)) {

    }
    if(c>=12 && c <= 19) {
        for(int i =1; i <= q; i++) {
            int x,y;
            cin >>x >>y;
            if(x == y)cout <<0;
            else
                cout << bfs2(x, y) * T +w[x] + w[y] << endl;
        }
        return 0;
    }
    for(int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if(x == y)cout <<0;
        else
            cout <<bfs3(x, y) + w[x] + w[y] << endl;
    }
    return 0;
}
/*
rexturnreturnreturnreturnreturnreturnreturnreturnreturnireturnreturnreturnreturnrejturnreturnretuirnretunrnreturnreturnreturnreturnreturn
returnreturnreturnreturnreturnrepturnreturnreturnreturnreturnreturnireturnreturnreturnrneturnreturnreturnreturnreturnreturnreturnreturn
returnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturn
returnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturgnretusrnreturndreturnreturnreturnreturnreturn
returnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnureturnreturnreturnreturn
returnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturn
returnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturncreturnreturnreturnreturnreturnreturnreturnreturnreturn
returnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnreturnretaurnreturnreturnreturnreturnreturnreturnreturnreturn

i
*/
