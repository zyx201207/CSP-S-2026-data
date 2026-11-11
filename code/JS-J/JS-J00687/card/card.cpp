#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    ll a[n+10]={};
    ll b[n+10]={};
    ll u=1;
    ll cnt2[m+10]={};
    ll lp[m+10]={};
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll j=1;j<=n;j++){
        memset(cnt,0,sizeof(cnt));
        for(ll i=1;i<=n;i++){
            if(i<=j-1)continue;
            if(cnt[a[i]]==1){
                for(ll l=lp[a[i]];l<=i;l++){
                    cnt[b[l]]--;
                    b[l]=0;
                }
                u=lp[a[i]]+1;
                b[u]=a[i];
                lp[a[i]]=u;
                u++;
                cnt[a[i]]=1;

            }
            else{
                b[u]=a[i];
                u++;
                lp[a[i]]=u-1;
                cnt[a[i]]++;
            }
        }
        for(ll i=1;i<=m;i++){
            if(cnt[i])cnt2[i]++;
        }
        memset(b,0,sizeof(b));
        u=1;
        memset(lp,0,sizeof(lp));
    }
    for(ll i=1;i<=m;i++){
        cout<<cnt2[i];
        if(i!=n)cout<<" ";
    }
    return 0;
}
