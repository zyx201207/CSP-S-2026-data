#include<bits/stdc++.h>
#define ll long long 
const int N=505;
const int M=20005;
const int Q=1e5+5;
int c,n,m,d,q;
ll w[M];
int k[N];
struct e{
    int to;
    int next;
    ll w;
}edge[M*2];
int head[M+N];
int cnt=0;
void add_edge(int u,int v,ll w){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    edge[cnt].w=w;
    head[u]=cnt;
}
struct node{
    ll v;
    int id;
    bool operator<(const node &x)const{
        return v>x.v;
    }
};
std::priority_queue<node> pq;
ll dis[M+N];
int vis[M+N];
ll ans[Q];
int tot;
void dijkstra(int s,int tim){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        node now=pq.top();
        pq.pop();
        if(vis[now.id]==tim){
            continue;
        }
        vis[now.id]=tim;
        for(int i=head[now.id];i;i=edge[i].next){
            int to=edge[i].to;
            if(dis[to]>dis[now.id]+edge[i].w){
                dis[to]=dis[now.id]+edge[i].w;
                pq.push({dis[to],to});
            }
        }
    }
}

struct que{
    int x,y,id;
    bool operator<(const que &w)const{
        return x<w.x;
    }
}qu[Q];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }

    for(int i=1;i<=n;i++){
       scanf("%d",&k[i]);
       for(int j=1,a;j<=k[i];j++){
           ll t;
           scanf("%d%lld",&a,&t);
           add_edge(i,n+a,t);
           add_edge(n+a,i,t);
       } 
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qu[i].x,&qu[i].y);
        qu[i].id=i;
    }
    std::sort(qu+1,qu+1+q);
    qu[0]={0,0,0};
    int index=1;

    while(index<=q){
        if(qu[index].x!=qu[index-1].x){
            dijkstra(n+qu[index].x,++tot);
            ans[qu[index].id]=dis[n+qu[index].y]+w[qu[index].x]+w[qu[index].y];
            while(qu[index].x==qu[index+1].x){
                index++;
                ans[qu[index].id]=dis[n+qu[index].y]+w[qu[index].x]+w[qu[index].y];
            }
            index++;
        }
    }
    for(int i=1;i<=q;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}