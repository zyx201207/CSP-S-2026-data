#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans;
bool check(ll x){
    if(x==1)return 1;
    for(ll i=1;i<=n-x+1;i++){
        ll temp=0;ll t=x/2;
        for(ll j=0;j<t;++j){
            temp+=a[i-j+x-1]-a[i+j];
        }
        if(temp<=m)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=1,r=n;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
