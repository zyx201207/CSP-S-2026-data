#include <bits/stdc++.h>

#define int long long
#define ull unsigned long long
#define up(i, a, b) for (int i = a; i <= b; i++)
#define down(i, a, b) for (int i = b; i >= a; i--)
#define unmap unordered_map 
#define pb push_back

using namespace std;

const int N = 5e7 + 101;

// edge
int head[N], nxt[N], to[N], w[N], ecnt;
inline void addedge1 (int u, int v, int weight) {
    to[++ecnt] = v;
    w[ecnt] = weight;
    nxt[ecnt] = head[u];
    head[u] = ecnt;
}
int c, n, m, d, q;
unordered_map <int, vector<int> > mp;
struct heapnode{
    int d, u;
    bool operator < (const heapnode &other) const {
        return other.d < d;
    }
};

inline void dijkstra(int s, vector<int>&dis) {
    priority_queue <heapnode> pq;
    dis[s] = 0;
    pq.push({dis[s], s});
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.d > dis[now.u]) continue;

        for (int e = head[now.u]; e; e = nxt[e]) {
            if (dis[to[e]] > dis[now.u]+ w[e]) {
                dis[to[e]] = dis[now.u] + w[e];
                pq.push({dis[to[e]], to[e]});
            }
        }
    }
}


inline void solve (){
    cin >> c >> n >> m >> d >> q;
    up (i, 1, m) {
        int w;
        cin >> w;
        addedge1(i, i + m, w);
        addedge1(i + m, i, w);
    }
    int k, a, t, la, la1, a2, maxlen = 0;
    up (i, 1, n) {
        cin >> k;
        la = 0;
        a2 = la;
        up (j, 1, k) {
            cin >> a >> t;
            la1 = la;
            la = a + (i + 1) * m;
            addedge1(a + m, la, t);
            addedge1(la, a + m, t);
            if (j == 1)  {
                a2 = a;
                continue;
            }
            addedge1(la1, la, 0);
            addedge1(la, la1, 0);
            maxlen = max(la, maxlen);
        }
        addedge1(a + (i + 1)* m , a2 + (i + 1)* m , 0);
        addedge1(a2 + (i + 1)* m , a + (i + 1)* m , 0);
    }
    int x, y;
    up (i, 1, q) {
        cin >> x >> y;
        if (mp.count(x)) {
            cout << mp[x][y] << '\n';
        }else {
            mp[x].assign(maxlen + 5, 0x3f3f3f3f3f3f3f3f);
            dijkstra(x, mp[x]);
            cout << mp[x][y] << '\n';
        }
    }
}

signed main() {

    freopen ("subway.in","r", stdin);
    freopen ("subway.out","w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();

    return 0;
}

