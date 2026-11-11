#include<bits/stdc++.h>
using namespace std;
constexpr long long MAX_N=510,MAX_M=5e5+1000,INF=0x3f3f3f3f3f3f3f3f;
struct edg{
    long long nv,nw;
};
struct ls_info{
    long long lid,lte;
};
struct node{
    long long ndv,ndw;
};
struct cmp{
    bool operator()(const node& a,const node& b){
        return a.ndw>b.ndw;
    }
};

long long c,n,m,d,q,xr,yr,ans;
long long tkc,ihw,iit;
long long e2hw[MAX_M];
long long d_dis[MAX_N][MAX_N];
bool vis[MAX_N];

vector <edg> gph[MAX_N];
vector <ls_info> hw2ls[MAX_M]; // <line_id,time>
priority_queue<node,vector<node>,cmp> pq;

void dijkstra(long long sn);

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(d_dis,0x3f,sizeof(d_dis));

    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for (int i=1;i<=m;i++) scanf("%lld",&e2hw[i]);
    for (int i=1;i<=n;i++){
        scanf("%lld",&tkc);
        for (int j=1;j<=tkc;j++){
            scanf("%lld %lld",&ihw,&iit);
            hw2ls[ihw].push_back(ls_info{(long long)i,iit});
        }
    }

    for (int i=1;i<=m;i++){
        for (int j=0;j<hw2ls[i].size();j++){
            for (int k=j+1;k<hw2ls[i].size();k++){
                // printf("DEBUG | %lld %lld\n",hw2ls[i][j].lid,hw2ls[i][k].lid);
                if (d_dis[hw2ls[i][j].lid][hw2ls[i][k].lid]==INF){
                    gph[hw2ls[i][j].lid].push_back(edg{hw2ls[i][k].lid,hw2ls[i][j].lte+hw2ls[i][k].lte});
                    gph[hw2ls[i][k].lid].push_back(edg{hw2ls[i][j].lid,hw2ls[i][j].lte+hw2ls[i][k].lte});
                }
                d_dis[hw2ls[i][j].lid][hw2ls[i][k].lid]=min(d_dis[hw2ls[i][j].lid][hw2ls[i][k].lid],hw2ls[i][j].lte+hw2ls[i][k].lte);
                d_dis[hw2ls[i][k].lid][hw2ls[i][j].lid]=min(d_dis[hw2ls[i][k].lid][hw2ls[i][j].lid],hw2ls[i][j].lte+hw2ls[i][k].lte);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<gph[i].size();j++){
            gph[i][j].nw=d_dis[i][gph[i][j].nv];
            // printf("DEBUG | %d %lld -> %lld\n",i,gph[i][j].nv,gph[i][j].nw);
        }
    }

    memset(d_dis,0x3f,sizeof(d_dis));

    for (int i=1;i<=n;i++) dijkstra(i);

    for (int i=1;i<=q;i++){
        ans=INF;
        scanf("%lld %lld",&xr,&yr);
        // printf("FIND | %ld %ld\n",hw2ls[xr].size(),hw2ls[yr].size());
        for (int j=0;j<hw2ls[xr].size();j++){
            for (int k=0;k<hw2ls[yr].size();k++){
                // printf("DEBUG | %lld<->%lld\n",hw2ls[xr][j].lid,hw2ls[yr][k].lid);
                ans=min(ans,e2hw[xr]+e2hw[yr]+d_dis[hw2ls[xr][j].lid][hw2ls[yr][k].lid]+hw2ls[xr][j].lte+hw2ls[yr][k].lte);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

void dijkstra(long long sn){
    long long topn;
    memset(vis,0,sizeof(vis));
    while (!pq.empty()) pq.pop();
    d_dis[sn][sn]=0;
    pq.push(node{sn,0});
    while (!pq.empty()){
        topn=pq.top().ndv;
        pq.pop();
        if (vis[topn]) continue;
        vis[topn]=1;
        // printf("Sure | %lld<->%lld %lld\n",sn,topn,d_dis[sn][topn]);
        for (edg e:gph[topn]){
            if (d_dis[sn][topn]+e.nw<d_dis[sn][e.nv]){
                d_dis[sn][e.nv]=d_dis[sn][topn]+e.nw;
                pq.push(node{e.nv,d_dis[sn][e.nv]});
            }
        }
    }
    return ;
}