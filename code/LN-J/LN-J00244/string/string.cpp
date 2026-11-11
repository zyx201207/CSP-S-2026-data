#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[200001];
char c[200001];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %c", &a[i], &c[i]);
    int l = 1, r = n, i = a[1], j = a[n];
    ll ans = 0;
    while (l < r)
        if (i == j) {
            if (c[l] != c[r])
                ans += i;
            ++l; --r;
            i = a[l], j = a[r];
        }
        else {
            if (i < j) {
                if (c[l] != c[r])
                    ans += i;
                j -= i;
                ++l; i = a[l];
            }
            else {
                if (c[l] != c[r])
                    ans += j;
                i -= j;
                --r; j = a[r];
            }
        }
    printf("%lld\n", ans);
    return 0;
}
