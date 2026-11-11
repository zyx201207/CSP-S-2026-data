#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
const ll MAXN=2e5;
ll n,m,ans=0;
ll a[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<ll>());
    for(ll i=n-1;i>=0;i--){
        ll cnt=LLONG_MAX;
        for(ll j=i;j>=i-m;j--){
            cnt=cnt&a[j];
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}