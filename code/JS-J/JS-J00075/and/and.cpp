#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[200005];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    long long ans = a[n];
    for (int i = k - 1; i >= 1; i--)
        ans = ans & a[n + i - k];
    printf("%lld\n", ans);
}
