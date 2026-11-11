#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q;
int w[M], a[N][N], t[N][N], k[N], x[M], y[M];

vector<pair<int, int>> e1[2005];
int dis1[2005][2005];
bool f1[2005];
struct node1 {
    int pos, dis;
    bool friend operator < (node1 a, node1 b) {
        return a.dis > b.dis;
    }
};
priority_queue<node1> pq1;
void solve1() {
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j < k[i]; j++) 
            for(int z = j + 1; z <= k[i]; z++) 
                e1[a[i][j]].push_back({a[i][z], t[i][j] + t[i][z]}), 
                e1[a[i][z]].push_back({a[i][j], t[i][j] + t[i][z]});
    memset(dis1, 0x3f, sizeof dis1);
    for(int i = 1; i <= m; i++) {
        int st = i;
        memset(f1, 0, sizeof f1);
        pq1.push({st, 0});
        dis1[i][st] = 0;
        while(!pq1.empty()) {
            int now = pq1.top().pos;
            pq1.pop();
            if(f1[now])
                continue;
            f1[now] = 1;
            for(auto x : e1[now]) {
                int enow = x.first;
                if(dis1[i][enow] > dis1[i][now] + x.second)
                    dis1[i][enow] = dis1[i][now] + x.second, pq1.push({enow, dis1[i][now] + x.second});
            }
        }
    }
    for(int i = 1; i <= q; i++)
        cout << w[x[i]] + w[y[i]] + dis1[x[i]][y[i]] << '\n';
    return ;
}

// vector<pair<int, int>> e2[505];
// vector<int> g[500005];
// int dis2[505][205];
// int flag[505][505];
// bool f2[505];
// struct node12 {
//     int pos, dis;
//     bool friend operator < (node1 a, node1 b) {
//         return a.dis > b.dis;
//     }
// };
// priority_queue<node1> pq2;
// void solve2() {
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= k[i]; j++) {
//             g[a[i][j]].push_back(i);
//         }
//     }

// }

bool f[3][505];
int ans[505];
void solve3() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k[i]; j++) {
            f[i][a[i][j]] = 1;
            ans[a[i][j]] += t[i][j];
        }
    }
    int mi = LONG_LONG_MAX;
    for(int i = 1; i <= m; i++) {
        if(f[1][i] && f[2][i])
            mi = min(ans[i], mi);
    }
    for(int i = 1; i <= q; i++) {
        if(f[1][x[i]] && f[1][y[i]] || f[2][x[i]] && f[2][y[i]])
            cout << w[x[i]] + w[y[i]] << '\n';
        else
            cout << mi + w[x[i]] + w[y[i]] << '\n';
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
            cin >> a[i][j] >> t[i][j];
    }
    for(int i = 1; i <= q; i++)
        cin >> x[i] >> y[i];
    if(c >= 0 && c <= 19) {
        solve1();
    }
    if(c >= 20 && c <= 21) {
        solve3();
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, s;
int dis[N];
bool f[N];
struct node {
    int pos, dis;
    bool friend operator < (node a, node b) {
        return a.dis > b.dis;
    }
};
vector<pair<int, int>> e[N];
priority_queue<node> q;
signed main() {
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    memset(dis, 0x3f, sizeof dis);
    q.push({s, 0});
    dis[s] = 0;
    while(!q.empty()) {
        int now = q.top().pos;
        q.pop();
        if(f[now])
            continue;
        f[now] = 1;
        for(auto x : e[now]) {
            int enow = x.first;
            if(dis[enow] > dis[now] + x.second)
                dis[enow] = dis[now] + x.second, q.push({enow, dis[now] + x.second});
        }
    }
    for(int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
}

*/