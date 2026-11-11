#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
ll n, m, a[N];
bool check(ll tk){
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] < tk)
            sum += tk - a[i];
        else
            break;
        if(sum > m)
            return false;
    }
    return sum <= m;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll l = a[1], r = a[n], mid, t = 0;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid))
            l = mid + 1, t = mid;
        else
            r = mid - 1;
    }
    ll ans = upper_bound(a + 1, a + n + 1, t) - a - 1;
    cout << ans << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}