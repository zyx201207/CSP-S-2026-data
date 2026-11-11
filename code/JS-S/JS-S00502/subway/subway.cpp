#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
int a[M];
int t[M];
int kt;
int pre[25 * M];
int k;
int c, n, m, d, q;
int w[M];
long long dis[25 * M];
bool vis[25 * M];
int id[M];
struct node {
    int to, next;
    long long w;
}au[25 * M];

struct ed{
    int x, y, id;
    long long ans;
}que[100005];

void add(int u, int v, long long w) {
    //cout << u << " " << v << " " << w << endl;
    au[++k] = {v, pre[u], w};
    pre[u] = k;
}

void spfa(int x) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(x);
    vis[x] = true;
    dis[x] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        vis[t] = false;
        for (int i = pre[t]; i; i = au[i].next) {
            int to = au[i].to;
            if (dis[to] > dis[t] + au[i].w) {
                dis[to] = dis[t] + au[i].w;
                //cout << to << " " << t << " " << dis[to] << " " << dis[t] << " " << au[i].w << endl;
                if (!vis[to]) {
                    q.push(to);
                    vis[to] = true;
                }
            }
        }
    }
}

bool cmp(ed x, ed y) {
    return x.x < x.x;
}

bool cmpid(ed x, ed y) {
    return x.id < y.id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }

    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> kt;
        for (int j = 1; j <= kt; j++) {
            cin >> a[j] >> t[j];
        }
        id[a[1]]++;
        for (int j = 2; j <= kt; j++) {
            add(22 * a[j - 1] + (id[a[j - 1]]) + 1, 22 * a[j] + (++id[a[j]]) + 1, 0);
            add(22 * a[j - 1] + id[a[j - 1]] + 1, 22 * a[j - 1] + 1, t[j - 1]);
            add(22 * a[j - 1] + 1, 22 * a[j - 1] + id[a[j - 1]] + 1, t[j - 1]);
            add(22 * a[j] + id[a[j]] + 1, 22 * a[j] + 1, t[j]);
            add(22 * a[j] + 1, 22 * a[j] + id[a[j]] + 1, t[j]);
        }
    }

    for (int i = 1; i <= q; i++) {
        cin >> que[i].x >> que[i].y;
        que[i].id = i;
    }

    sort(que + 1, que + 1 + q, cmp);

    int tx = -1;
    for (int i = 1; i <= q; i++) {
        if (tx != que[i].x) {
            spfa(22 * que[i].x + 1);
        }
        que[i].ans = dis[22 * que[i].y + 1] + w[que[i].x] + w[que[i].y];
    }

    sort(que + 1, que + 1 + q, cmpid);
    for (int i = 1; i <= q; i++)
        cout << que[i].ans << "\n";
    return 0;
}
