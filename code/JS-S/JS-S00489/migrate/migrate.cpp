#include<bits/stdc++.h>
using namespace std;
#define N (2000000)
#define ll long long
// check the number type

int c, T;
int n; ll d;
ll dis[N + 5];

int Query(int l, int r) {
    ll y = dis[l] + d, x = dis[r] - d;
    return upper_bound(dis + 1, dis + n + 1, y) - lower_bound(dis + 1, dis + n + 1, x) - 1;
}

void Work() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; ++i) { scanf("%lld", dis + i); }
    bool SubTask1 = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (dis[i] - dis[i + 1] != dis[i + 1] - dis[i + 2]) {
            SubTask1 = 0;
        }
    }
    if (SubTask1) {
        ll a = dis[2] - dis[1];
        ll len = d / a;
        ll ans = 0;
        if (len != 2) { return printf("0\n"), void(); }
        else { printf("%lld\n", 1ll * (n - 3)); }
        return;
    }
    int ans = 0;
    for (int l = 1; l <= n; ++l) {
        vector<int> stk; int sum = 0;
        stk.push_back(l);
        for (int r = l + 1; r <= n; ++r) {
            if (stk.size() >= 2) {
                if (dis[r] - dis[stk[stk.size() - 2]] <= d) {
                    if (stk.size() >= 3) {
                        sum -= Query(stk[stk.size() - 3], stk[stk.size() - 1]);
                    }
                    stk.pop_back();
                }
            }
            stk.push_back(r);
            if (stk.size() >= 3) {
                sum += Query(stk[stk.size() - 3], r);
            }
            if (sum == 1) { ++ans; }
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--) { Work(); }
    return 0;
}
