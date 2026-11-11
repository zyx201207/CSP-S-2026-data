#include <iostream>
#include <cstdio>
#include <queue>
#include <unordered_map>
using namespace std;
#define ll long long
//#define int long long
int c, t;
int n;
ll d;
ll x[2000005];
struct C {
    int id;
    int dis;
    string s;
    C() {}
    C(int id, int dis, string s): id(id), dis(dis), s(s) {

    }
};
int dis[5005][5005];
bool bfs2(int s, int e) {
    queue<C> q;
    int co = 0;
    q.push(C(s, 0, to_string(s)));
    unordered_map<string, bool> vis;
    while (!q.empty()) {
        C &c = q.front();
        q.pop();
        if (c.id == e) {
            //cout << c.s << ": " << c.dis << " ";
            if (c.dis == dis[s][e]) {
                ++co;
                //cout << "true\n";
            }
            // else {
                //cout << "\n";
            //}
            continue;
        }
        //printf("[%d %d]\n", c.id + 1, e);
        for (int i = c.id + 1; i <= e; ++i) {
            if (abs(x[i] - x[c.id]) <= d && !vis.count(c.s + "->" + to_string(i))) {
                q.push(C(i, c.dis + 1, c.s + "->" + to_string(i)));
                vis[c.s + "->" + to_string(i)] = true;
                //cout << (c.s + "->" + to_string(i)) << '\n';
            } else {
                break;
            }
        }
    }
    return co == 2;
}
void bfs1(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push({0, s});
    while (!q.empty()) {
        pair<int, int> u = q.top();
        q.pop();
        for (int i = u.second + 1; i <= n; ++i) {
            if (abs(x[i] - x[u.second]) <= d) {
                if (dis[s][i] > dis[s][u.second] + 1) {
                    //printf("%d -> %d = %d\n", u.second, i, dis[s][u.second] + 1);
                    q.push({dis[s][i] = dis[s][u.second] + 1, i});
                }
            } else {
                //printf("|%d - %d| = %d\n", x[i], x[u.second], abs(x[i] - x[u.second]));

                break;
            }
        }
    }
}
signed main() {
    freopen("mlgrate.in", "r", stdin);
    freopen("mlgrate.out", "w", stdout);
    //freopen("test", "r", stdin);
    scanf("%d%d", &c, &t);
    while (t--) {
        int ans = 0;
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &x[i]);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) {
                    dis[i][j] = 2e+9;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            bfs1(i);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                ans += bfs2(i, j);
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}
