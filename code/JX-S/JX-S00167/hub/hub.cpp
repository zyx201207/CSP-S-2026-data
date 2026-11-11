#include<bits/stdc++.h>
#define CSP2026 using
#define RP namespace
#define PLUSPLUS std
CSP2026 RP PLUSPLUS;
using ll=long long;
using pii=pair<int,int>;
#define debug(x) cout<<"clock="<<clock()<<' '<<#x<<'='<<(x)<<'\n'
inline int rd(){int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
inline ll rdll(){ll x=0;int f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
constexpr int N=5e5+5;
struct edge{int to,nxt;}e[N<<1];
int h[N],ecnt=1,a1[N],a2[N],U[N],V[N],mx,amx,mxLYR[N],LYR[N],seq[N];
bitset<N>vis;
void addedge(int u,int v){
    e[++ecnt]={v,h[u]};
    h[u]=ecnt;
}void dfs1(int lyr,int u,int f,int ban){
    LYR[u]=mxLYR[u]=lyr;
    if(lyr>mx)mx=lyr,amx=u;
    for(int i=h[u];i;i=e[i].nxt){
        if(i==ban||i==(ban^1))continue;
        int v=e[i].to;
        if(v==f)continue;
        dfs1(lyr+1,v,u,ban);
        mxLYR[u]=max(mxLYR[u],mxLYR[v]);
    }
}int dfs2(int lyr,int u,int f,int ban,int goal){
    seq[lyr]=u;
    if(u==goal)return seq[(1+lyr)>>1];
    for(int i=h[u];i;i=e[i].nxt){
        if(i==ban||i==(ban^1))continue;
        int v=e[i].to;
        if(v==f)continue;
        int ret=dfs2(lyr+1,v,u,ban,goal);
        if(ret)return ret;
    }return 0;
}int t1,t2,t3;
void hxcs(int u,int ban,int *a,int k){
    // cout<<u<<','<<ban<<'\n';
    mx=0,amx=u;dfs1(0,u,0,ban);
    t1=amx;
    mx=0,amx=u;dfs1(0,t1,0,ban);
    t2=amx;
    // debug(t1),debug(t2);
    t3=dfs2(1,t1,0,ban,t2);
    // cout<<u<<','<<ban<<'\n';
    assert(t3);
    mx=amx=0;dfs1(0,t3,0,ban);
    // a[1]=mx;
    priority_queue<pii>pq;
    pq.emplace(mx,t3);
    vis.reset();vis[t3]=1;
    a[1]=mx;
    for(int t=1;t<=k;++t){
        int u=pq.top().second;
        // cout<<"t="<<t<<' '<<u<<'\n';
        pq.pop();
        vis[u]=1;
        for(int i=h[u];i;i=e[i].nxt){
            if(i==ban||i==(ban^1))continue;
            int v=e[i].to;
            if(!vis[v]){
                int nw=mxLYR[v]-LYR[v];
                pq.emplace(nw,v);
            }
        }
        if(pq.empty())break;
        // cout<<"t="<<t<<']'<<pq.top().second<<'\n';
        a[t]=pq.top().first+1;
    }
}void solve(){
    int n=rd(),k=rd();
    fill(h+1,h+n+1,0);ecnt=1;
    for(int i=1;i<n;++i)U[i]=rd(),V[i]=rd(),addedge(U[i],V[i]),addedge(V[i],U[i]);
    fill(a1+1,a1+n+1,0);
    hxcs(1,0,a1,k);
    // for(int i=1;i<=n;++i)cout<<a1[i]<<" \n"[i==n];
    int ans=a1[k];
    // debug(a1[k]);
    for(int i=1;i<n;++i){
        fill(a1+1,a1+n+1,0);
        fill(a2+1,a2+n+1,0);
        hxcs(U[i],i<<1,a1,k);
        hxcs(V[i],i<<1,a2,k);
        for(int i=1;i<=k-1;++i)ans=min(ans,max(a1[i],a2[k-i]));
        // cout<<i<<' '<<U[i]<<' '<<V[i]<<'\n';
        // for(int i=1;i<=n;++i)cout<<a1[i]<<" \n"[i==n];
        // for(int i=1;i<=n;++i)cout<<a2[i]<<" \n"[i==n];        
    }cout<<ans<<'\n';
    // for(int i=1;i<=k;++i)cout<<a1[i]<<'\n';
}int b1[N],b2[N];
void dfs3(int u,int f,int *a,int *b){
    a[u]=b[u]=0;
    int mx=0,mx2=0;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==f)continue;
        dfs3(v,u,a,b);
        a[u]=max(a[u],a[v]+1);
        b[u]=max(b[u],b[v]);
        if(a[v]+1>mx)mx2=mx,mx=a[v]+1;
        else mx2=max(mx2,a[v]+1);
    }b[u]=max(b[u],(mx+mx2+1)>>1);
}void solve2(){
    int n=rd(),k=rd();
    fill(h+1,h+n+1,0);ecnt=1;
    for(int i=1;i<n;++i)U[i]=rd(),V[i]=rd(),addedge(U[i],V[i]),addedge(V[i],U[i]);
    fill(a1+1,a1+n+1,0);
    fill(seq+1,seq+n+1,0);
    hxcs(1,0,a1,k);
    int ans=a1[k];
    if(k==2){
        // cout<<t1<<' '<<t2<<'\n';
        // for(int i=1;i<=n;++i)cout<<seq[i]<<" \n"[i==n];
        dfs3(t1,0,a1,b1);
        dfs3(t2,0,a2,b2);
        // for(int i=1;i<=n;++i)cout<<b1[i]<<" \n"[i==n];
        // for(int i=1;i<=n;++i)cout<<b2[i]<<" \n"[i==n];
        for(int i=1;i<n;++i)if(seq[i]&&seq[i+1]){
            ans=min(ans,max(b2[seq[i]],b1[seq[i+1]]));
        }
    }cout<<ans<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=rd();int T=rd();
    while(T--){
        if(c==11||c==12)solve2();
        else solve();
    }
}