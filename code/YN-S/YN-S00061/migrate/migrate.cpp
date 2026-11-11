#include<bits/stdc++.h>
using namespace std;
constexpr long long MAXN=2e6+1000,INF=0x3f3f3f3f3f3f3f3f;
struct node{
    long long nv,nw;
};
struct cmp{
    bool operator()(const node& a,const node& b){
        return a.nw>b.nw;
    }
};

long long c,t,n,d,ans;
long long isdp[MAXN],d_dis[MAXN],lsans[MAXN],d_cnt[MAXN];
bool vis[MAXN];

vector <long long> gph[MAXN];
priority_queue<node,vector<node>,cmp> pq;

void dijkstra(long long sn);

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    scanf("%lld %lld",&c,&t);
    for (int Roundi=0;Roundi<t;Roundi++){
        ans=0;
        scanf("%lld %lld",&n,&d);
        for (int i=1;i<=n;i++) scanf("%lld",&isdp[i]);
        for (int i=1;i<=n;i++) gph[i].clear();
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if (isdp[j]-isdp[i]<=d){
                    // if (Roundi==13) printf("Create Path | %d -> %d[%lld]\n",i,j,isdp[j]-isdp[i]);
                    gph[i].push_back(j);
                    gph[j].push_back(i);
                }
            }
        }
        for (int i=1;i<=n;i++) dijkstra(i);
        printf("%lld\n",ans);
    }
    return 0;
}

void dijkstra(long long sn){
    long long topn,top_w;
    memset(vis,0,sizeof(vis));
    memset(d_dis,0x3f,sizeof(d_dis));
    memset(lsans,0,sizeof(lsans));
    memset(d_cnt,0,sizeof(d_cnt));
    while (!pq.empty()) pq.pop();
    d_dis[sn]=0;
    pq.push(node{sn,0});
    while (!pq.empty()){
        topn=pq.top().nv;
        top_w=pq.top().nw;
        pq.pop();
        // printf("Same | %lld -> %lld[%lld,%lld,%lld]\n",sn,topn,d_dis[topn],d_cnt[topn],lsans[topn]);
        if (vis[topn]&&d_dis[topn]==top_w){
            d_cnt[topn]++;
            lsans[topn]=(d_cnt[topn]==2?1:0);
            // printf("Same | %lld -> %lld[%lld,%lld,%lld]\n",sn,topn,d_dis[topn],d_cnt[topn],lsans[topn]);
        }
        if (vis[topn]&&d_dis[topn]<top_w) continue;
        vis[topn]=1;
        d_cnt[topn]++;
        for (long long v:gph[topn]){
            if (d_dis[topn]+1<=d_dis[v]){
                d_dis[v]=d_dis[topn]+1;
                pq.push(node{v,d_dis[v]});
            }
        }
    }
    for (int i=sn+1;i<=n;i++){
        // if (lsans[i]!=0) printf("Same | %lld->%d[%lld]\n",sn,i,d_dis[i]);
        ans+=lsans[i];
    }
    return ;
}