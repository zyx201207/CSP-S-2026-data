#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 2e6 + 5;
int c, t, n, d, x[N];
int depth, cnt;
bool flag;
int ans;

void iddfs(int step, int ed, int deep, int way) {
    // printf("%d %d %d\n", step, deep, way);
    if (way > deep)
        return;
    if (step == ed && way == deep) {
        cnt++;
        return;
    }
    for (int i = step + 1; i <= ed; i++) {
        if (x[i] - x[step] > d)
            break;
        iddfs(i, ed, deep, way + 1);
    }
}

void solve() {
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            flag = false;
            depth = 1;
            for (depth = 1; depth <= n; depth++) {
                cnt = 0;
                iddfs(i, j, depth, 0);
                // printf("from %d to %d, when long:%d, way:%d\n", i, j, depth, cnt);
                if (cnt == 2) {
                    ans++;
                    break;
                }
            }
        }
    // iddfs(2, 4, 2, 0);
    // cout << cnt << endl;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while (t--) {
        scanf("%d %d", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%d", &x[i]);

        solve();

        printf("%d\n", ans);
    }
    return 0;
}