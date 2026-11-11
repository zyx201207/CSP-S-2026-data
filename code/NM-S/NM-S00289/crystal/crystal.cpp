#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<ll> c(n);
    c[0] = 0;
    for(ll i = 1;i<n;i++){
        c[i] = a[i]-a[i-1];
    }
    ll res = 0,l = m;
    for(ll i = 0;i<n;i++){
        l-=(i*c[i]);
        if(l<0)break;
        else{
            res++;
        }
    }
    cout << res;
    return 0;
}

