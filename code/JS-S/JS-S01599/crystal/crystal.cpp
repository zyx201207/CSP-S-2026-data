#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
const int N = 5e5 + 5;
ll a[N], s[N];
int n;
ll m;
inline bool check(int l, int r){
    const ll x = a[r] * (r - l + 1ll) - s[r] + s[l - 1];
    return m >= x;
}
int getPos(int p){
    int l = 1, r = p, res = p + 1;
    while(l <= r){
        const int mid = (l + r) >> 1;
        if(check(mid, p)) r = mid - 1, res = mid;
        else l = mid + 1;
    }
    return res;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d %lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    std::sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        const int p = getPos(i);
        ans = std::max(ans, i - p + 1);
    }
    printf("%d", ans);
    return 0;
}