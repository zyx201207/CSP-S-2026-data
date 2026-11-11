#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;

const int N = 2e6 + 10;
int c, T, n;
ll d, x[N];

template <class T>
void read(T &a) {
    a = 0;
    bool f = false;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = true;
        c = getchar();
    }
    while (c >= '0' && c <= '9') a = (a << 3) + (a << 1) + (c ^ 48), c = getchar();
    if (f) a = -a;
}

bool check(int s, int t) {
    std :: vector<int> r1, r2;
    int pos = s;

    r1.push_back(s);
    while (pos < t) {
        int p = 1;
        while (pos + p <= t && x[pos] + d >= x[pos + p]) p ++;
        if (p == 1) return false;
        pos = pos + p - 1;
        r1.push_back(pos);
    }
    pos = t;
    r2.push_back(t);
    while (pos > s) {
        int p = 1;
        while (pos - p >= s && x[pos] - d <= x[pos - p]) p ++;
        if (p == 1) return false;
        pos = pos - p + 1;
        r2.push_back(pos);
    }

    std :: reverse(r2.begin(), r2.end());
    bool flag = false;
    for (int i = 0; i < r1.size(); i ++) {
        if (r1[i] != r2[i]) {
            if (std :: abs(r1[i] - r2[i]) > 1 || flag) return false;
            flag = true;
        }
    }

    return flag;
}

int main() {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    read(c), read(T);
    while (T --) {
        ll res = 0;
        read(n), read(d);
        for (int i = 1; i <= n; i ++) read(x[i]);
        if (c == 11 || c == 12) {
            ll l = d / (x[2] - x[1]);
            printf("%lld\n", l <= 1 ? 0 : std :: max((ll)n - 2 * (l - 1LL) - 1LL, 0LL));
        } else {
            for (int l = 4; l <= n; l ++)
                for (int i = 1; i <= n - l + 1; i ++)
                    if (check(i, i + l - 1)) res ++;
            printf("%d\n", res);
        }
    }


    return 0;
}