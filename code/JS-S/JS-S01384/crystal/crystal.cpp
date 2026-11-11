#include<bits/stdc++.h>
using  namespace std;
#define ll long long
ll a[500005];
ll b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++){
        b[i]=abs(a[i]-a[i-1]);
    }
    ll ans=1;
    for(ll i=2;i<=n;i++){
        if(m>=b[i]){
            m-=b[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
