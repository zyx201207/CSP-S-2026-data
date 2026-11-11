#include <bits/stdc++.h>
#define eputs(str) fputs(str"\n",stderr)
#define dbgo stderr 
using namespace std;
#define ll long long
using pr=pair<ll,int>;
const int MAXN=510,MAXM=5e5+10;
ll w[MAXM];
int k[MAXN];
struct Edge{
    int to,nxt;
    ll val;
}es[(MAXM<<1)+(MAXN<<1)];
int head[MAXM+MAXN],cnte;
void add_edge(int u,int v,ll w){
    es[++cnte]={v,head[u],w};
    head[u]=cnte;
}
int di,m,n,op,q;
ll dis[MAXN][MAXM+MAXN];
priority_queue<pr>pq;
void dijkstra(int s){
    pq.push({0,s});
    dis[s][s]=0;
    for (;pq.size();){
        ll cdis=pq.top().first,cur=pq.top().second;
        pq.pop();
        for (int i=head[cur];i;i=es[i].nxt){
            int to=es[i].to,val=es[i].val;
            if (dis[s][cur]+val<dis[s][to]){
                dis[s][to]=dis[s][cur]+val;
                pq.push({dis[s][cur]+val,to});
            }
        }
    }
}

void solve(){
    
    scanf("%d%d%d%d%d",&op,&n,&m,&di,&q);
    for (int i=1;i<=m;++i){
        scanf("%lld",&w[i]);
    }

    for (int i=1,ks;i<=n;++i){
        scanf("%d",&ks);
        k[i]=ks;
        for (int j=1;j<=ks;++j){
            int a;
            ll t;
            scanf("%d%lld",&a,&t);
            add_edge(n+a,i,t);
            add_edge(i,n+a,t);
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n+m;++j){
            memset(&dis[i][j],0x3f,sizeof(ll));
        }
    }
    for (int s=1;s<=n;++s){
        dijkstra(s);
    }
    /*for (int i=1;i<=n;++i){
        fprintf(stderr,"%d:\n  ",i);
        for (int j=1;j<=n+m;++j){
            fprintf(stderr,"%lld ",dis[i][j]);
        }
        fputc('\n',stderr);
    }*/
    for (int i=1,x,y;i<=q;++i){
        scanf("%d%d",&x,&y);
        ll ans=0x3f3f3f3f3f3f3f3f;
        for (int j=head[n+x];j;j=es[j].nxt){
            ans=min(ans,w[x]+es[j].val+dis[es[j].to][n+y]+w[y]);
        }
        printf("%lld\n",ans);
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int t=1;
    for (int _=1;_<=t;++_){
        solve();
    }
    fflush(NULL);
    return 0;
}