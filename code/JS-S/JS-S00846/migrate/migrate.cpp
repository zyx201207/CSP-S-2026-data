#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>

using namespace std;

ll a[2000005];
ll f[2000005][2];
ll ans=0;
ll n,d;

pii getrg(ll p){
    ll lcl=max(a[p-1]+d+1,a[p]+1);
    ll lcr=a[p]+d;
    ll* pl=lower_bound(a,a+n+2,lcl);
    ll* pr=upper_bound(a,a+n+2,lcr)-1;
    return {pl-a,pr-a};
}

void solve(){

    cin>>n>>d;
    for(ll i=0;i<=n+3;i++){
        f[i][0]=f[i][1]=0;
    }
    ans=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=a[1]-d-1;
    a[n+1]=a[n]+d+1;
    for(ll i=n;i>=1;i--){
        pii pi=getrg(i);
        int nxt=pi.second;
        {pii pnx1,pnxt;
        if(a[nxt]<a[i-1]+d+1)continue;
        //f[i][0]=1;
        if(nxt>i+1){
            pnx1=getrg(nxt-1);
            ans+=pnx1.second-pnx1.first+1;
        }

        ans+=f[nxt][1];
        if(nxt>i+1){
            if(pnxt.second-pnxt.first+1==0&&pnx1.second-pnx1.first+1>0)
                ans+=f[pnx1.second][0]+1;//,ans+=f[pnx1.second][0];
        }}
        //cout<<i<<' '<<a[i]<<' '<<cur<<"---\n";
        //II
        {pii pnx1,pnxt;
        if(a[nxt]<a[i-1]+d+1)continue;
        //f[i][0]=1;
        if(nxt>i+1&&a[nxt-1]>=a[i-1]+d+1){
            pnx1=getrg(nxt-1);
            f[i][1]+=pnx1.second-pnx1.first+1;
        }
        if(nxt>i){
            pnxt=getrg(nxt);
            f[i][0]+=pnxt.second-pnxt.first+1;
        }
        f[i][1]+=f[nxt][1];
        f[i][0]+=f[nxt][0];
        if(nxt>i+1&&a[nxt-1]>=a[i-1]+d+1){
            if(pnxt.second-pnxt.first+1==0&&pnx1.second-pnx1.first+1>0)
                f[i][1]+=f[pnx1.second][0]+1;//,ans+=f[pnx1.second][0];
        }}
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<' '<<f[i][0]<<'-'<<f[i][1]<<"--\n";
    // }

    cout<<ans<<'\n';
    

}

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ll c,t;
    cin>>c>>t;
    while(t--)solve();

}