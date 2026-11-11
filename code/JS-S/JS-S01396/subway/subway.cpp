#include<bits/stdc++.h>
using namespace std;
#define ll long long 
inline int re(){
    int a=0,s=1;char d=getchar_unlocked();
    while(!isdigit(d)){
        if(d=='-') s=-1;
        d=getchar_unlocked();
    }
    while(isdigit(d)){
        a=(a<<3)+(a<<1)+d-48;
        d=getchar_unlocked();
    }
    return a*s;
}
//bianhao,zhanshu,xianshu,meiyong,question
int     c,  a,        s,  d,f ,   q,n,cnt,x[500001],hd[1010100];
ll ans,dis[1000001];
bool vis[1000001];
struct Edge
{
    int f,t,v,nxt;
}e[500001];

void dfs(int r,int p){
    int o=hd[p];
    while(e[o].nxt){
        if(dis[e[o].t]==0&&e[o].t!=r) {dis[e[o].t]=e[o].v+dis[p];dfs(r,e[o].t);}
        if(dis[e[o].t]>e[o].v+dis[p]){dis[e[o].t]=e[o].v+dis[p];dfs(r,e[o].t);}
        o=e[o].nxt;
    }
    if(e[o].f){
        if(dis[e[o].t]==0&&e[o].t!=r) {dis[e[o].t]=e[o].v+dis[p];dfs(r,e[o].t);}
        if(dis[e[o].t]>e[o].v+dis[p]){dis[e[o].t]=e[o].v+dis[p];dfs(r,e[o].t);}
    }
    return;
}

void zdl(int r,int t){
    dis[r]=0;
    for(int i=1;i<=a;i++){
        dis[i]=vis[i]=vis[i+500000]=0;
    }
    dfs(r,r);
    printf("%lld\n",dis[t]+x[r]+x[t]);
    return;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=re(),s=re(),a=re(),d=re(),q=re();
    for(int i=1;i<=a;i++) x[i]=re();
    for(int i=1;i<=s;i++){
        n=re();
        for(int j=1;j<=n;j++){
            d=re(),f=re();
            cnt++;
            e[cnt].f=d;
            e[cnt].t=500000+i;
            e[cnt].v=f;
            e[cnt].nxt=hd[d];
            hd[d]=cnt;
            cnt++;
            e[cnt].f=500000+i;
            e[cnt].t=d;
            e[cnt].v=f;
            e[cnt].nxt=hd[500000+i];
            hd[500000+i]=cnt;
        }
    }
    // for(int i=1;i<=cnt;i++){
    //     printf("%d %d %d\n",e[i].f,e[i].t,e[i].v);
    // }
    for(int T=1;T<=q;T++){
        zdl(re(),re());
    }
    return 0;
}