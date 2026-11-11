#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=5e5+10;
const ll inf=1e12;
ll n,m,a[MAXN],b[MAXN],mx=-inf,Mn=inf,Mx=-inf,ans;
bool A=1;
bool check(int x){
    for(ll l=1;l+x-1<=n;l++){
        ll r=l+x-1,mid=(l+r)>>1;
        if((x*a[r]-b[r]+b[l-1])<=m) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];mx=max(mx,abs(a[i]));
        Mn=min(Mn,a[i]);Mx=max(Mx,a[i]);
        if(a[i]!=i) A=0;
    }
    // if(mx<=100){
    //     for(ll i=Mn;i<=Mx;i++){
    //         for(ll j=1;j<=n;j++) b[j]=abs(a[j]-i);
    //         sort(b+1,b+1+n);
    //         ll now=0,cnt=0;
    //         for(ll j=1;j<=n;j++){
    //             if(now+b[j]>m) break;
    //             now+=b[j];cnt++;
    //         }
    //         ans=max(ans,cnt);
    //     }
    //     cout<<ans<<"\n";
    //     //return 0;
    // }
    // if(A){
    //     int t=(-1+sqrt(1+4*m))/2,ans=2*t+1;
    //     if(ans>n) ans=n;
    //     else if(ans<n&&(t+1)*t+t+1<=m) ans++,t++;
    //     cout<<ans<<"\n";return 0;
    // }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    ll l=1,r=n;
    while(l<=r){
        ll mid=l+r>>1;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans<<"\n";
    return 0;
}