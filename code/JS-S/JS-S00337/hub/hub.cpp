#include <bits/stdc++.h>
using namespace std;

/*
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

const int N = 1e6+5, B = 20, N1 = 15;
vector<int> g[N];
int n, k;
int st[N][B], po[B];
bool e[N1][N1];
int ans[N], idd;
int fa[N];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    int u = find(x), v = find(y);
    if (u != v) {
        fa[u] = v;
    }
}

void baoli(int step, int had)
{
    if (step > n + 1) {
        return;
    }
    if (had == k) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        for (int i = 1; i < k; i++) {
            merge(ans[i], ans[i + 1]);
        }
        int cnt = 0;
        for (int i = 1; i <= k; i++) {
            cnt += find(i) == i;
        }
        if (cnt < 3) {
            for(int i=1;i<=k;i++)cout<<ans[i]<<' ';cout<<'\n';
        }
    }
    for (int i = step; i <= n; i++) {
        ans[had + 1] = i;
        baoli(i + 1, had + 1);
        ans[had + 1] = 0;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int _;
    cin >> _ >> _;
    po[0] = 1;
    for (int i = 1; i < B; i++) {
        po[i] = po[i - 1] * 2;
    }
    while (_--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            e[u][v] = true;
        }
        baoli(1, 0);
    }

    return 0;
}