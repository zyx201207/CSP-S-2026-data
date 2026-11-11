#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int main() {
    printf("13 1000\n");
    for (int _ = 1; _ <= 1000; ++_) {
        int m = rnd() % 5 + 1, k = rnd() % (2 * m + 1) + 1;
        printf("%d %d\n", 2 * m + 1, k);
        for (int i = 1; i <= m; ++i) printf("%d %d\n", i, i + 1);
        for (int i = m + 1; i < 2 * m + 1; ++i) printf("%d %d\n", i - m, i + 1); puts("");
    }
    return 0;
}