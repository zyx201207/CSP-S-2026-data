#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
int n, k, fa[N], dep[N], se[N], d[N], o[N], to[N], res;
int ch[N], idx;
vector<int> dr[N];
void dfs(int u, int Fa) {
    fa[u] = Fa;
    for (int v : dr[u]) {
        if (v == Fa)
            continue;
        dfs(v, u);
        if (dep[v] + 1 > dep[u])
            se[u] = dep[u], dep[u] = dep[v] + 1;
        else
            se[u] = max(se[u], dep[v] + 1);
    }
}
int solve(int x) {
    int L = 0, R = idx + 1;
    for (int i = 1; i <= n; i ++) {
        if (ch[i] + min(i, idx - i + 1) <= x)
            continue;
        if (i <= idx - i + 1)
            L = max(L, ch[i] + i - x);
        else
            R = min(R, idx - (ch[i] + (idx - i + 1) - x) + 1);
    }
    return max(idx - x * 2, L + idx - R + 1);
}
void dfs2(int u, int x) {
    if (d[u] == 2 && u != 1) {
        idx = 0;
        while (d[u] == 2) {
            ch[++ idx] = se[u];
            u = to[u];
        }
        res = max(res, idx - solve(x));
        return;
    }
    for (int v : dr[u]) {
        if (v == fa[u] || !o[v])
            continue;
        dfs2(v, x);
    }
}
bool check(int x) {
    int num = 0;
    res = 0;
    for (int i = 1; i <= n; i ++)
        d[i] = o[i] = 0;
    for (int i = 1; i <= n; i ++) {
        if (dep[i] >= x) {
            o[i] = 1, num ++;
            if (i != 1)
                d[i] ++, d[fa[i]] ++, to[fa[i]] = i;
        }
    }
    dfs2(1, x);
    if (d[1] == 2) {
        idx = 0;
        int u = dr[1][0];
        while (d[u] == 2) {
            ch[++ idx] = se[u];
            u = to[u];
        }
        reverse(ch + 1, ch + idx + 1);
        ch[++ idx] = 0;
        u = dr[1][1];
        while (d[u] == 2) {
            ch[++ idx] = se[u];
            u = to[u];
        }
        res = max(res, idx - solve(x));
    }
    return (num - min(res, 2 * x) <= k);
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while (T --) {
        cin >> n >> k;
        for (int i = 1; i <= n; i ++)
            dep[i] = 0, dr[i].clear();
        for (int i = 1, u, v; i < n; i ++) {
            cin >> u >> v;
            dr[u].push_back(v);
            dr[v].push_back(u);
        }
        dfs(1, 0);
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r >> 1);
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << '\n';
    }
    return 0;
}
/*
二分转为判定
子树距离>mid的点必填且优
现在要在一个树中扣掉尽可能多的点使得扣完后为两个连通块
只能扣度为2的点，直接搜，注意链长不能超过2mid
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
