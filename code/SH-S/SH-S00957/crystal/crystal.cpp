#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 500010;

int n;
LL m;
LL A[N], s[N];
int ans = 0;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%lld", &A[i]);
    sort(A + 1, A + 1 + n);

    for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + A[i];
    for (int i = 1, j = 1; i <= n; i ++ )
    {
        while (1ll * (i - j + 1) * A[i] - (s[i] - s[j - 1]) > m) j ++ ;
        ans = max(ans, i - j + 1);
    }

    printf("%d", ans);
    return 0;
}
