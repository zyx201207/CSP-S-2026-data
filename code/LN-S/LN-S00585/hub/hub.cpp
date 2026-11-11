#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 15;

int n, k;
int h[N], e[N << 1], ne[N << 1], idx;
int fa[N];
bool st[N];
int d[N], mind[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int solve() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    int res = n;

    for (int state = 1; state < (1 << n); state ++ ) {
        memset(st, false, sizeof st);
        for (int i = 1; i <= n; i ++ ) fa[i] = i;
        int tot = 0;
        for (int i = 1; i <= n; i ++ ) 
            if ((state >> i - 1) & 1) st[i] = true, tot ++ ;
        if (tot != k) continue;
        for (int i = 1; i <= n; i ++ ) {
            if (!st[i]) continue; 
            int ffa = find(i);
            for (int j = h[i]; ~j; j = ne[j]) {
                int k = e[j];
                if (!st[k]) continue;
                int ffb = find(k);
                if (ffa == ffb) continue;
                fa[ffb] = ffa;
                tot -- ;
            }
        }


        if (tot > 2) continue;

        int maxd = 0;
        queue<int> q;
        for (int i = 1; i <= n; i ++ ) 
            if (st[i])
                d[i] = 0, q.push(i);
        
        while (!q.empty()) {
            int t = q.front(); q.pop();
            // printf("#%d\n", t);
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                // printf("@%d\n", j);
                if (!st[j]) d[j] = d[t] + 1, maxd = max(maxd, d[j]), st[j] = true, q.push(j);
            }
        }
        // printf("!!%d\n", maxd);
        res = min(res, maxd);
    }
    printf("%d\n", res);

    return 0;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, T;
    scanf("%d%d", &c, &T);
    while (T -- ) {
        solve();
    }
    return 0;
}