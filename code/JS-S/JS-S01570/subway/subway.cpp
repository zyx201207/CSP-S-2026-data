#include<bits/stdc++.h>
using namespace std;

struct node{
    int st;
    long long t;
};
struct karf{
    int li;
    long long t;
};
const int N = 5e5+5;
int c, n, m, d, q;
long long in[N];
vector<node> line[505];
vector<karf> station[N];
bool vis[N];
queue<node>ps_st;

long long bfs(int srt, int fin) {
    for (int i = 1; i <= m; ++i) vis[i] = 0;
    vis[srt] = 1;
    while (!ps_st.empty()) ps_st.pop();
    ps_st.push({srt,0});
    long long mint = INT_MAX;

    while (!ps_st.empty()) {
        int u = ps_st.front().st;
        long long nowt = ps_st.front().t;
        ps_st.pop();
        if (nowt >= mint) continue;
        if (u == fin) {
            mint = min(mint,nowt);
            continue;
        }
        for (karf k:station[u]) {
            int lv = k.li;
            for (node v : line[lv]) {
                if (!vis[v.st]) {
                    vis[v.st] = 1;
                    ps_st.push({v.st, nowt+v.t+k.t});
                }
            }
        }
    }
    if(mint == INT_MAX) return 0;
    return mint;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> in[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int st,te;
            cin >> st >> te;
            line[i].push_back({st,te});
            station[st].push_back({i,te});
        }
    }

    for (int i = 1; i <= q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << bfs(u, v) + in[u] + in[v] << endl;
    }
    return 0;
}
