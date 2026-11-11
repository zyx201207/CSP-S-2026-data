#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=30;i>=0;i--){
        ll x=(1<<i),cnt=0;
        for(ll i=1;i<=n;i++){
            if((a[i]|x)==a[i])cnt++;
        }
        if(cnt>=m){
            for(ll i=1;i<=n;i++){
                if((a[i]|x)==a[i])a[i]-=x;
                else a[i]=0;
            }
            ans+=x;
        }
    }
    cout<<ans;
    return 0;
}
/*





*/
