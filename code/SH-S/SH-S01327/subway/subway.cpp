#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q; // 25 500 5e5 20 1e5
int w[500005];
vector<pair<long long, int>> fri[500505];
long long de[500505];
long long dline[505][505];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
void dig(int s) {
    memset(de, 0x7f, sizeof(de[0]) * (n + m + 1));
    de[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        pair<long long, int> u = pq.top();
        pq.pop();
        for(pair<long long, int> v : fri[u.second]) {
            if(de[v.second] > de[u.second] + v.first) {
                de[v.second] = de[u.second] + v.first;
                pq.push({de[v.second], v.second});
            }
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; ++i) {
        scanf("%d", &w[i]);
    }
    for(int i = 1, k; i <= n; ++i) {
        scanf("%d", &k);
        for(int j = 1, sta; j <= k; ++j) {
            long long ti;
            scanf("%d%lld", &sta, &ti);
            fri[m + i].push_back({ti, sta});
            fri[sta].push_back({ti, m + i});
        }
    }
    memset(dline, 0x7f, sizeof dline);
    for(int i = 1; i <= n; ++i) { // 500
        dig(m + i); // 50
        for(int j = 1; j <= n; ++j) { // 500
            dline[i][j] = de[m + j];
        }
    }
    // O(n log(m + n))
    while(q--) { // 1e5
        int x, y;
        scanf("%d%d", &x, &y);
        long long ans = LLONG_MAX;
        for(pair<long long, int> i : fri[x]) { // 20
            for(pair<long long, int> j : fri[y]) { // 20
                ans = min(ans, dline[i.second - m][j.second - m] + i.first + j.first);
            }
        }
        // dig(x);
        printf("%lld\n", 1ll * w[x] + 1ll * w[y] + ans);
    }
    return 0;
}
/*
1-15 60pts
g++ subway/subway.cpp -o subway/subway -std=c++14 -O2 -static -Wall && cp subway/subway ~ && chmod +x ~/subway && ~/subway

500 条线路各视为图上的一个点,分别和地铁站连线

考虑优化,注意到可以预处理维护两个地铁线路的最短距离,再枚举起点终点的线路选择

爆longlong得到负值(原因为数据构造器未保证连通)
*/