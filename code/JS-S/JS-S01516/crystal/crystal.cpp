#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    bool f = true;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        if(i > 2) {
            ll d1 = a[i] - a[i - 1];
            ll d2 = a[2] - a[1];
            if(d1 != d2){
                f = false;
            }
        }
    }
    if(f){
        ll q = m * 1.0 / abs(a[2] - a[1]);
        ll t = sqrt(1 + 8 * q) / 2;
        ll x = t * (t - 1) / 2;
        while(x <= q){
            t ++;
            x = t * (t - 1) / 2;
        }
        cout << t - 1 << '\n';
        return 0;
    }
    sort(a+1,a+n+1);
    int r = 0;
    for(int i = 2;i <= n;i ++){
        ll sum = 0;
        int ans = 0;
        while(sum<=m && i - ans > 0){
            ans ++;
            sum += a[i] - a[i - ans];
        }
        r = max(r,ans);
    }
    cout << r << '\n';
    return 0;
}
