#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int N = 5e4 + 5;

struct Edge {
    int to, w;
    bool operator < (const Edge& a) const {
        return to > a.to;
    }
};

int c, n, m, d, q, lst, x, y;
int w[N], k[505], a[505][N], t[505][N], dis[N * 25];
bool vis[N * 25];

vector<Edge> vec[N * 25];
vector<int> zzh[N];
priority_queue<Edge> ppq;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        lst = 0;
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            zzh[a[i][j]].push_back(i);
            vec[N + a[i][j] * 22 + (int)zzh[a[i][j]].size()].push_back({ a[i][j], t[i][j] });
            vec[a[i][j]].push_back({ N + a[i][j] * 22 + (int)zzh[a[i][j]].size(), t[i][j] });
            if (lst != 0) {
                vec[N + lst * 22 + (int)zzh[lst].size()].push_back({ N + a[i][j] * 22 + (int)zzh[a[i][j]].size(), 0 });
                vec[N + a[i][j] * 22 + (int)zzh[a[i][j]].size()].push_back({ N + lst * 22 + (int)zzh[lst].size(), 0 });
            }
            lst = a[i][j];
        }
    }

    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        memset(dis, 0x3f3f3f, sizeof dis);
        memset(vis, 0, sizeof vis);
        dis[x] = 0;
        ppq.push({ x, 0 });
        while (!ppq.empty()) {
            Edge u = ppq.top();
            ppq.pop();
            //cout << u.to << ' ' << u.w << ' ';
            if (vis[u.to]) {
                continue;
            }
            vis[u.to] = 1;
            if (u.to == y) {
                break;
            }
            for (auto v : vec[u.to]) {
                //cout << v.to << ' ';
                if (dis[v.to] > dis[u.to] + v.w) {
                    dis[v.to] = dis[u.to] + v.w;
                    ppq.push({ v.to, dis[v.to] });
                }
            }
        }
        cout << dis[y] + w[x] + w[y] << endl;
        while (!ppq.empty()) {
            ppq.pop();
        }
    }
    return 0;
}
