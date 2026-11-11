#include <bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("migrate.in");
ofstream fout("migrate.out");
const int N = 1e6 + 5, INF = 1e18;
int T, t, n, d, a[N], dis[N], f[N], b[N], ans;
vector<int> g[N];
signed main() {
    for (fin >> T >> t; t--; ans = 0) {
        fin >> n >> d; 
        fill(g + 1, g + n + 1, g[0]);
        for (int i = 1; i <= n; i++) {
            fin >> a[i];
            for (int j = 1; j < i; j++) 
                (a[i] - a[j] <= d) && (g[j].push_back(i), 0);
        } 
        for (int i = 1; i <= n; i++) {
            fill(dis + i, dis + n + 1, INF);
            fill(f + i, f + n + 1, 0);
            queue<int> q;
            q.push(i), dis[i] = 0, f[i] = 1; 
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (auto j : g[x])
                    if (dis[j] == INF) 
                        dis[j] = dis[x] + 1, f[j] = f[x], q.push(j);
                    else if (dis[j] == dis[x] + 1) 
                        f[j] += f[x];
            }
            for (int j = i + 1; j <= n; j++) {
                if (dis[j] == INF)
                    break;
                ans += (f[j] == 2);
            }
        }
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