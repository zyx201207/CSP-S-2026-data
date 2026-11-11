#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 505, maxm = 2e4 + 5;
int c, n, m ,d, r;
int www[maxm], a[maxn][maxm], t[maxn][maxm];
struct node{
    int pos, dis, line;
};
int k[maxn];
bool in_i[maxn][maxm];
int vis[maxm];
queue<node> q;
int bfs(int s, int e) {
    fill(vis + 1, vis + m + 1, INT_MAX);
    int res = INT_MAX;
    while (!q.empty()) q.pop();
    node st;
    for (int i = 1; i <= n; i++) {
        if (in_i[i][s]) {
            st.line = i;
            st.dis = t[i][s];
            for (int j = 1; j <= k[i]; j++) {
                st.pos = a[i][j];
                q.push(st);
                vis[st.pos] = min(vis[st.pos], st.dis);
            }
        }
    }
    while (!q.empty()) {
        node fa = q.front();
        q.pop();
        if (fa.pos == e) {
            res = min(res, fa.dis + t[fa.line][e]);
            continue;
        }
        node son;
        for (int i = 1; i <= n; i++) {
            if (in_i[i][fa.pos]) {
                son.line = i;
                son.dis = fa.dis;
                if (son.line != fa.line) son.dis += t[fa.line][fa.pos] + t[son.line][fa.pos];
                for (int j = 1; j <= k[i]; j++){
                    if (vis[a[i][j]] > son.dis) {
                        son.pos = a[i][j];
                        q.push(son);
                        vis[son.pos] = son.dis;
                    }
                }
            }
        }
    }
    return res;
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> r;
    for (int i = 1; i <= m; i++) cin >> www[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            in_i[i][a[i][j]] = true;
        }
    }
    int ans;
    while (r--) {
        int s, e;
        cin >> s >> e;
        ans = bfs(s, e) + www[s] + www[e];
        cout << ans << endl;
    }
    return 0;
}
