#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T,n,k,vis[1005],in[1005],dis[1005][1005],res=1e18;
vector<ll>e[1005],f;
void cd(ll u){
    vis[u]=1;
    for(auto i:e[u])
        if(in[i]&&!vis[i])
            cd(i);
}
void floyd(){
    memset(dis,0x3f,sizeof(dis));
    for(ll i=1;i<=n;i++){
        dis[i][i]=0;
        for(auto j:e[i])
            dis[i][j]=dis[j][i]=min(dis[i][j],1ll);
    }
    for(ll k2=1;k2<=n;k2++)
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k2]+dis[k2][j]);
}
void check(){
    ll cnt=0;
    for(ll i=1;i<=n;i++)
        vis[i]=0;
    for(auto i:f){
        if(!vis[i]){
            cnt++;
            if(cnt>2)
                return;
            cd(i);
        }
    }
    ll mx=-1;
    for(ll i=1;i<=n;i++){
        ll mn=1e18;
        for(auto j:f)
            mn=min(mn,dis[i][j]);
        mx=max(mx,mn);
    }
    res=min(res,mx);
    /*for(auto i:f)
        cout<<i<<" ";
    cout<<"ok!\n";
    cout<<mx<<"\n";*/
}
void dfs(ll u,ll cnt){
    if(cnt==k){
        check();
        return;
    }
    if(u==n+1)
        return;
    dfs(u+1,cnt);
    in[u]=1;
    f.push_back(u);
    dfs(u+1,cnt+1);
    f.pop_back();
    in[u]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        res=1e18;
        cin>>n>>k;
        for(ll i=1;i<=n;i++)
            e[i].clear();
        for(ll i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        floyd();
        dfs(1,0);
        cout<<res<<"\n";
    }
    return 0;
}
