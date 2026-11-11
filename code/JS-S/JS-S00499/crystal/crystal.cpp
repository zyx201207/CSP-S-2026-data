#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll m;
ll a[500010];

int main (){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int j = 1;
    ll sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        while(j <= i && 1LL * a[i] * (i - j + 1) - sum > m) {
            sum -= a[j];
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    printf("%d\n", ans);
}
