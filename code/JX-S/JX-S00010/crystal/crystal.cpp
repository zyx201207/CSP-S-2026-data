#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll a[N];
    ll n,m;
    cin>>n>>m;
    a[0]=0,a[n+1]=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll ans=1;
    ll t=0,c=0,sum=n;
    for(ll i=n;i>1;i--){
        c++;
        t+=a[i-1];
        if(c*a[sum]-t<=m){
            ans=max(ans,c+1);
        }else{
            i=sum;
            sum--;
            t=0,c=0;
        }
    }
    cout<<ans;
    return 0;
}
