#include <bits/stdc++.h>
#define int long long
#define fr(i, x, y) for (int i = (x); i <= (y); i ++)
#define froepen freopen
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, k[N], w[M], num[M], s[N][N];
vector<int> a[M], t[M];
map<int, vector<pii> > mp; // lines that the station belongs to

int cnt, hd[N + M];
struct Edge{ int to, w, nxt; }e[(N + M) << 1];
void add(int u, int v, int w){
    e[++ cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = hd[u];
    hd[u] = cnt;
}

void dijkstra(int u){
    priority_queue<pii, vector<pii>, greater<pii> > q;
    vector<int> dis(n + m + 1, LLONG_MAX);
    q.push(make_pair(0, u)), dis[u] = 0;
    while (!q.empty()){
        pii f = q.top(); q.pop();
        int d = f.fi, v = f.se;
        if (v > u && v <= n) s[u][v] = s[v][u] = d;
        for (int i = hd[v]; i; i = e[i].nxt){
            int v1 = e[i].to, w = d + e[i].w;
            if (w < dis[v1]) q.push(make_pair(w, v1)), dis[v1] = w;
        }
    }
}

signed main(){
    froepen("subway.in", "r", stdin);
    froepen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    fr(i, 1, m) cin >> w[i];
    fr(i, 1, n){
        cin >> k[i], a[i].resize(k[i] + 1), t[i].resize(k[i] + 1);
        fr(j, 1, k[i]) cin >> a[i][j] >> t[i][j],
            num[a[i][j]] ++, mp[a[i][j]].push_back(make_pair(i, t[i][j]));
    }
    fr(i, 1, n) fr(j, 1, k[i]) if (num[a[i][j]] > 1)
        add(i, n + a[i][j], t[i][j]), add(n + a[i][j], i, t[i][j]);
    fr(i, 1, n) dijkstra(i);
    while (q --){
        int x, y, ans = LLONG_MAX;
        cin >> x >> y;
        for (pii xx : mp[x]) for (pii yy : mp[y]){
            int xid = xx.fi, yid = yy.fi, xl = xx.se, yl = yy.se;
            ans = min(ans, s[xid][yid] + xl + yl);
        }
        cout << w[x] + w[y] + ans << "\n";
    }
    return 0;
}

// 15:36 xiang dao zuo fa le !!!
// bai xie wo chong hao
// Can I get full pts on T2???????
// Just do it!!!!!!!
// 16:18 dai ma bei vscode fang da le bu hui suo xiao
// zhi neng jiang jiu zhe xie le
// 16:47 tiao dai ma hao nan a 
// 17:00 passed all the examples!!!!!!!!!!!!!!!!!!!!!!!!!
// csp-s2 2026 >=200pts seems not impossible
// check repeatedly and make sure no errors.