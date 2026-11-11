#include<bits/stdc++.h>
using lli=long long;
using namespace std;
const int N=500005;
int n;
int c,t;
vector<int> g[N];
bool vis[N];
void dfs(int u,int x){
    vis[u]=1;
    for(int v:g[u]){
        if(vis[v]||!(x&1<<(v-1)))continue;
        dfs(v,x);
    }
}
int dep[N];
void dft(int u,int fa){
    //cout<<"dft:"<<u<<"\n";
    for(int v:g[u]){
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dft(v,u);
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=0x3f3f3f3f;
    for(int x=0;x<1<<n;x++){
        vector<int> sd;
        for(int i=1;i<=n;i++){
            if(x&1<<(i-1)){
                sd.push_back(i);
                vis[i]=0;
            }
        }
        if(sd.size()!=k)continue;
        //cout<<"here\n";
        dfs(sd[0],x);
        for(int v:sd){
            if(!vis[v]){
                dfs(v,x);
                break;
            }
        }
        int lts=1;
        for(int v:sd){
            if(!vis[v]){
                lts=0;
                break;
            }
        }
        if(!lts)continue;
        //cout<<"here?\n";
        int res=0;
        for(int i=1;i<=n;i++){
            int ret=0x3f3f3f3f;
            dep[i]=0;
            dft(i,0);
            for(int u:sd){
                ret=min(ret,dep[u]);
            }
            res=max(res,ret);
            //cout<<x<<" "<<i<<" "<<ret<<"\n";
        }
        ans=min(ans,res);
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
