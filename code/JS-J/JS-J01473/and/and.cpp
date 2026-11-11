#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200002],n,m;
bool vis[200002]={false};
ll maxx=-0x3f3f3f3f,ans=-0x3f3f3f3f;
ll calc(){
    ll tot=0,nw=0;
    for(ll i=1;i<=n;++i){
        if(vis[i]==true){
            nw++;
            if(nw==1){
                tot=a[i];
            }
            else{
                tot=tot&a[i];
            }
        }
    }
    return tot;
}
void dfs(ll k){
    if(k==m){
        ll sum=calc();
        ans=max(ans,sum);
        return;
    }
    for(ll i=1;i<=n;++i){
        if(vis[i]==false){
            vis[i]=true;
            dfs(k+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        maxx=max(maxx,a[i]);
        if(i==1){
            ans=a[i];
        }
        ans=ans&a[i];
    }
    if(m==1){
        printf("%lld",maxx);
        return 0;
    }
    if(m==2){
        ll ans=-0x3f3f3f3f;
        for(ll i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll k=a[i]&a[j];
                ans=max(ans,k);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        printf("%lld",ans);
        return 0;
    }
    dfs(0);
    cout<<ans;
    return 0;
}
