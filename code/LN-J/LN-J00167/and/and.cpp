#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n, m, a[MAXN], cnt[35], ans;
int mpos = 127;

bool cmp(int n1, int n2) {
    return n1 > n2;
}

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 30; j++) {
            if (a[i] & (1 << j)) {
                cnt[j]++;
            }
        }
    }
    /*for (int j = 30; j >= 0; j--) {
        printf("%d ", cnt[j]);
    }
    puts("");*/
    for (int j = 30; j >= 0; j--) {
        if (cnt[j] >= m) {
            mpos = j;
            break;
        }
    }
    if (mpos == 127) {
        printf("0");
        return 0;
    }
    // printf("%d\n", mpos);
    for (int i = 1; i <= n; i++) {
        a[i] &= ((1 << (mpos + 1)) - 1);
        // printf("%d ", a[i]);
    }
    // puts("");
    sort(a + 1, a + n + 1, cmp);
    ans = a[1];
    for (int i = 2; i <= m; i++) {
        ans &= a[i];
    }
    printf("%d", ans);
    return 0;
}
