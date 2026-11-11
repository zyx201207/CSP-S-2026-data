#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c, n, m, d, q, a[500009], T;
bool vis[500009];
vector <int> l[500009];
queue <int> que;
int ans[500009];
void bfs(int st, int ed) {
    que.push(st);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        vis[x] = 1;
        if (x == ed) {
            cout << 2 * ans[ed] * T + a[st] + a[ed] << "\n";
            return;
        }

        for (int i = 0; i < l[x].size(); i++) {
            if (!vis[l[x][i]]) {
                que.push(l[x][i]);
                ans[l[x][i]] = ans[x] + 1;
            }
        }
    }
}
int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }int k, xxxxx, x_, xfir;
    for (int i = 1; i <= n; i++) {

        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> xxxxx >> T;
            if (i != 1) {
                l[xxxxx].push_back(x_);
                l[x_].push_back(xxxxx);
            } else {
                xfir = xxxxx;
            }
            x_ = xxxxx;
        }
        l[xfir].push_back(xxxxx);
        l[xxxxx].push_back(xfir);
    }
    int st, ed;
    for (int i = 1; i <= q; i++) {
        cin >> st >> ed;
       for (int j = 0; j <= m; j++) {
            vis[j] = false;
            ans[j] = 0;
       }
       while(!que.empty()) {
        que.pop();
       }
        bfs(st, ed);
    }
    fclose(stdin);
    fclose(stdout);
}

