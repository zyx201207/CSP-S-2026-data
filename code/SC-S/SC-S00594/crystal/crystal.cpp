#include <cstdio>
#include <algorithm>
typedef long long ll;

const int N = 5e5 + 10;
int n;
ll a[N], s[N], m;

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

bool check(int mid) {
    for (int i = 1; i <= n - mid + 1; i ++)
        if (m >= (mid * a[i + mid - 1] - (s[i + mid - 1] - s[i - 1])))
            return true;
    return false;
}

int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    read(n), read(m);
    for (int i = 1; i <= n; i ++) read(a[i]);
    std :: sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];

    int l = 0, r = n;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    if (check(r - 1)) l = r;
    if (check(r)) l = r;

    printf("%d\n", l);

    return 0;
}