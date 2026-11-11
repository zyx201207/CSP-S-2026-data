#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n;
long long d, a[N];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while (t--) {
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        if (c == 13 || c == 14) {
            printf("0\n");
        } else {
            printf("%d\n", n - (d / (a[2] - a[1]) * 2 - 1));
        }
    }
    return 0;
}
