// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// const int N = 2e6 + 5;
// int c, t, n, d, depth[N], td[N], mxd[N], cnd[N], mxd2[N];
// vector <pair <int, bool> > e[N];
// priority_queue <pair <int, int> > que;
// void dfs(int x, int fa) {
//     depth[x] = depth[fa] + 1;
//     for (auto i : e[x])
//         if (i.first != fa)
//             dfs(i.first, x);
// }
// void dfs2(int x, int fa) {
//     td[x] = td[fa] + 1;
//     for (auto i : e[x])
//         if (i.first != fa && i.second) {
//             dfs2(i.first, x);
//             if (mxd[i.first] > mxd[x]) mxd2[x] = mxd[x], mxd[x] = mxd[i.first], cnd[x] = cnd[i.first];
//             else if (mxd[i.first] == mxd[x]) cnd[x] += cnd[i.first];
//         }
//     if (e[x].size() == 1) mxd[x] = td[x], cnd[x] = 1;
// }
// signed main() {
//     // freopen("hub.in", "r", stdin);
//     // freopen("hub.out", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     cin >> c >> t;
//     while (t--) {
//         int ans = 1e18;
//         cin >> n >> d;
//         for (int i = 1; i <= n; i++)
//             e[i].clear(), depth[i] = 0;
//         for (int i = 1, u, v; i <= n - 1; i++)
//             cin >> u >> v, e[u].push_back({v, true}), e[v].push_back({u, true});
//         for (int i = 1; i <= n; i++)
//             sort(e[i].begin(), e[i].end());
//         dfs(1, 0);
//         if (d == 1) {
//             dfs2(1, 0);
//             int temp1 = 1, p = 0;
//             while (!que.empty()) que.pop();
//             while (cnd[temp1] <= 1 && p != mxd[temp1]) {
//                 for (auto k : e[temp1])
//                     if (td[k.first] > td[temp1] && k.second && mxd[k.first] == mxd[temp1]) 
//                         temp1 = k.first, p = max(p + 1, mxd2[k.first]);
//             }
//             dfs2(temp1, 0);
//             for (auto k : e[temp1])
//                 if (k.second) que.push({mxd[k.first], k.first});
//             for (int k = 3; k <= d; k++) {
//                 auto tt = que.top();
//                 que.pop();
//                 for (auto pp : e[tt.second])
//                     if (pp.second && depth[pp.first] > depth[tt.second])
//                         que.push({mxd[pp.first], pp.first});
//             }
//             ans = min(ans, que.top().first);
//             cout << ans << endl;
//             continue;
//         }
//         for (int i = 1; i <= n; i++)
//             for (int j = 0; j < e[i].size(); j++) {
//                 int pt = e[i][j].first;
//                 cout << i << ' ' << j << endl;
//                 if (depth[i] < depth[pt]) {
//                     cout << 1 << endl;
//                     int it = lower_bound(e[pt].begin(), e[pt].end(), make_pair(i, true)) - e[pt].begin();
//                     e[i][pt].second = e[pt][it].second = false;
//                     cout << it << endl;
//                     dfs2(i, 0), dfs2(pt, 0);
//                     cout << 1 << endl;
//                     int temp1 = i, p = 0;
//                     while (!que.empty()) que.pop();
//                     while (cnd[temp1] <= 1 && p <= mxd[temp1]) {
//                         cout << temp1 << endl;
//                         for (auto k : e[temp1]) {
//                             cout << k.first << endl;
//                             if (td[k.first] > td[temp1] && k.second && mxd[k.first] == mxd[temp1])  {
//                                 temp1 = k.first, p = max(p + 1, mxd2[k.first]);
//                                 break;
//                             }
//                         }
//                     }
//                     cout << 1 << endl;
//                     dfs2(temp1, 0);
//                     cout << 1 << endl;
//                     for (auto k : e[temp1])
//                         if (k.second) que.push({mxd[k.first], k.first});
//                     temp1 = pt, p = 0;
//                     cout << 1 << endl;
//                     while (cnd[temp1] <= 1 && p <= mxd[temp1]) {
//                         for (auto k : e[temp1])
//                             if (td[k.first] > td[temp1] && k.second && mxd[k.first] == mxd[temp1]) 
//                                 temp1 = k.first, p = max(p + 1, mxd2[k.first]);
//                     }
//                     cout << 1 << endl;
//                     dfs2(temp1, 0);
//                     cout << 1 << endl;
//                     for (auto k : e[temp1])
//                         if (k.second) que.push({mxd[k.first], k.first});
//                     for (int k = 3; k <= d; k++) {
//                         auto tt = que.top();
//                         que.pop();
//                         for (auto pp : e[tt.second])
//                             if (pp.second && depth[pp.first] > depth[tt.second])
//                                 que.push({mxd[pp.first], pp.first});
//                     }
//                     cout << 1 << endl;
//                     ans = min(ans, que.top().first);
//                     e[i][pt].second = e[pt][it].second = true;
//                 }
//             }
//         cout << ans << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 25;
int c, t, n, d, ooo;
vector <int> e[N];
// bitset <N> vis;
// void dfs(int x, int fa) {
//     if (!(ooo & (1 << (x - 1)))) return ;
//     vis[x] = true;
//     for (int i : e[x])
//         if (i != fa) dfs(i, x);
// }
// void bfs(int x) {
//     queue <pair <int, int> > que;
//     que.push({x, 0});
//     while (!que.empty()) {
//         auto t = 
//     }
// }
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1, u, v; i <= n - 1; i++)
            cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
        cout << n / 4 << endl;
        // for (int i = 0; i < (1 << n); i++) 
        //     if (__builtin_popcount(i) == d) {
        //         vis.reset();
        //         ooo = i;
        //         int cnt = 0;
        //         for (int j = 1; j <= n; j++)
        //             if (!vis[j]) dfs(j, 0), cnt++;
        //         if (cnt > 2) continue;

        //     }
    }
    return 0;
}