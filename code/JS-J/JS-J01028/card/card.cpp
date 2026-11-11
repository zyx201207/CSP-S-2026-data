#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll a[n+1];
    ll ans[m+1];
    ll desk[n+1];
    ll ar=0;
    memset(ans,0,sizeof(ans));
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll g=1;g<=n;g++){
        for(ll i=g;i<=n;i++){
            bool f=false;
            ll x;
            for(ll j=1;j<=ar;j++){
                if(desk[j]==a[i]){
                    x=j;
                    f=true;
                    break;
                }
            }
            if(f==false){
                ar++;
                desk[ar]=a[i];
            }
            else{
                for(ll j=x;j<=ar;j++){
                    desk[j]=0;
                    ar=x;
                    desk[ar]=a[i];
                }
            }
        }
        for(ll i=1;i<=ar;i++){
            ans[desk[i]]++;
            desk[i]=0;
        }
        ar=0;
    }
    for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
