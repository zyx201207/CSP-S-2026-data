//fencengtu zuiduanlu
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m, c, d, q, w[N], cnt = 0;

vector<pair<int, long long> > layer[502];//pts of each layer

bool vis[502];
long long mint[502][502], dis[502];
vector<pair<int, long long> > pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j ++) {
            int u; long long ct;
            cin >> u >> ct;
            layer[i].push_back({u, ct});
            pos[u].push_back({m + i, ct});
        }    
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) mint[i][j] = 1e10;
    }
    for(int i = 1; i <= n; i ++) {
        for (pair <int, long long> x : layer[i]) {
            for (pair <int, long long> y : pos[x.first]) {
                if(y.first == m + i) continue;
                mint[i][y.first - m] = min (y.second + x.second, mint[i][y.first - m]);
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(mint[i][j] == 1e10) continue;
            else pos[m + i].push_back({m + j, mint[i][j]});
        }
    }
    for(int i = 1; i <= q; i ++) {
        memset(vis, false, sizeof(vis));
        for(int j = 1; j <= n; j ++) dis[j] = 1e16;
        int x, y;
        cin >> x >> y;
        long long ans = w[x] + w[y];
        priority_queue <pair<long long, int> > q; 
        for (pair<int, long long> a : pos[x]) {
            dis[a.first - m] = a.second;
            q.push({a.second, a.first});
        }
        while(!q.empty()) {
            pair <long long, int> curr = q.top();
            q.pop();
            if(vis[curr.second - m]) continue;
            vis[curr.second - m] = true;
            for (pair<int, long long>  a : pos[curr.second]) {
                int u = a.first; 
                int cost = a.second; 
                if(cost + curr.first < dis[u - m]) {
                    dis[u - m] = cost + curr.first;
                    q.push({dis[u - m], u});
                }
            }
        }
        long long tmp = 1e16;
        for(pair<int, long long> a : pos[y]) {
            tmp = min(tmp, dis[a.first - m] + a.second);
        }
        ans += tmp;
        cout << ans << "\n";
    }
    return 0;
}