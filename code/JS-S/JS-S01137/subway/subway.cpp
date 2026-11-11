#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
struct P{
    long long id,t;
};
vector<P>vis[500005];
long long huan[505][505];
long long dis[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    long long rec=0;
    for(int i=1;i<=n;i++){
        long long kk;
        scanf("%lld",&kk);
        for(int j=1;j<=kk;j++){
            long long x,y;
            scanf("%lld%lld",&x,&y);
            vis[x].push_back({i,y});
            rec=y;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)huan[i][j]=dis[i][j]=1e18;
        huan[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        if(vis[i].size()>1){
            for(auto j:vis[i]){
                for(auto k:vis[i]){
                    if(j.id==k.id)continue;
                    huan[j.id][k.id]=min(huan[j.id][k.id],j.t+k.t);
                }
            }
        }
    }
    for(int it=1;it<=n;it++){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >p;
    p.push({0,it});
    dis[it][it]=0;
    while(!p.empty()){
        long long w=p.top().first,u=p.top().second;
        p.pop();
        if(w>dis[it][u])continue;
        for(int j=1;j<=n;j++){
            if(j==it)continue;
            if(dis[it][j]>w+huan[u][j]){
                dis[it][j]=w+huan[u][j];
                p.push({dis[it][j],j});
            }
        }
    }
    }
    for(int i=1;i<=q;i++){
        long long x,y,ans=1e18;
        scanf("%lld%lld",&x,&y);
        for(auto j:vis[x]){
            for(auto k:vis[y]){
                ans=min(ans,dis[j.id][k.id]+j.t+k.t);
            }
        }
        long long res=ans+w[x]+w[y];
        printf("%lld\n",res);
    }
    return 0;
}
