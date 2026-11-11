#include <iostream>
using namespace std;
int c, t, n, k, u, v;
void solve() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i)
        scanf("%d%d", &u, &v);
    if (k == n) printf("0\n");
    else printf("1\n");
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) solve();
    return 0;
}