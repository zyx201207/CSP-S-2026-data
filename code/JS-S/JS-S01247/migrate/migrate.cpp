#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e6 + 2;
int x[N], swsd;

int main() {
    int c, t;
    scanf("%d%d", &c, &t);
    while (t--) {
        int n, d;
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x[i]);
            swsd += x[i];
        }
    }
    return 0;
}
