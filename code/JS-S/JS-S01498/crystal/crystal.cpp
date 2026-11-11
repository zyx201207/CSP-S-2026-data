#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, a[500010], ans;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 1;i <= n;i++){
        ll x = 0;
        cin >> x;
        a[i] = x;
    }
    sort(a + 1, a + n + 1);
    ll l = 1;
    ll thisans = 0;
    ll x = m;
    for(ll i = 1;i <= n;i++){
        thisans++;
        x -= (i - l) * (a[i] - a[i - 1]);
        while(x < 0){
            x += a[i] - a[l];
            l++;
            thisans--;
        }
        ans = max(ans, thisans);
    }
    cout << ans;
    return 0;
}
//easy!
