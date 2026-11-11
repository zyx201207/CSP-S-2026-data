#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define __Debug

using namespace std;
typedef long long ll;
const int N = 2e2 + 10;

int c, T;
int n, d;
int tot;
ll a[N];

void Dfs(int cur, int cnt, int def) {
    if (cur == def) {
        tot++;
        return ;
    }
    if (cnt == 0) return ;
    for (int i = cur + 1; i <= def; i++) {
        if (a[i] - a[cur] <= d) {
            Dfs(i, cnt - 1, def);
        } else return;
    }
}
bool Check(int x, int y) {
    for (int i = x + 1; i <= y; i++) {
        if (a[i] - a[i - 1] > d) return false;
    }
    int u = x, cnt = 0;
    for (int i = x; i <= y; i++) {
        if  (a[i + 1] - a[u] > d) {
            u = i;
            cnt++;
        }
    }
    if (u != y) cnt++;
    tot = 0;
    Dfs(x, cnt, y);
    return tot == 2;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int j = 1; j < i; j++) {
                ans += Check(j, i);
            }
        }
        printf("%d\n", ans);
    }  
    return 0;
}