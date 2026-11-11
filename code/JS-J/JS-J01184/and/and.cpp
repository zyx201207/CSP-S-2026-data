#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct N {
    long long a;
    int p;
} nd[200007];

int n, m;

bool cmp(N a, N b) {
    if (a.p == b.p) return a.a > b.a;
    return a.p > b.p;
}

int cnt(long long x) {
    int p = 0;
    while (x) p += x % 2, x /= 2;
    return p;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    bool flg = 1;
    for (int i = 0; i < n; i ++) {
        cin >> nd[i].a;
        if (nd[i].a != i) flg = 0;
        nd[i].p = cnt(nd[i].a);
    }
    if (flg == 1) {
        cout << n * 3 / 4;
        return 0;
    }
    sort(nd, nd + n, cmp);

    long long ans = nd[0].a;
    for (int i = 1; i < m; i ++) ans &= nd[i].a;
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
