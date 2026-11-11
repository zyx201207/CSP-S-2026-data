#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],n,m,b[500005],ans,d[500005];
bool check(ll mid){
    ll cnt=0;
    for(int i=mid;i<=n;i++){
        cnt=b[i]-b[i-mid+1]-(i-mid)*(a[i]-a[i-mid+1]);
        if(cnt<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
        b[i]=b[i-1]+d[i]*(i-1);
    }
    ll l=0,r=n;
    while(l<r){
        ll mid=l+r>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid;
        }
    }
    cout<<ans;
    return 0;
}
