#include <bits/stdc++.h>
#define Mem(a,b) memset((a),(b),sizeof((a)))
#define pb push_back
#define eb emplace_back
using i64 = long long;
using uint = unsigned int;
using ui64 = unsigned long long;
using i128 = __int128;
using namespace std;
constexpr int N = 5e5 + 15, mod = 998244353;

int n;
i64 m, a[N], b[N], d[N];
int cnt[N];

inline i64 greedy1 (i64 m) {
    int ans = 0, pos = 1;
    for (int i = 1; i <= n; ++ i) {
        if (ans <= cnt[a[i]]) {
            ans = cnt[a[i]];
            pos = i;
        }
    }
    // printf ("ans: %d   pos: %d  val: %lld\n", ans, pos, b[a[pos]]);
    for (int i = pos - cnt[a[pos]]; i >= 1; -- i) {
        if (m - labs(b[a[pos]] - b[a[i]]) >= 0) {
            m -= labs(b[a[pos]] - b[a[i]]);
            ++ ans;
        } else break;
    }
    // printf ("ans: %d   m: %lld\n", ans, m);
    // int res = pos + cnt[a[pos]];
    int Ans = ans;
    if (m > 0) {
        int xx = 0;
        for (int i = pos + 1; i <= n; ++ i) {
            // res = i;
            int l = 0, r = i - 1 - xx, res = 0;
            while (l <= r) {
                int mid = l + r >> 1;
                if (m - 1ll * mid * labs(b[a[i]] - b[a[i - 1]]) >= 0) res = mid, l = mid + 1;
                else r = mid - 1;
            }
            if (m - 1ll * res * labs(b[a[i]] - b[a[i - 1]]) >= 0) {
                m -= 1ll * res * labs(b[a[i]] - b[a[i - 1]]);
                ans = res + 1;
                Ans = max(Ans, ans);
                xx = i - 1 - res;
                // printf("%d ", ans);
            } else break;
        }
        // puts ("");
    }
    // printf ("ans: %d   m: %lld   res: %d   val: %lld\n", ans, m, res, b[a[res]]);
    return Ans;
}

inline i64 greedy2(i64 m) {
    int ans = 0, pos = 1;
    for (int i = 1; i <= n; ++ i) {
        if (ans < cnt[a[i]]) {
            ans = cnt[a[i]];
            pos = i;
        }
    }
    // printf ("ans: %d   pos: %d  val: %lld\n", ans, pos, b[a[pos]]);
    for (int i = pos - 1; i >= 1; -- i) {
        if (m - labs(b[a[pos]] - b[a[i]]) >= 0) {
            m -= labs(b[a[pos]] - b[a[i]]);
            ++ ans;
        } else break;
    }
    // printf ("ans: %d   m: %lld\n", ans, m);
    // int res = pos + cnt[a[pos]];
    int Ans = ans;
    if (m > 0) {
        int xx = 0;
        for (int i = pos + cnt[a[pos]]; i <= n; ++ i) {
            // res = i;
            int l = 0, r = i - 1 - xx, res = 0;
            while (l <= r) {
                int mid = l + r >> 1;
                if (m - 1ll * mid * labs(b[a[i]] - b[a[i - 1]]) >= 0) res = mid, l = mid + 1;
                else r = mid - 1;
            }
            if (m - 1ll * res * labs(b[a[i]] - b[a[i - 1]]) >= 0) {
                m -= 1ll * res * labs(b[a[i]] - b[a[i - 1]]);
                ans = res + 1;
                Ans = max(Ans, ans);
                xx = i - 1 - res;
                // printf("%d ", ans);
            } else break;
        }
        // puts ("");
    }
    // printf ("ans: %d   m: %lld   res: %d   val: %lld\n", ans, m, res, b[a[res]]);
    return Ans;
}

inline i64 greedy3(i64 m) {
    int ans = 0, pos = 1;
    for (int i = 1; i <= n; ++ i) {
        if (ans < cnt[a[i]]) {
            ans = cnt[a[i]];
            pos = i;
        }
    }
    // printf ("%d %d\n", ans, pos);
    for (int i = pos - 1; i >= 1; -- i) {
        if (m - labs(b[a[pos]] - b[a[i]]) >= 0) {
            m -= labs(b[a[pos]] - b[a[i]]);
            ++ ans;
            // puts ("ssds");
            // printf ("%d %lld\n", ans, m);
        } else break;
    }
    // printf ("%d %lld\n", ans, m);
    if (m > 0) {
        for (int i = pos + cnt[a[pos]]; i <= n; ++ i) {
            if (m - (i - 1) * labs(b[a[i]] - b[a[i - 1]]) >= 0) {
                m -= (i - 1) * labs(b[a[i]] - b[a[i - 1]]);
                ++ ans;
            } else break;
        }
    }
    return ans;
}

#define filename "crystal"

int main () {
#ifdef filename
    freopen (filename ".in", "r", stdin);
    freopen (filename ".out", "w", stdout);
#endif
    scanf ("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++ i) scanf ("%lld", &a[i]), b[i] = a[i];
    sort (a + 1, a + n + 1);
    // for (int i = 1; i <= n; ++ i) printf ("%lld ", a[i]);
    // puts ("");
    sort (b + 1, b + n + 1);
    int len = unique (b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; ++ i) a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;
    for (int i = 1; i <= n; ++ i) ++ cnt[a[i]];
    printf ("%lld\n", max({greedy1(m), greedy2(m), greedy3(m)}));
    return 0;
}