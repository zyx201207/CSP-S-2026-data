#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define ls p<<1
#define rs p<<1|1
#define rst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define ll long long
#define btp __builtin_popcount
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;

const int N(1e6+5);

int n,K,mxd[N],son[N],dfn[N],tot,d1[N],d2[N];
vector <int> G[N];

struct node{
    int x,y;
    void ins(int v){
        if(v>x) y=x,x=v;
        else if(v>y) y=v;
    }
    int calc(int v){
        if(x==v) return y;
        return x;
    }
}f1[N];

void dfs1(int u,int fa){
    f1[u]={0,0};
    mxd[u]=1;son[u]=0;
    for(int v:G[u]){
        if(v==fa) continue;
        dfs1(v,u);
        f1[u].ins(mxd[v]);
        if(mxd[v]>mxd[son[u]]){
            mxd[u]=mxd[v]+1;
            son[u]=v;
        }
    }
}

void dfs2(int u,int fa,int d){
    d1[u]=d;dfn[u]=++tot;
    if(son[u]){
        dfs2(son[u],u,max(d,f1[u].y)+1);
    }
    node A={0,0};
    for(int v:G[u]){
        if(v==fa||v==son[u]) continue;
        dfs2(v,u,max(d,f1[u].x)+1);
        A.ins(mxd[v]);
    }
    for(int v:G[u]){
        if(v==fa) continue;
        d2[v]=A.calc(mxd[v]);
    }
}

int lim,f[N],g[N],dp[N],mn;

void dfs3(int u,int fa){
    // if(mxd[u]<=lim) return ;
    f[u]=g[u]=1;
    if(son[u]){
        dfs3(son[u],u);
        if(mxd[son[u]]<=lim) f[u]=g[u]=1;
        else f[u]=f[son[u]]+1,g[u]=g[son[u]]+1;
        // cout<<u<<' '<<dp[dfn[u]+min(mxd[u]-1,lim*2+1)]<<' '<<dfn[u]+min(mxd[u]-1,lim*2+1)<<'\n';
        cmin(g[u],dp[dfn[u]+min(mxd[u]-1,lim*2+1)]+1);
    }
    // cout<<"!?!?!"<<u<<' '<<g[u]<<'\n';
    dp[dfn[u]]=inf;
    for(int v:G[u]){
        if(v==fa||v==son[u]) continue;
        // if(mxd[v]<=lim){
            // for(int i=0;i<mxd[v];i++) dp[dfn[u]+i+1]=inf;
            // continue;
        // }
        dfs3(v,u);
        if(mxd[v]>lim){
            g[u]+=f[v];
            for(int i=0;i<min(lim*2+1,mxd[v]);i++) cmin(g[u],f[u]+dp[dfn[v]+i]);
            f[u]+=f[v];            
        }
        int w=max(d2[v],d1[u]);
        if(w<lim){
            for(int i=0;i<min(lim*2,mxd[v]);i++){
                // if(i+w+1<=lim) cmin(mn,dp[dfn[v]+i]+dp[dfn[u]+mxd[u]-1]);
                // else cmin(mn,dp[dfn[v]+i]+dp[dfn[u]+mxd[u]-1]);
                if(i+w+1<=lim) cmin(mn,dp[dfn[v]+i]+dp[dfn[u]+min(lim*2,mxd[u]-1)]);
                else cmin(mn,dp[dfn[v]+i]+dp[dfn[u]+min({lim-w,lim*2-i,mxd[u]-1})]);
            }            
        }
        // for(int i=0;i<min(mxd[v],mxd[u]-1);i++) dp[dfn[u]+i+1]=inf;
        for(int i=0;i<min(mxd[v]*2,mxd[u]-1);i++) dp[dfn[u]+i+1]=f[u];
    }
    dp[dfn[u]]=f[u];
    if(d1[u]<=lim) cmin(mn,g[u]);
    // cout<<"-------------\n";
    // cout<<u<<' '<<f[u]<<' '<<g[u]<<' '<<mn<<'\n';
    // for(int i=0;i<mxd[u];i++) cout<<dp[dfn[u]+i]<<' ';
    // cout<<'\n';
    // cout<<"\n\n";
}

bool check(int _lim){
    lim=_lim;mn=inf;
    if(mxd[1]<=lim) return 1;
    rst(dp,0);rst(f,0);rst(g,0);
    // for(int i=1;i<=n;i++) dp[i]=1;
    // cout<<lim<<'\n';
    dfs3(1,0);
    // cout<<mn<<' '<<K<<'\n';
    return mn<=K;
}

void solve(){
    rst(mxd,0);rst(son,0);rst(dfn,0);rst(d1,0);rst(d2,0);tot=0;
    cin>>n>>K;
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    if(K>=n){
        cout<<"0\n";
        return ;
    }
    tot=0;
    dfs1(1,0);
    dfs2(1,0,0);
    // for(int i=1;i<=n;i++) cout<<d1[i]<<' '<<d2[i]<<'\n';
    int l=1,r=n,res=inf;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t;cin>>t>>t;
    while(t--) solve();

    
    return 0;
}