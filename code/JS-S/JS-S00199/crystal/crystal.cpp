#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+5;
ll n, m, a[N], ans;
bool check(ll k){
    ll tmp = 0;
    for(int i = 1; i < k; i++) tmp += a[k] - a[i];
    for(int i = k; i <= n; i++){
        if(tmp <= m) return 1;
        tmp += (a[i + 1] - a[i]) * k - (a[i] - a[i - k + 1]);
    }
    return 0;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    ll l = 1, r = n;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    printf("%lld", ans);
    return 0;
}
