#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
const int N=1e6+5;
int n,k,tid;
vector<int> e[N];

namespace spec{
    const int inf=1e9;
    int h[N],g[N];
    int fl[N],gl[N],ans;
    void dfs1(int u,int fa){
        h[u]=g[u]=fl[u]=gl[u]=0;
        int mx=0,cmx=0;
        for(auto v:e[u])
            if(v^fa){
                dfs1(v,u);
                fl[u]=max(fl[u],fl[v]);
                h[v]+1>mx?cmx=mx,mx=h[v]+1:cmx=max(cmx,h[v]+1);
            }
        fl[u]=max(fl[u],mx+cmx),h[u]=mx;
    }
    struct node{ int mx,cmx; }info[N];
    void dfs2(int u,int fa){
        // db("%d:h %d,g %d,fl %d,gl %d\n",u,h[u],g[u],fl[u],gl[u]);
        int mx=g[u],cmx=0,pre=gl[u];
        for(auto v:e[u])
            if(v^fa){
                info[v]={mx,cmx};
                h[v]+1>mx?cmx=mx,mx=h[v]+1:cmx=max(cmx,h[v]+1);
                gl[v]=pre;
                pre=max(pre,fl[v]);
            }
        mx=cmx=pre=0;
        for(int i=(int)e[u].size()-1;i>=0;--i){
            int v=e[u][i];
            if(v==fa) continue;
            // db("%d:%d %d %d %d\n",v,info[v].mx,info[v].cmx,mx,cmx);
            g[v]=max(info[v].mx,mx)+1;
            gl[v]=max(gl[v],pre);
            gl[v]=max(gl[v],max(info[v].mx+info[v].cmx,max(mx+cmx,info[v].mx+mx)));

            int d=max(fl[v],gl[v]);
            ans=min(ans,(d+1)>>1);
            // db("%d to %d:%d  %d %d\n",u,v,d,fl[v],gl[v]);
            gl[v]=max(gl[v],g[v]);

            pre=max(pre,fl[v]);


            h[v]+1>mx?cmx=mx,mx=h[v]+1:cmx=max(cmx,h[v]+1);
        }
        for(auto v:e[u]) if(v^fa) dfs2(v,u);
    }
    void slv(){
        ans=n+1;
        dfs1(1,0),dfs2(1,0);
        printf("%d\n",ans);
    }
}

int h[N],g[N];
void dfs(int u,int fa){
    h[u]=0,g[u]=0;
    for(auto v:e[u]) if(v^fa) dfs(v,u),h[u]=max(h[u],h[v]+1);
}
int MX,rt;
void dfs2(int u,int fa){
    int mx=g[u];
    for(auto v:e[u])
        if(v^fa) g[v]=mx+1,mx=max(mx,h[v]+1);
    mx=0;
    for(int i=(int)e[u].size()-1;i>=0;--i){
        int v=e[u][i];
        if(v^fa) g[v]=max(g[v],mx+1),mx=max(mx,h[v]+1);
    }
    for(auto v:e[u]) if(v^fa) dfs2(v,u);
    int w=max(h[u],g[u]);
    if(w<MX) MX=w,rt=u;
}
int del,s[N];
void dfs3(int u,int fa){
    h[u]=0;
    for(auto v:e[u]) if((v^fa)&&(v^del)) dfs3(v,u),h[u]=max(h[u],h[v]+1);
    ++s[h[u]];
}
namespace spec2{
    void slv(){
        if(n==k){
            printf("%d\n",0);
            return ;
        }
        int l=(n-1)>>1;
        if(k>=l){
            printf("1\n");
            return ;
        }
        int x=l>>1,y=l-x,ans=n+1;
        x+=2,y+=2;
        for(int a=1;a<=k&&a<=x;++a){
            ans=min(ans,max((x-a+1)>>1,(y-(k-a)+1)>>1));
        }
        printf("%d\n",ans);
    }
}
void slv(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) e[i].clear();
    for(int i=1,u,v;i<n;++i) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    if(k==2){
        spec::slv();
        return ;
    }
    if(tid==13||tid==14){
        spec2::slv();
        return ;
    }
    int ans=n+1;
    for(int u=1;u<=n;++u) for(auto v:e[u]) if(u<v){
        del=v,MX=n+1,dfs(u,v),dfs2(u,v),dfs3(rt,0);
        ++s[n],--s[h[rt]];
        del=u,MX=n+1,dfs(v,u),dfs2(v,u),dfs3(rt,0);
        ++s[n],--s[h[rt]];
        for(int i=n;i>=0;--i) s[i]+=s[i+1],s[i]<=k?ans=min(ans,i):0;
        memset(s,0,(n+1)*sizeof(int));
    }
    printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int T;
    cin>>tid>>T;
    while(T--) slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}