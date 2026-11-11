#include <bits/stdc++.h>
using namespace std;
int T = 10, nn = 100, v = 100;
int main() {
    freopen("data.in", "w", stdout);
    random_device o;
    mt19937 rnd(o());
    printf("0 %d\n", T);
    while (T--) {
        int n = rnd() % nn + 1, d = rnd() % v + 3;
        printf("%d %d\n", n, d);
        for (int i = 1, x = 0; i <= n; ++i) {
            printf("%d ", x);
            x += rnd() % (d + 1) + 1;
        } puts("");
    }
    return 0;
}