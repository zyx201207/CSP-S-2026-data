#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
ll f(ll x){
    ll ans=1;
    ll h=m;
    for(int i=x-1;i>=1;i--){
        if(h>=a[x]-a[i]&&a[i]<=a[x]){
            h-=(a[x]-a[i]);
            ans++;
        }
        else break;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+n+1);
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans=max(ans,f(i));
    }
    cout<<ans;
    return 0;
}
