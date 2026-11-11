#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
const int M = 3e5;
int n, m, a[N + 10];
int pos[M + 10], nxt[N + 10];
int ans[N + 10];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        pos[i] = n + 1;
    }
    for (int i = n; i >= 1; i--) {
        nxt[i] = pos[a[i]], pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; ) {
            if (nxt[j] == n + 1) {
                ans[a[j]]++;
                j++;
            } else {
                j = nxt[j];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
