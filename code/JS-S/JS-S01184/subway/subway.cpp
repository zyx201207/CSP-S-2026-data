#include<bits/stdc++.h>
using namespace std;

const int N = 505;
const int M = 5e5+5;
int w[M], f[M];
int c, n, m, d, q, ori, dest, minn = 0x3f3f3f3f;
vector <pair<int, int> > ln[N];
vector <pair<int, int> > st[M];

inline int read(){
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while ('0' <= ch && ch <= '9'){
        s *= 10, s += (ch - '0');
        ch = getchar();
    }
    return s;
}

void routeFind(int u, int fa, int tm, int lastLine){
    if (u == dest){
        minn = min(minn, tm);
        return;
    }
    for (pair<int, int> l : st[u]){
        int downl = l.first, downt = l.second;
        if (downl == lastLine) continue;

        int ctm = tm + downt;
        for (pair<int, int> ts : ln[downl]){
            int arri = ts.first, upt = ts.second;
            if (arri == u || arri == fa || (st[arri].size() < 2 && arri != dest)) continue;
            if (ctm + upt > f[arri]) continue;
            f[arri] = ctm + upt;
            routeFind(arri, u, f[arri], downl);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; ++i) w[i] = read();
    for (int i = 1; i <= n; ++i){
        int k = read();
        for (int j = 1; j <= k; ++j){
            int stid = read(), wt = read();
            ln[i].push_back(make_pair(stid, wt));
            st[stid].push_back(make_pair(i, wt));
        }
    }

    while (q--){
        memset(f, 0x3f, sizeof f);
        minn = 0x3f3f3f3f;

        ori = read(), dest = read();
        f[ori] = 0;
        routeFind(ori, ori, 0, -1);
        minn += w[ori] + w[dest];
        cout << minn << "\n";
    }
    return 0;
}
