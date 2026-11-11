#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],a,t;
struct node{
    int v,w;
};
vector<vector<node> >G(501010);
long long Dij(int x,int y){
    long long dis[501010];
    bool inq[501010]={0};
    dis[x]=0;
    memset(dis,0x7f7f7f7f,sizeof(dis));
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    pq.push({0,x});
    while(!pq.empty()){
        auto xx=pq.top();
        pq.pop();
        if(inq[xx.second]||xx.first>dis[xx.second])continue;
        inq[xx.second]=1;
        for(auto i:G[xx.second]){
            if(!inq[i.v]&&dis[i.v]>dis[xx.second]+i.w){
                dis[i.v]=dis[xx.second]+i.w;
                pq.push({dis[i.v],i.v});
            }
        }
    }
    return dis[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
        node xx;
        xx.v=i+m;
        xx.w=w[i];
        G[i].push_back(xx);
        xx.v=i;
        G[i+m].push_back(xx);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a,&t);
            node xx;
            xx.v=2*m+i;
            xx.w=t;
            G[a+m].push_back(xx);
            xx.v=a+m;
            G[2*m+i].push_back(xx);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",Dij(x,y));
    }
    return 0;
}
