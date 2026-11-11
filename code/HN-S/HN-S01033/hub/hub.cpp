#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+114;
int del[maxn];
int dep[maxn],fa[maxn];
vector<int> E[maxn];
array<int,2> dfs1(int u){
    array<int,2> res={dep[u],u};
    for(int v:E[u]){
        if(del[v]==1) continue;
        if(v!=fa[u]){
            fa[v]=u;
            dep[v]=dep[u]+1;
            res=max(res,dfs1(v));
        }
    }
    return res;
}
int R;
int cst;
int dfs2(int u,int lst){
    int res=0;
    for(int v:E[u]){
        if(del[v]==1) continue;
        if(v!=lst){
            res=max(res,dfs2(v,u)+1);
        }
    }
    if(res>=R||lst==0) cst++;
    return res;
}
int n,k;
bool chk1(int mid){
    R=mid;
    //一个连通块
    int a=1;
    fa[a]=0,dep[a]=0;
    int b=dfs1(a)[1];
    fa[b]=0,dep[b]=0;
    a=dfs1(b)[1];
    //a b 是直径端点
    int len=dep[a]/2;
    int rt=a;
    for(int i=1;i<=len;i++) rt=fa[rt];
    //直径中点 rt 必选
    cst=0;
    dfs2(rt,0);
    if(cst<=k) return true;
    else return false;
}
int getans1(){
    int l=-1,r=n;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(chk1(mid)==true) r=mid;
        else l=mid;
    }
    return r;
}
bool chk2(int mid,int u,int v){
    R=mid;
    //断开边 u,v
    del[u]=1;
    int a=v;
    fa[a]=dep[a]=0;
    int b=dfs1(a)[1];
    fa[b]=dep[b]=0;
    a=dfs1(b)[1];
    int len=dep[a]/2;
    int rt=a;
    for(int j=1;j<=len;j++) rt=fa[rt];
    cst=0;
    dfs2(rt,0);
    del[u]=0;
    del[v]=1;
    a=u;
    fa[a]=dep[a]=0;
    b=dfs1(a)[1];
    fa[b]=dep[b]=0;
    a=dfs1(b)[1];
    len=dep[a]/2;
    rt=a;
    for(int j=1;j<=len;j++) rt=fa[rt];
    dfs2(rt,0);
    del[v]=0;
    if(cst<=k) return true;
    else return false;
}
int getans2(int u,int v){
    int l=-1,r=n;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(chk2(mid,u,v)==true) r=mid;
        else l=mid;
    }
    return r;
}
mt19937 rd(114514);
int c;
void work(){
    cin>>n>>k;
    vector< array<int,2> > e;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e.push_back({u,v});
        E[u].push_back(v);
        E[v].push_back(u);
    }
    int ans=getans1();
    if(c>10){
        e.clear();
        int a=1;
        fa[a]=0,dep[a]=0;
        int b=dfs1(a)[1];
        fa[b]=0,dep[b]=0;
        a=dfs1(b)[1];
        //a b 是直径端点
        int len=dep[a];
        int x=a;
        for(int i=1;i<=len;i++){
            if(abs(i-(len/2))<=10){
                if(x!=0&&fa[x]!=0){
                    e.push_back({x,fa[x]});
                }
            }
            x=fa[x];
        }
    }
    shuffle(e.begin(),e.end(),rd);
    for(array<int,2> now:e){
        if(ans>0){
            if(chk2(ans-1,now[0],now[1])==true) ans=getans2(now[0],now[1]);
        }
    }        
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>c>>t;
    while(t--){
        work();
        for(int i=0;i<=n;i++) E[i].clear();
    }
    return 0;
}