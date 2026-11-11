#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll INF = 1e15 + 7;
const int N = 5e5 + 10, M = 510;
int c, n, m, d, q;// c:ce_shi_dian n:number of line m:kou q:number of query
ll w[N]; //kou -> ting time
struct node {
    ll id, time;
};
vector<node> a[M];
vector<node> t[N];
struct path{
    int node;
    ll time;
    bool operator < (const path num)const {
        return time > num.time;
    }
};
ll dis[410][410];
ll dijk(int s, int t) {
    priority_queue<path> pq;
    pq.push({s, 0});
    while(!pq.empty()) {
        path tmp = pq.top();
        pq.pop();
        if(tmp.time > dis[s][tmp.node]) {
            continue;
        }
        for(int i = 1;i <= m;i ++) {
            if(dis[tmp.node][i] == 0) continue;
            if(dis[tmp.node][i] + tmp.time <= dis[s][i]) {
                dis[s][i] = dis[i][s] = dis[tmp.node][i] + tmp.time;
                pq.push({i, dis[s][i]});
            }
        }
    }
    return dis[s][t];
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for(int i = 1;i <= m;i ++) scanf("%lld", &w[i]);
    for(int i = 1;i <= n;i ++) {
        int tmp;
        scanf("%d", &tmp);
        for(int j = 1;j <= tmp;j ++) {
            int x;
            ll time;
            scanf("%d %lld", &x, &time);
            a[i].push_back({x, time});
            t[x].push_back({i, time});
        }
    }
    if(c <= 11) {
        for(int i = 1;i <= m;i ++) {
            for(int j = 1;j <= m;j ++) {
                dis[i][j] = INF;
            }
        }
        for(int i = 1;i <= n;i ++) {
            for(int j = 0;j < a[i].size();j ++) {
                for(int k = j + 1;k < a[i].size();k ++) {
                    dis[a[i][j].id][a[i][k].id] = dis[a[i][k].id][a[i][j].id] = min(dis[a[i][j].id][a[i][k].id], a[i][j].time + a[i][k].time);
                }
            }
        }
        for(int i = 1;i <= q;i ++) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%lld\n", dijk(x, y) + w[x] + w[y]);
        }
    }
    return 0;
}
