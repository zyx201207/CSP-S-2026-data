#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 5e5 + 5;

int n;
LL m;
LL val[N];
LL pre[N];

bool check(int tot) {
    for (int i = tot; i <= n; i ++ ) {
        LL cost = val[i] * tot - (pre[i] - pre[i - tot]);

        if (cost <= m)
            return true;
    }

    return false;
}

void inp() {
    scanf("%d%lld", &n, &m);

    for (int i = 1; i <= n; i ++ )
        scanf("%lld", &val[i]);
}

void work() {
    sort(val + 1, val + n + 1);
    int l = 1, r = n;

    for (int i = 1; i <= n; i ++ )
        pre[i] = pre[i - 1] + val[i];

    while (l < r) {
        int mid = l + r + 1 >> 1;

        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    printf("%d\n", l);
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
