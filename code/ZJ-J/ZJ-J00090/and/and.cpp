#include <bits/stdc++.h>

using namespace std;

int n, m, a[200010], offset[200010];
vector<int> f;
bool res[31];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f.push_back(i);
    }
    for (int j = 30; j >= 0; j--) {
        vector<int> g;
        for (auto x : f)
            if ((a[x] >> j) & 1)
                g.push_back(x);
        if (g.size() >= m)
            f = g, res[j] = 1;
    }
    int ans = 0;
    for (int i = 0, base = 1; i <= 30; i++, base *= 2)
        ans += (int)res[i] * base;
    printf("%d\n", ans);
    return 0;
}
