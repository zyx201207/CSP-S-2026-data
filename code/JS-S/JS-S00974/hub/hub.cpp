#include<bits/stdc++.h>
using namespace std;
vector<int> g[2001];
int vis[2001],dep[2001];
int n,k;
void dfs(int u,int f,int mx){
    dep[u]=dep[f]+1;
    vis[u]=1;
    if(dep[u]==mx+1) return;
    for(auto v:g[u]){
        if(v==f) continue;
        dfs(v,u,mx);
    }
}
int dfs2(int u,int f){
    dep[u]=dep[f]+1;
    vis[u]=1;
    int t2=dep[u];
    for(auto v:g[u]){
        if(v==f||vis[v]) continue;
        int t=dfs2(v,u);
        t2=max(t2,t);
    }
    return t2;
}
int erfen(int l,int r){
    if(l==r) return l;
    int mid=(l+r)>>1,res=0,flag=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) vis[j]=dep[j]=0;
        dfs(i,0,mid);
        int r1=0;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                r1=dfs2(j,0);
                break;
            }
        }
        int f2=1;
        for(int j=1;j<=n;j++) if(!vis[j]){
            f2=0;
            break;
        }
        if(r1-1<=mid&&f2){
            flag=1;
            break;
        }
    }
    if(flag) res=erfen(l,mid);
    else res=erfen(mid+1,r);
    return res;
}
int ju[2001],col[2001];
void dfsn(int u,int f){
    vis[u]=1;
    for(auto v:g[u]){
        if(v==f||!col[v]) continue;
        dfsn(v,u);
    }
}
void dfsn2(int u,int f){
    ju[u]=min(ju[f]+1,ju[u]);
    for(auto v:g[u]){
        if(v==f) continue;
        dfsn2(v,u);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){

        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(k==2){
            int ans=erfen(0,100000);
            cout<<ans<<"\n";
        }
        else{
            int ans=3000;
            for(int s=1;s<(1<<n);s++){
                for(int i=1;i<=n;i++) ju[i]=3000,vis[i]=col[i]=0;
                if(__builtin_popcount(s)!=k) continue;
                for(int i=1;i<=n;i++){
                    if(s&(1<<(i-1))){
                        col[i]=1;
                    }
                }
                int flag=1,ji=0;
                for(int i=1;i<=n;i++){
                    if(s&(1<<(i-1))&&!vis[i]){
                        ji++;
                        dfsn(i,0);
                    }
                }
                if(ji>2) continue;
                for(int i=1;i<=n;i++){
                    if(s&(1<<(i-1))){
                        dfsn2(i,0);
                    }
                }
                int res=0;
                for(int i=1;i<=n;i++) res=max(res,ju[i]);
                ans=min(ans,res-1);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
