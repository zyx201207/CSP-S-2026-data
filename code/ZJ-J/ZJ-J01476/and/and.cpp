#include <bits/stdc++.h>
using namespace std;
int n, m;
namespace alg1 {
    const int INF = (1 << 30) - 1;
    int a[200050], ans;
    void solve () {
        for (int i = 1; i <= n; i ++) scanf ("%d", &a[i]);
        sort(a + 1, a + n + 1);
        ans = INF;
        for (int i = n; i >= n - m + 1; i --) ans = ans & a[i];
        printf ("%d\n", ans);
    }
}
namespace alg2 {
    int solve (int top, const vector<int> &a, const vector<int> &cnt) {
        int dig = -1;
        for (int i = top; ~i; i --)
            if (cnt[i] >= m) { dig = i; break; }
        if (dig < 0) return 0;
        if (dig == 0) return 1;
        vector<int> na, ncnt(30, 0);
        top = dig - 1;
        for (int i : a)
            if (i & (1 << dig)) na.push_back(i);
        for (int i : na)
            for (int j = top; ~j; j --)
                if (i & (1 << j)) ncnt[j] ++;
        return (1 << dig) + solve(top, na, ncnt);
    }
    void work () {
        vector<int> a(n, 0), cnt(30, 0);
        for (int &i : a) scanf ("%d", &i);
        for (int i : a)
            for (int j = 29; ~j; j --)
                if (i & (1 << j)) cnt[j] ++;
        printf ("%d\n", solve(29, a, cnt));
    }
}
int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    if (m == 1 || m == n) alg1::solve();
    else alg2::work();
}