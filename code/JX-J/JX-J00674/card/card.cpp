#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#define ll long long
#define CSP2026 using
#define plus_plus namespace std

CSP2026 plus_plus;
ll n,m,s[300005],a[500005],f[500005];
int check(ll x,ll cnt){
    ll b = -1;
    for(ll k = 1;k <= cnt;k++){
        if(f[k] == x){
            b= k;
            return b;
        }
    }
    return b;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(ll i = 1;i <= n;i++){
        ll cnt = 1;
        f[1] = a[i];
        for(ll j = i+1;j <= n;j++){
            ll res = check(a[j],cnt);
            if(res == -1){
                f[++cnt] = a[j];
            }
            else{
                cnt = res;
            }
        }
        for(ll j = 1;j <= cnt;j++){
            s[f[j]]++;
        }
    }
    for(ll i = 1;i <= m;i++)
        cout << s[i] << " ";
    return 0;
}
