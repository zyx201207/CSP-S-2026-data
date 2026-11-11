#include <bits/stdc++.h>
using namespace std;
vector<int>g[1000006];
int n,k,dep[1000006],fa[1000006],len;
int cnt[1000006],mxd[1000006];
int up[1000006],pnt[1000006],vis[1000006],rt;
int dn[1000006],son[1000006],sec[1000006],mn[1000006];
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    fa[u]=f;
    for(int v:g[u]){
        if(v==f)continue;
        dfs(v,u);
    }
}
void dfs2(int u,int f){
    dep[u]=dep[f]+1;
    pnt[dep[u]]=u;
    if(dep[u]>len){
        vis[pnt[dep[u]-len]]=1;
    }
    mxd[u]=0;
    for(int v:g[u]){
        if(v==f)continue;
        dfs2(v,u);
        mxd[u]=max(mxd[u],mxd[v]+1);
        if(mxd[u]==mxd[v]+1){
            son[u]=v;
        }
    }
    pnt[dep[u]]=0;
}
void dfs3(int u,int f){
    cnt[u]=vis[u];
    for(int v:g[u]){
        if(v==f)continue;
        dfs3(v,u);
        cnt[u]+=cnt[v];
    }
}
void dfs4(int u,int f,int MX){
    dep[u]=dep[f]+1;
    pnt[dep[u]]=u;
    int mx=0,se=0;
    up[u]=cnt[rt]-cnt[pnt[MX+1]];
    for(int v:g[u]){
        if(v==f)continue;
        if(mxd[v]+1>mx){
            se=mx;
            mx=mxd[v]+1;
        }else{
            se=max(se,mxd[v]+1);
        }
    }
    sec[u]=se;
    for(int v:g[u]){
        if(v==f)continue;
        int val=(mxd[v]+1==mx?se:mx);
        dfs4(v,u,max(MX,dep[u]-max(0,len-val)));
    }
    pnt[dep[u]]=0;
}
void dfs5(int u,int f){
    pnt[dep[u]]=u;
    mn[u]=dep[u];
    for(int v:g[u]){
        if(v==f||v==son[u]){
            continue;
        }
        dfs5(v,u);
    }
    for(int v:g[u]){
        if(v==f){
            continue;
        }
        if(v!=son[u]){
            continue;
        }
        dfs5(v,u);
        mn[u]=mn[v];
    }
    mn[u]=min(mn[u],dep[u]+max(0,len-sec[u]));
    dn[u]=cnt[pnt[mn[u]]];
}
int ask(int x){
    len=x;
    dfs(1,0);
    pair<int,int> mx={0,0};
    for(int i=1;i<=n;i++){
        mx=max(mx,{dep[i],i});
        vis[i]=0;
    }
    if(mx.first<=x+1){
        return 1;
    }
    rt=mx.second;
    for(int i=1;i<=x;i++){
        rt=fa[rt];
    }
    dfs2(rt,0);
    dfs3(rt,0);
    dfs4(rt,0,1);
    dfs5(rt,0);
    int mn=1e9;
    for(int i=1;i<=n;i++){
        dn[i]=max(dn[i],1);
        if(i!=rt){
            mn=min(mn,up[i]+dn[i]);
        }
    }
    return mn;
}
void solve(){
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
    if(k==n){
        cout<<0<<'\n';
        return ;
    }
    int L=1,R=n,ans=R;
    while(L<=R){
        int mid=L+R>>1;
        if(ask(mid)<=k){
            ans=mid;
            R=mid-1;
        }else{
            L=mid+1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}