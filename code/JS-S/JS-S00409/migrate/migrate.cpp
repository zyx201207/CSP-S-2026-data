#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int C, T;
int n;
long long d, pos[N + 10];

vector<int> g[N + 10];
int dist[N + 10], num[N + 10];
int bfs(int s) {
    for (int i = 1; i <= n; i++) {
        dist[i] = -1, num[i] = 0;
    }
    dist[s] = 0, num[s] = 1;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : g[x]) {
            if (dist[i] == -1) {
                dist[i] = dist[x] + 1;
                num[i] = min(3, num[i] + num[x]);
                q.push(i);
            } else if (dist[i] == dist[x] + 1){
                num[i] = min(3, num[i] + num[x]);
            }
        }
    }
    if (C == 11 || C == 12) {
        long long res = 0;
        for (int i = 2; i <= n; i++) {
            if (num[i] == 2) {
                res += (n - i + 1);
            }
        }
        return res;
    }
    int res = 0;
    for (int i = s + 1; i <= n; i++) {
        res += (num[i] == 2);
    }
    return res;
}
int calc() {
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += bfs(i);
    }
    return ans;
}

void clean() {
    for (int i = 1; i <= n + 5; i++) {
        pos[i] = 0;
    }
    for (int i = 1; i <= n + 5; i++) {
        g[i].clear();
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &C, &T);
    while (T--) {
        clean();
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &pos[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n && pos[j] - pos[i] <= d; j++) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        if (C == 11 || C == 12) {
            printf("%d\n", bfs(1));
            continue;
        }
        printf("%d\n", calc());
    }
    return 0;
}
