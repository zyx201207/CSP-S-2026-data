

#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;
int n, m;
//unordered_set<int> a;
int a[200005];
int ans;
void dfs(int i, int pos, int x) {
    if (i == m || pos > n) {
        ans = max(ans, x);
        return;
    }
    dfs(i + 1, pos + 1, x);
    dfs(i + 1, pos + 1, x & a[pos]);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    if (m == 1) {
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, a[i]);
        }
    } else if (m == 2) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                ans = max(ans, a[i] & a[j]);
            }
        }
    } else {
        dfs(0, 1, 2147483647);
    }
    printf("%d\n", ans);
    return 0;
}

