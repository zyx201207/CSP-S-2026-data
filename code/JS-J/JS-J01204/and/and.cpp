#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],cnt[35];
vector<ll>g[35];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,Max=0,ans=0;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++){
        ll b=0,c=a[i];
        while(a[i]>=(1<<b))b++;
        b--;
        Max=max(Max,b);
        while(b>=0){
            if(c>=(1<<b)){
                c=c-(1<<b);
                g[b].push_back(a[i]);
            }
            b--;
        }
    }
    for(ll i=Max;i>=0;i--){
        if(g[i].size()>=m){
            ans+=(1<<i);
            vector<ll>d;
            d=g[i];
            for(int j=0;j<=30;j++)g[j].clear();
            for(ll k:d){
                ll b=0,c=k;
                while(k>=(1<<b))b++;
                b--;
                while(b>=0){
                    if(c>=(1<<b)){
                        c=c-(1<<b);
                        g[b].push_back(k);
                    }
                    b--;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
