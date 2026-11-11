#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 2e5 + 5;
struct Node{
    int y;
    long long v;
    bool operator < (const Node a)const{
        return a.v < v;
    }
};
vector<Node>edge[N + M];
int nsid, n, m, d, q, w[M];
long long dis[N][N + M];
bool vis[N + M];
void dijskra(int st){
    for(int i = 1; i <= n + m; i++)dis[st - m][i] = LONG_MAX, vis[i] = 0;
    priority_queue<Node>q;
    q.push({st, 0}), dis[st - m][st] = 0;
    while(!q.empty()){
        int x = q.top().y;
        q.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(int i = 0; i < edge[x].size(); i++){
            int y = edge[x][i].y, v = edge[x][i].v;
            if(dis[st - m][x] + v < dis[st - m][y])dis[st - m][y] = dis[st - m][x] + v, q.push({y, dis[st - m][y]});
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> nsid >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1, k; i <= n; i++){
        cin >> k;
        for(int j = 1, x, y; j <= k; j++){
            cin >> x >> y;
            edge[x].push_back({i + m, y});
            edge[i + m].push_back({x, y});
        }
    }
    for(int i = 1; i <= n; i++){
        dijskra(i + m);
    }
    for(int i = 1, x, y; i <= q; i++){
        cin >> x >> y;
        long long ans = LONG_MAX;
        for(int j = 1; j <= n; j++){
            ans = min(ans, w[x] + w[y] + dis[j][x] + dis[j][y]);
        }
        cout << ans << "\n";
    }
}
