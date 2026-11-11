#include<bits/stdc++.h>
using namespace std;
long long id, n, m, d, q, a[200010], b[200010], c[200010], dp[1010][1010], maxk = 0, dis[2010][2010], vis[2010], v[20010];
vector<pair<long long, long long> > g[200010];
priority_queue<pair<long long, long long> > pq;
queue<pair<long long, long long> > p;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    memset(dp, 0x3f, sizeof(dp));
    memset(dis, 0x3f, sizeof(dis));
    cin >> id >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        dp[i][i] = 0;
    }for(int i = 1; i <= n; i++) {
        long long k; cin >> k;
        maxk = max(maxk, k);
        for(int j = 1; j <= k; j ++){
            cin >> b[j] >> c[j];
        }for(int j = 1; j <= k; j ++) {
            for(int t = j + 1; t <= k; t ++) {
                g[b[j]].push_back({b[t], c[j] + c[t]});
                g[b[t]].push_back({b[j], c[j] + c[t]});
                if(b[j] <= 300 && b[t] <= 300){
                    dp[b[j]][b[t]] = min(dp[b[j]][b[t]], c[j] + c[t]);
                    dp[b[t]][b[j]] = min(dp[b[t]][b[j]], c[j] + c[t]);
                }
            }
        }
    }if(m <= 300) {
        for(int k = 1; k <= m; k ++) {
            for(int i = 1; i <= m; i ++) {
                for(int j = 1; j <= m; j ++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }while(q --) {
            int x, y;
            cin >> x >> y;
            cout << dp[x][y] + a[x] + a[y] << "\n";
        }return 0;
    }if(maxk <= 2){
        for(int i = 1; i <= m; i ++) {
            pq.push({0, i});
            dis[i][i] = 0;
            while(pq.size()) {
                long long di = pq.top().first, id = pq.top().second;
                pq.pop();
                if(vis[id]) continue;
                vis[id] = 1;
                for(int j = 0; j < g[id].size(); j ++) {
                    if(dis[i][id] + g[id][j].second < dis[i][g[id][j].first]){
                        dis[i][g[id][j].first] = di + g[id][j].second;
                        pq.push({dis[i][g[id][j].first], g[id][j].first});
                    }
                }
            }for(int i = 1; i <= m; i ++) vis[i] = 0;
        }while(q --) {
            int x, y;
            cin >> x >> y;
            cout << dis[x][y] + a[x] + a[y] << "\n";
        }return 0;
    }
	while(q --) {
        int x, y;
        cin >> x >> y;
        p.push({x, 0});
        v[x] = 1;
        while(p.size()) {
            int di = p.front().second, id = p.front().first;
            p.pop();
            if(id == y) {
                cout << di << "\n";
                break;
            }for(int i = 0; i < g[id].size(); i ++) {
                if(v[g[id][i].first] == 0) {
                    p.push({g[id][i].first, di + g[id][i].second});
                    v[g[id][i].first] = 1;
                }
            }
        }while(p.size()) p.pop();
        for(int i = 1; i <= m; i ++) v[i] = 0;
    }return 0;
}