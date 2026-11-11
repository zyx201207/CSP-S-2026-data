#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 8;
int n, m, ans, cnt;
vector <int> v[2];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n; i++) scanf("%d", &x), v[0].push_back(x);
    for (int i = 30; i >= 0; i--) {
        cnt = 0;
        v[i + 1 & 1].clear();
        for (int x : v[i & 1]) if ((x >> i) & 1) v[i + 1 & 1].push_back(x);
        if (v[i + 1 & 1].size() < m) v[i + 1 & 1] = v[i & 1];
        else ans += (1 << i);
    }
    printf("%d\n", ans);
    return 0;
}
