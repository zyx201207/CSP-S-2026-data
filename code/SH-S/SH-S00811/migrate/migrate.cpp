#include <bits/stdc++.h>
using namespace std;

int C, T, n, d, a[2000005], dis[2000005];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &C, &T);
    while (T--) {
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int u = 1; u <= n; u++) {
            for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f;
            queue <int> q;
            q.push(u);
            dis[u] = 0;
            vector <int> ans;
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                for (int v = 1; v <= n; v++)
                    if (v != t)
                        if (dis[t] + 1 < dis[v]) {
                            dis[v] = dis[t] + 1;
                            q.push(v);
                        } else if  (dis[t] + 1 == dis[v]) {
                            ans.push_back(v);
                        }
            }
            for (int i : ans)
                printf("%d ", i);
            printf("\n");
        }
    }
    return 0;
}