#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct cone{
    int to;
    ll w;
};
struct edge{
    int v;
    ll w;
};
struct point{
    int p;
    ll D;
};
bool operator< (point a,point b){
    return a.D>b.D;
}
int c,n,m,d,q;
ll cost[500005],ans[505][505];
bool vis[505];
priority_queue<point> Q;
vector<cone> sta[500005];
vector<edge> g[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&cost[i]);
    //printf("IAKIOI\n");
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int T;
            ll W;
            scanf("%d%lld",&T,&W);
            sta[T].push_back({i,W});
        }
    }
    //printf("IAKIOI\n");
    for(int i=1;i<=m;i++){
        if(sta[i].size()>1){
            for(int j=0;j<sta[i].size();j++){
                for(int k=0;k<j;k++){
                    g[sta[i][j].to].push_back({sta[i][k].to,sta[i][j].w+sta[i][k].w});
                    g[sta[i][k].to].push_back({sta[i][j].to,sta[i][j].w+sta[i][k].w});
                }
            }
        }
    }
    //printf("IAKIOI\n");
    memset(ans,0x3f,sizeof(ans));
    for(int st=1;st<=n;st++){
        for(int i=1;i<=n;i++) vis[i]=false;
        ans[st][st]=0;
        Q.push({st,0});
        while(Q.size()){
            int to=Q.top().p;
            ll val=Q.top().D;
            Q.pop();
            if(vis[to]) continue;
            vis[to]=true;
            ans[st][to]=val;
            for(auto v:g[to]){
                if(!vis[v.v]&&ans[st][v.v]>val+v.w){
                    ans[st][v.v]=val+v.w;
                    Q.push({v.v,ans[st][v.v]});
                }
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",ans[i][j]);
        }
        printf("\n");
    }*/
    while(q--){
        int x,y;
        ll Ans=LONG_LONG_MAX;
        scanf("%d%d",&x,&y);
        for(int i=0;i<sta[x].size();i++){
            for(int j=0;j<sta[y].size();j++){
                Ans=min(Ans,ans[sta[x][i].to][sta[y][j].to]+sta[x][i].w+sta[y][j].w+cost[x]+cost[y]);
            }
        }
        printf("%lld\n",Ans);
    }
    return 0;
}