#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5e5 + 10;
typedef long long LL;

LL n, m;
LL a[N], s[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i ++ ) s[i] = a[i] + s[i - 1];

    int i = 1;
    while (i <= n && a[i] * (i - 1) - s[i - 1] <= m) i ++ ;

    printf("%d\n", i - 1);

    return 0;
}
