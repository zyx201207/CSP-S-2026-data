#include<bits/stdc++.h>
using namespace std;
struct st{
    int fa,w;
};
struct edge{
    int v,w;
};
bool operator < (const edge &A,const edge &B){
    return A.w>=B.w;
}
int n,m,d,q;
int w[500010];
vector<st> f[500010];//station refers to...
//st h[500010];
//bool tmph[500010];
//vector<st> hc;//trans. staion
vector<int> b;
vector<edge> a[500510];
long long dis[500510];
long long fun(int ks,int js){
    for(int i=1;i<=n+m;i++) dis[i]=1e9+7;
    priority_queue<edge> q;
    q.push({ks,0});
    dis[ks]=0;
    while(!q.empty()){
        int u=q.top().v,disu=q.top().w;
        q.pop();
        if(disu>dis[u]) continue;
        for(auto x:a[u]){
            int v=x.v,w=x.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
    return dis[js];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    scanf("%d",&c);

    scanf("%d%d%d%d",&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x,y;
            scanf("%d%d",&x,&y);
            f[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        if(f[i].size()>1){//huanchengzhan
            for(int j=0;j<f[i].size();j++){//jiantu
                a[n+i].push_back({f[i][j].fa,f[i][j].w});
                a[f[i][j].fa].push_back({n+i,f[i][j].w});
            }
            f[i].clear();
            b.push_back(i);
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=w[x]+w[y];
        int ks,js;
        if(b[lower_bound(b.begin(),b.end(),x)-b.begin()]==x){
            ks=x+n;
        }
        else{
            ks=f[x][0].fa;
            ans+=f[x][0].w;
        }
        if(b[lower_bound(b.begin(),b.end(),y)-b.begin()]==y){
            js=y+n;
        }
        else{
            js=f[y][0].fa;
            ans+=f[y][0].w;
        }
        printf("%lld\n",fun(ks,js)+ans);
    }
    return 0;
}

