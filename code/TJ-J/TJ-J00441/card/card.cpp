#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, tot, a[500005], f[300005], lst[300005];
bool in[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int r = 1; r <= n; r++) {
        for (int i = r; i <= n; i++) {
            if (lst[a[i]]) {
                for (int j = lst[a[i]]; j <= tot; j++)
                    in[a[j]] = lst[a[j]] = 0;
                tot = lst[a[i]] - 1;
            }
            in[a[i]] = 1;
            lst[a[i]] = ++tot;
        }
        for (int j = 1; j <= m; j++) {
            if (in[j])
                ++f[j];
            in[j] = lst[j] = 0;
        }
        tot = 0;
    }
    for (int i = 1; i <= m; i++)
        printf("%d ", f[i]);
}

