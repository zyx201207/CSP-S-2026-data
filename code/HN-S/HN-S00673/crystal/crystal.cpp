#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 9;

ll n, m, a[N], pre[N], ans;

bool check(ll x){
    for(int i = x; i <= n; i++){
        if(a[i] * x <= pre[i] - pre[i - x] + m){
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    ll l = 1, r = n;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        } else{
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
