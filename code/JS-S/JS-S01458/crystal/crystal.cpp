#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> v, sum;
bool check(int i, int len) {
    return v[i] * len - (sum[i] - sum[i - len]) <= m;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    v.resize(n + 1);
    sum.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
    }
    sort(v.begin() + 1, v.end());
    for (int i = 1; i <= n; i++) {
        sum[i] = v[i] + sum[i - 1];
        //cout << sum[i] << ' ';
    }
    //cout << endl;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        for (;l < r;) {
            int mid = (l + r) / 2 + 1;
            if (check(i, mid)) l = mid;
            else r = mid - 1;
        }
        res = max(res, l);
        //cout << l << ' ';
    }
    printf("%lld", res);
    return 0;
}
