#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define ll long long
const ll INF = 500005;
using namespace std;
ll n,m,a[INF],pre[INF],ans;
ll pluss(ll x){
    ll anss = m+1;
    for(ll i = x;i <= n;i++){
        ll data = a[i] * (x-1) -(pre[i-1] - pre[i-x]);
        anss = min(anss,data);
    }
    return anss;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;

    for(ll i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(ll i = 1;i <= n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    ll l = 1,r = n,mid;
    while(l <= r){
        mid = (l+r) >> 1;
        if(pluss(mid) == m){
            ans = mid;
            break;
        }
        else if(pluss(mid) < m){
            ans = mid;
            l = mid + 1;
        }
        else 
            r = mid - 1;
    }
    cout << ans;
    return 0;
}