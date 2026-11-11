#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
ll n,m;
ll a[(ll)5e5+5];ll s[(ll)5e5+5];ll b[(ll)5e5+5];
// bool check(ll x){
//     ll num=a[x]*x-s[x];
//     return (m<=num);
// }
// ll tt[255];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
// ll a[9]={0};ll s[9]={0};
    cin>>n>>m;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll la=0;
    ll lai=0;
    for(ll i=n;i>=1;--i){
        if(i==n){
            la=a[i];
            b[i]=i;
            lai=i;
        }else{
            if(la==a[i]){
                b[i]=lai;
            }else{
                b[i]=i;
                lai=i;
                la=a[i];
            }
        }
    }
    for(ll i=1;i<=n;++i){
        s[i]=s[i-1]+a[i];
    }
    ll cf=0;
    ll laa=0;
    ll mcf=0;
    for(ll i=1;i<=n;++i){
        if(a[i]==laa){
            cf++;
        }else{
            laa=a[i];
            mcf=max(cf,mcf);
            cf=1;

        }
    }
    ll l=0,r=n;
    ll ans=mcf;
    // for(ll i=1;i<=n;++i){
    //     tt[a[i]+100]++;
    // }
    // for(ll i=0;i<=199;++i){
    //     cout<<i-100<<":"<<tt[i]<<"\n";
    // }
    // ll lll=0;
    // for(ll i=1;i<=n;++i){
    //     cout<<a[i]<<":"<<(ll)a[i]*(ll)b[i]-(ll)s[b[i]]<<"\n";
    // }
    // for(ll i=1;i<=n;++i){
    //     cout<<b[i]<<" ";
    // }

    while(l<r){
        ll mi=(l+r+1)/2;
        if((ll)a[mi]*(ll)b[mi]-(ll)s[b[mi]]<=(ll)m){
            ans=mi;
            l=mi;
        }else{
            r=mi-1;
        }
    }
    cout<<ans<<"\n";
    //cout<<(ll)m-((ll)a[ans]*(ll)b[ans]-(ll)s[b[ans]]);
    return 0;
}