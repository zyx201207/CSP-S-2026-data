#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=3e5+7;
int n,m,a[MAXN];
ll g[MAXN],sum,s[MAXN];
char f[MAXN],c[MAXN];
string ss;
pair<ll,ll> got(ll x){
    ll l=1,r=n;
    while(l<r){
        ll mid=(l+r)>>1;
        if(s[mid]<x)l=mid+1;
        else r=mid;
    }
    return make_pair(l,x-s[l-1]);
}
char read(ll x){
    return c[got(x).first];
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>m;
    for(ll i=1;i<=m;i++){
        cin>>a[i]>>f[i];
        if(f[i]==f[i-1])g[n]+=a[i];
        else g[++n]=a[i],c[n]=f[i];
    }
    for(ll i=1;i<=n;i++){
        sum+=g[i];
        s[i]=s[i-1]+g[i];
        
    }
    int ff=0;cout<<sum<<endl;
    // for(int i=1;i<=sum;i++){
    //     ll gg=got(i).first;
    //        // cout<<i<<endl;
    //     if(gg!=i){
    //         cout<<s[gg]-i<<endl;
    //     }
    // }
    ll l=(sum)>>1,r=sum-l+1;
    ll cnt=0;;
    ll L=got(l).first,R=got(r).first;
    if(c[L]!=c[R])cnt++;
    while(l>=1&&r<=sum){
        // cout<<l-s[L-1]+1<<' '<<s[R]-r<<' '<<cnt<<endl;
        //if(read(l)!=read(r))++cnt;
        ll d=max(min(l-s[L-1]+1,s[R]-r),1ll);
        l-=d;r+=d;
        ll L=got(l).first,R=got(r).first;
        if(c[L]!=c[R])cnt+=d;
        
    }if(cnt>0)cnt--;
    cout<<cnt;
    return 0;
}/*
aaaa bb ccc-cc bb a b cc


*/