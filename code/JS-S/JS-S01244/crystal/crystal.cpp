#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N(5e5 + 5);
int n, ans;
ll a[N], m, now;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    int l = 1;
    for(int i = 1; i <= n; i++){
        now += 1ll * (i - l) * (a[i] - a[i - 1]);
        while(now > m) now -= a[i] - a[l], l++;
        ans = max(ans, i - l + 1);
    }
    printf("%d", ans);
    return 0;
}
