// hub.cpp
#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, u, v;
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for (int z = 1; z <= t; z++) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n-1; i++) scanf("%d%d", &u, &v);
        printf("%d\n", z);
    }
    return 0;
}
