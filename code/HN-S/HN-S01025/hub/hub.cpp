#include <bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("hub.in");
ofstream fout("hub.out");
const int N = 1e5 + 5, INF = 1e18;
int tc, t, n, k, b[N], ans, v[N], dis, mi; 
vector<int> g[N];
void T(int x, int f) {
    v[x] = 1;
    for (auto i : g[x]) 
        if (!v[i] && i != f && b[i]) 
            T(i, x);
}
void T1(int x, int f, int d) {
    if (d > mi) 
        return;
    if (b[x]) 
        mi = min(mi, d);
    for (auto i : g[x]) 
        if (i != f) 
            T1(i, x, d + 1);
}
void Calc() {
    int cnt = 0, mx = 0;
    for (int i = 1; i <= n; i++) 
        if (b[i] && !v[i]) {
            T(i, 0);
            cnt++;
            if (cnt > 2) 
                return;
        } 
    for (int i = 1; i <= n; i++) 
        if (!b[i]) {
            mi = INF;
            T1(i, 0, 0);
            mx = max(mx, mi);
        }
    ans = min(ans, mx);
}
void dfs(int x, int cnt) {
    if (cnt > k || cnt + (n - x + 1) < k) 
        return;
    if (x > n) {
        if (cnt == k) {
            Calc();
            fill(v + 1, v + n + 1, 0);
        }
        return;
    }
    b[x] = 1;
    dfs(x + 1, cnt + 1);
    b[x] = 0;
    dfs(x + 1, cnt);
}
signed main() {
    for (fin >> tc >> t; t--;) {
        ans = INF;
        fin >> n >> k;
        fill(g + 1, g + n + 1, g[0]);
        fill(v + 1, v + n + 1, 0);
        for (int i = 1, x, y; i < n; i++) {
            fin >> x >> y;
            g[x].push_back(y), g[y].push_back(x);
        }
        dfs(1, 0);
        fout << ans << '\n';
    }
    return 0;
}

/*
背负着火影之名我不能输
luogu UID: 1449703

上善若水，人杰地灵

Rocketcar
*/