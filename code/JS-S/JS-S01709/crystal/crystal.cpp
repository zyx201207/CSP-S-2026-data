#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+8;
ll n,m,ans=-1;
ll a[N];
bool xz=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll delta=a[2]-a[1];
    for(ll i=3;i<=n;i++){
        if(a[i]-a[i-1]!=delta){
            xz=0;
        }
    }
    if(xz){
        for(ll i=2;;i++){
            ll s=i*(i-1)/2*delta;
            if(m<s){
                cout<<i-1;
                return 0;
            }
        }
    }
    for(ll i=n;i>=1;i--){
        ll tg=a[i],s=0,an=1;
        for(ll j=i-1;j>=1;j--){
            s+=a[i]-a[j];
            if(s>m)
                break;
            an++;
        }
        ans=max(ans,an);
    }
    cout<<ans;
    return 0;










}
