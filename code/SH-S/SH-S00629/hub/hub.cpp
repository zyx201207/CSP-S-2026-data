#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,k;
vector<ll> g[1000005];
ll dep[1000005];
ll pos=0,pos2=0;
ll vis[1000005];
ll now=0;
void dfs(ll u,ll fa){
    dep[u]=dep[fa]+1;
    for(auto v:g[u]){
        if(v!=fa){
            dfs(v,u);
        }
    }
}
ll sss=0;
void check(ll u,ll fa){
    if(vis[u]==1&&vis[fa]==0){
        sss++;
    }
    for(auto v:g[u]){
        if(v!=fa){
            check(v,u);
        }
    }
}
ll ans=0;
void dfs2(ll f,ll cnt){
    if(cnt==k){
        sss=0;
        check(1,0);
        if(sss>2)return;
        now=0;
        for(ll i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,0);
                ll tmp=1e18;
                for(ll j=1;j<=n;j++){
                    if(vis[j])tmp=min(tmp,dep[j]-1);
                }
                for(ll j=1;j<=n;j++)dep[j]=0;
                now=max(now,tmp);
            }   
        }
        ans=min(ans,now);
        return;
    }
    if(f==n+1)return;
    dfs2(f+1,cnt);
    vis[f]=1;
    dfs2(f+1,cnt+1);
    vis[f]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(ll i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=1e18;
        if(c>=6){
            cout<<1<<"\n";
            for(ll i=1;i<=n;i++){
                vis[i]=dep[i]=0;
                g[i].clear();
            }
            continue;
        }
        dfs2(1,0);
        cout<<ans<<"\n";
        for(ll i=1;i<=n;i++){
            vis[i]=dep[i]=0;
            g[i].clear();
        }
    }
}