#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll read(){
    ll x=0,f=1;char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-') f=-1;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f*x;
}
const ll N=510,M=2e4+10,INF=1e16;
ll c,n,m,d,q,k[N],sw[N];
struct node{
    ll to,nxt,w;
};
node E[M<<3];
ll tot,head[M<<3],cnt;
void addedge(ll u,ll v,ll val){
    E[++tot]={v,head[u],val};
    head[u]=tot;
}
struct point{
    ll id,dis;
};
bool operator < (point x1,point x2){
    return x1.dis>x2.dis;
} 
ll dis[M<<3],vis[M<<3];
ll Dij(ll tx,ll ty){
    for(int i=1;i<=cnt;i++) dis[i]=INF,vis[i]=0;
    dis[tx]=0;
    priority_queue<point> q;
    while(!q.empty()) q.pop();
    q.push({tx,0});
    while(!q.empty()){
        ll u=q.top().id;
        q.pop();
        for(int i=head[u];i;i=E[i].nxt){
            ll v=E[i].to,val=E[i].w;
            if(vis[v]) continue;
            dis[v]=dis[u]+val;
            vis[v]=1;
            q.push({v,dis[v]});
            if(v==ty) return dis[v];
        }
    }
    return INF;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    //1-m zhan ting
    for(int i=1;i<=m;i++) sw[i]=read();
    cnt=m;
    for(int i=1;i<=n;i++){
        k[i]=read();
        int a,t,prea=0;
        for(int j=1;j<=k[i];j++){
            a=read(),t=read();
            if(j!=1) addedge(cnt+j-1,cnt+j,0),addedge(cnt+j,cnt+j-1,0);
            addedge(cnt+j,a,t);addedge(a,cnt+j,t);
        }
        cnt+=k[i];
    }
    while(q--){
        ll x=read(),y=read(),ans;
        ans=Dij(x,y)+sw[x]+sw[y];
        printf("%lld\n",ans);
    }
    return 0;
}