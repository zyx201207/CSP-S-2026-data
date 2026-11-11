#include<bits/stdc++.h>
using namespace std;
#define ll long long
//void int bool vector priority_queue pair<ll int>
ll n,m,a[100010],ct[100010],ans = 1,mx = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    ct[0] = 0;
    for(ll i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(ll i = 1;i<=n;i++){
        ct[i] = ct[i-1]+a[i];
    }
    for(ll l = 1;l<=n;l++){

        ll r = l+mx-1,cnt = 0;
        while(r<n){
            r++;
            ll num = r-l+1;
            if(a[r]*num <= (ct[r] - ct[l-1])+m)cnt = num;
            else {
                ans = max(ans,cnt);
                mx = ans;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
