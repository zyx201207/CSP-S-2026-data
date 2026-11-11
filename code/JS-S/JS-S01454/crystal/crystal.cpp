#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500050],ans=1,cur,cnt=1,l=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;++i){
        cur+=cnt*(a[i]-a[i-1]);
        while(cur>m){
            cur-=(a[i]-a[l]);
            --cnt;
            ++l;
        }
        ++cnt;
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
