#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 5;
int n;
LL m;
LL a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int l = 1, ans = 1;
    for(int i = 2; i <= n; i++) {
        LL res;
        res = 1ll * (i - l) * (a[i] - a[i - 1]);
        m -= res;
        if(m < 0) {
            while(l < i && m + a[i] - a[l] < 0) m += a[i] - a[l++];
            m += a[i] - a[l++];
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d", ans);
    return 0;
}
