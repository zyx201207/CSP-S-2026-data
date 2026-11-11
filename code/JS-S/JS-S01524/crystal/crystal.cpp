#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i = (a);i <= (b);i++)
#define rep(i,a,b) for(ll i = (a);i < (b);i++)
#define pb push_back

ll n,m;
ll ar[1000006];
ll p[1000006];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    repe(i,1,n){
        cin >> ar[i];
    }
    sort(ar+1,ar+1+n);
    repe(i,1,n) p[i] = p[i-1] + ar[i];
    ll ans = 0;
    repe(i,1,n){
        ll l = i,r = n;
        while(l <= r){
            ll mid = (r-l)/2+l;
            //cout << l << ' ' << r << ' ' << mid << '\n';
            if(ar[mid]*(mid-i+1) - (p[mid]-p[i-1]) <= m){
                l = mid+1;
                ans = max(ans,(mid-i+1));
            }else{
                r = mid-1;
            }
        }
    }
    cout << ans;
    return 0;
}