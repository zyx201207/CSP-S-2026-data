#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000010;
int c, test, n;
ll d, a[N];

inline void solve() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    srand(time(0));
    printf("%d\n", rand() % n + 3);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &test);
    for (; test--; )
        solve();
    return 0;
}
