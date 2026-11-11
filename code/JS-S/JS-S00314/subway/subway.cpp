#include<bits/stdc++.h>
using namespace std;
struct Node {
    int p, ln, step;
};
const int INF = 0x3f3f3f3f;
int dis[501][1001], w[1001], k[1001];
int a[501][1001], t[501][1001], ans;
vector<int> vec[1001];
void bfs(int s, int e) {
    queue<Node> q;
    for(int z : vec[s]) {
        q.push({s, z, w[s] + t[z][s]});
    }
    while(!q.empty()) {
        auto l = q.front();
        q.pop();
        if(l.step >= dis[l.p][l.ln] || l.step >= ans) continue;
        if(l.p == e) {
            dis[e][l.ln] = l.step + t[l.ln][l.p] + w[e];
            ans = min(ans, dis[e][l.ln]);
            continue;
        }
        dis[l.p][l.ln] = l.step;
        for(int i = 1; i <= k[l.ln]; i++) {
            int op = a[l.ln][i];
            if(op == e) {
                int ndis = l.step + t[l.ln][op] + w[e];
                if(ans > ndis) {
                    ans = dis[e][l.ln] = ndis;
                }
            }
            for(int z : vec[op]) {
                q.push({op, z, l.step + t[l.ln][op] + t[z][op]});
            }
        }
    }
}
int main() {
    //By Luogu-bilibiliTV
    //Give me a blue-gou pls,I'll do every thing
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) {
            int x, y;
            cin >> x >> y;
            a[i][j] = x;
            vec[x].push_back(i);
            t[i][x] = y;
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = INF;
        ans = INF;
        bfs(x, y);
        cout << ans << "\n";
    }
    return 0;
}
