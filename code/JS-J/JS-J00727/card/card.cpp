#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
bool flag[500005];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if (n <= 500) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) flag[j] = false;
            for (int j = i; j <= n;j++) {
                if (flag[j]) continue;
                int id = -1;
                for (int k = i; k < j; k++) {
                    if (flag[k]) continue;
                    if (a[k] ==  a[j]) {
                        id = k;
                        break;
                    }
                }
                if (id != -1) {
                    for (int k = id; k < j; k++) flag[k] = true;
                }
            }
            for (int j = i; j <= n;j ++) {
                if (flag[j])continue;
                cnt[a[j]]++;
            }
        }
        for (int i = 1; i <= m; i++) {
            printf("%d ", cnt[i]);
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        cnt[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", cnt[i]);
    }
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
