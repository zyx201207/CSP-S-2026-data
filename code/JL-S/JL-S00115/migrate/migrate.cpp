#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e7+10;
ll a[N]={}, cnt[N]={};
void func(ll d, ll n, ll stp, ll e){
    if(n==e) {cnt[stp]++; return ;}
    for(ll i=n+1; i<=e && a[i]-a[n]<=d; i++){
        func(d, i, stp+1, e);
    }
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ll c, t;
    cin>>c>>t;
    while(t--){
        ll n, d, ans=0;
        cin>>n>>d;
        if(d==1){cout<<0<<'\n'; continue;}
        for(ll i=1; i<=n; i++) cin>>a[i];
        for(int i=1; i<=n-3; i++){
            for(int j=i+3; j<=n; j++){
                memset(cnt, 0, sizeof cnt);
                func(d, i, 0, j);
                for(ll i=1; i<=n; i++){
                    if(cnt[i]==2) {ans++;}
                    if(cnt[i]) break;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
