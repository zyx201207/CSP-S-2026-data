#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct edge{
    int u,v,nxt;
}e[1000005];
int c,T,n,k,dep[500005],cnt[500005],dfn[500005],head[500005],st[25][500005],idx=0,pos=1;
bitset<500005> vis;
LL sum[500005];
int lowbit(int x){return (x&-x);}
void add_edge(int u,int v){
    e[++pos]={u,v,head[u]};
    head[u]=pos;
    return;
}
void dfs(int u,int fa=0){
    st[0][dfn[u]=++idx]=fa;
    for (int i=head[u];i;i=e[i].nxt){
        if (e[i].v==fa){continue;}
        dep[e[i].v]=dep[u]+1;
        dfs(e[i].v,u);
    }
    return;
}
void dfs1(int u,int fa=0){
    cnt[u]=1;sum[u]=dep[u];
    for (int i=head[u];i;i=e[i].nxt){
        if (e[i].v==fa){continue;}
        dep[e[i].v]=dep[u]+1;
        dfs(e[i].v,u);
        cnt[u]+=cnt[e[i].v];sum[u]+=sum[e[i].v];
    }
    return;
}
void dfs2(int u,int fa=0){
    for (int i=head[u];i;i=e[i].nxt){
        if (e[i].v==fa){continue;}
        sum[e[i].v]=sum[u]+cnt[u]-(cnt[e[i].v]<<1);
        dfs(e[i].v,u);
    }
    return;
}
int shushu(int u,int v){return ((dfn[u]<dfn[v])?(u):(v));}
int LCA(int u,int v){
    if (u==v){return u;}
    int l=min(dfn[u],dfn[v])+1,r=max(dfn[u],dfn[v]);
    return shushu(st[__lg(r-l+1)][l],st[__lg(r-l+1)][r-(1<<__lg(r-l+1))+1]);
}
void init(){
    for (int k=1;(1<<k)<=n;++k){
        for (int i=1;i<=n-(1<<k)+1;++i){
            st[k][i]=shushu(st[k-1][i],st[k-1][i+(1<<(k-1))]);
        }
    }
    return;
}
void justfillit(int u){
    vis[u]=0;
    for (int i=head[u];i;i=e[i].nxt){
        if (vis[e[i].v]){justfillit(e[i].v);}
    }
    return;
}
bool lian(int s){
    for (int i=1;i<=n;++i){vis[i]=0;}
    for (int i=s;i;i-=lowbit(i)){vis[__lg(lowbit(i))+1]=1;}
    for (int i=1,cnt=0;i<=n;++i){
        if (vis[i]){if (++cnt>2){return 1;}justfillit(i);}
    }
    return 0;
}
int justmodit(int s){
    int ans=0,tmp=0x3f3f3f3f;
    for (int i=1;i<=n;++i){
        if ((s>>(i-1))&1){continue;}
        tmp=0x3f3f3f3f;
        for (int j=s,o;j;j-=lowbit(j)){
            o=__lg(lowbit(j))+1;
            tmp=min(tmp,dep[i]+dep[o]-(dep[LCA(i,o)]<<1));
        }
        ans=max(ans,tmp);
    }
    return ans;
}
int k2(){
    int ans=0,u=1,v=1,tmp=0x3f3f3f3f;
    LL cursum=0,cursum2=0;
    dfs1(1);dfs2(1);cursum=cursum2=sum[1];
    for (int i=2;i<=n;++i){
        if (sum[i]<=cursum){cursum2=cursum;cursum=sum[i];v=u;u=i;}
        else if (sum[i]<=cursum2){cursum2=sum[i];v=i;}
    }
//cerr<<u<<" "<<v<<endl;
    for (int i=1;i<=n;++i){
        if (i==u||i==v){continue;}
        tmp=0x3f3f3f3f;
        vector<int> shushu;shushu.push_back(u);shushu.push_back(v);
        for (auto &&o : shushu){
            tmp=min(tmp,dep[i]+dep[o]-(dep[LCA(i,o)]<<1));
        }
        ans=max(ans,tmp);
    }
    return ans;
}
void solve(){
    scanf("%d%d",&n,&k);int ans=0x3f3f3f3f;
    for (int i=1;i<=n;++i){head[i]=0;}pos=1;idx=0;
    for (int i=1,u,v;i<n;++i){scanf("%d%d",&u,&v);add_edge(u,v);add_edge(v,u);}
    dfs(1);init();
    for (int i=1;i<(1<<n);++i){
        if (__builtin_popcount(i)!=k){continue;}
        if (lian(i)){continue;}
        ans=min(ans,justmodit(i));
    }
    printf("%d\n",ans);
    return;
}
void solve_k_2(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i){head[i]=0;}pos=1;idx=0;
    for (int i=1,u,v;i<n;++i){scanf("%d%d",&u,&v);add_edge(u,v);add_edge(v,u);}
    dfs(1);init();
    printf("%d\n",k2());
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    if (c==7||c==11||c==12){
        ++T;while (--T){solve_k_2();}
        return 0;
    }
    ++T;while (--T){solve();}
    return 0;
    //freopen("shushu.ans","r",stderr);
    //zhe'shi'yi'ge'yin(g)'cang'cai'dan
    //gong'xi
    //yin(g)'shi'qian'bi'yin'hai'shi'hou'bi'yin?????
}
//CSP-S 2026 RP++
//%%%candybar%%%
//%%%lzq%%%
//%%%lzy%%%
//%%%zxx%%%
