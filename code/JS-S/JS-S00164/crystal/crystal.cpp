#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll l=1,r=1;
    ll nowuse=0;
    ll ans=0;
    while(l<=n){
        if(nowuse+(r-l+1)*(a[r+1]-a[r])<=m&&r<n){
            r++;
            nowuse+=(r-l)*(a[r]-a[r-1]);
        }else if(l<r){
            l++;
            nowuse-=a[r]-a[l-1];
        }else{
            l++;
            r++;
        }
        //cout<<l<<' '<<r<<' '<<nowuse<<endl;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
//why there isnt seat E in a train???-15pts

//cspjs_2026 while(true)rp+=LLONG_MAX;
//
//
//14:29 think about T1
//14:50 T1 WA
//15:11 T1 finish!!!
//15:12 start T2
//16:07 failed.. the only way is to try the special points
//17:41 there is still time... its never the end...
//17:49 wtf only 40min left and they finally say that there are mistakes in the pdf???
//18:21 here is the end of the trip.
