#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int c, n, m, d, q;
int w[260010];
vector<PII> e[260010];
long long dis[260010];
int a[1500], t[1500], vis[260010];
void bfs(int x, int y){
    priority_queue<PII, vector<PII>, greater<PII> > q;
    for(int i = 1; i <= m; i++)dis[i] = LLONG_MAX;
    memset(vis, 0, sizeof(vis));
    q.push(make_pair(0, x));
    while(!q.empty()){
        int d = q.top().first, id = q.top().second;
        if(vis[id] == 1)continue;
        vis[id] = 1;
        for(int i = 0; i < e[id].size(); i++){
            int to = e[id][i].first, nd = d + e[id][i].second;
            if(nd < dis[to]){
                dis[to] = nd;
                q.push(make_pair(to, nd));
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> a[i] >> t[i];
        }
        for(int j = 1; j < k; j++){
            for(int l = j + 1; l <= k; l++){
                int tt = t[j] + t[l];
                e[j].push_back(make_pair(l, tt));
                e[l].push_back(make_pair(j, tt));
            }
        }
    }
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        bfs(x, y);
        long long ans = dis[y] + w[x] + w[y];
        cout << ans << endl;
    }
    return 0;
}
