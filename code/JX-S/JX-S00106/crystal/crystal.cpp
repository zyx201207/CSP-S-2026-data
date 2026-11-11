#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 500005;

int n;
LL m;
LL a[N], f[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + (i - 1) * (a[i] - a[i - 1]);

    int l = 1, r = n + 1, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (f[mid] <= m) l = mid;
        else r = mid - 1;
    }

    printf("%d", l);

    return 0;
}
