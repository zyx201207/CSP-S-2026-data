#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1, M = 3e5 + 1;
int n, m, a[N];
int h, t, table[N], o[M];
int ans[M];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    for (int g = 1;g <= n;g++) {
        h = 1, t = 0;
        memset(o, 0, sizeof(o));
        for (int i = g;i <= n;i++) {
            if (!o[a[i]]) {
                table[++t] = a[i];
                o[a[i]] = t;
            } else {
                for (int j = o[a[i]]+1;j <= t;j++) {o[table[j]] = 0;table[j] = 0;}
                t = o[a[i]];
            }
        }
        for (int i = h;i <= t;i++)
            ans[table[i]]++;
    }
    for (int i = 1;i <= m;i++) printf("%d ", ans[i]);
}
