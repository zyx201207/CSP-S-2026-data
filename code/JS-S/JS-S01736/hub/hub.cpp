#include<bits/stdc++.h>
using namespace std;
const int N=1e2;
int c,t,k,u,v,n,head[N+6],dep[N+6],pos,fa[N+6],ans;
bool vs[N];
struct edg{
    int u,v,nxt;
}e[N*2+2];
int lowbit(int x){
    return x&-x;
}
void init(){
    pos=0;
    ans=INT_MAX;
    memset(head,-1,sizeof head);
    memset(fa,0,sizeof fa);
    memset(dep,0,sizeof dep);
}
void adg(int u,int v){
    e[pos]={u,v,head[u]};
    head[u]=pos++;
}
void bdt(int x,int f){
    dep[x]=dep[f]+1;
    fa[x]=f;
    for(int i=head[x];~i;i=e[i].nxt){
        if(e[i].v!=f){
            bdt(e[i].v,x);
        }
    }
}
void dfs(int x,int u){
    vs[u]=1;
    for(int i=head[u];~i;i=e[i].nxt){
        if((x&(1<<(e[i].v-1)))&&!vs[e[i].v]){
            dfs(x,e[i].v);
        }
    }
}
bool chk(int x){
    int cnt=0,t=x;
    for(;t;t-=lowbit(t)){
        ++cnt;
    }
    if(cnt!=k){
        return 0;
    }
    memset(vs,0,sizeof vs);
    cnt=0;
    for(int i=1;i<=n;++i){
        if((x&(1<<(i-1)))&&(!vs[i])){
            dfs(x,i);
            ++cnt;
        }
    }
    return cnt<=2;
}
int ds(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    int tu=u,tv=v;
    for(;dep[tu]>dep[tv];tu=fa[tu]);
    for(;tu!=tv;tu=fa[tu],tv=fa[tv]);
    return dep[u]+dep[v]-dep[tu]*2;
}
int l(int x){
    int res=0;
    for(int i=1;i<=n;++i){
        if((x&(1<<(i-1)))==0){
            int d=INT_MAX;
            for(int j=1;j<=n;++j){
                if(x&(1<<(j-1))){
                    d=min(d,ds(i,j));
                }
            }
            res=max(res,d);
        }
    }
    return res;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(;t--;){
        cin>>n>>k;
        init();
        for(int i=1;i<n;++i){
            cin>>u>>v;
            adg(u,v);
            adg(v,u);
        }
        bdt(1,0);
        for(int i=1;i<(1<<n);++i){
            if(chk(i)){
                ans=min(ans,l(i));
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
