// migrate.cpp
#include <bits/stdc++.h>
using namespace std;
int c, t, n, d;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for (int z = 1; z <= d; z++) {
        scanf("%d%d", &n, &d);
        int x[n+5];
        for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
        printf("%d\n",z-1);
    }
    return 0;
}
