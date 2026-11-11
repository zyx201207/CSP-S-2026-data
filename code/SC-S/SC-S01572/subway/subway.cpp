#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
using ll=long long;
const int N=5e5+5,M=505;
const ll inf=1e18;
struct node{
    int u;
    ll w;
};
vector<node> hv[N];
ll rdis[N],dis[M][M];
int n,m,q,d,tid;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>tid>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>rdis[i];
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int id;
            ll w;
            cin>>id>>w,hv[id].push_back({i,w});
        }
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dis[i][j]=inf;
    for(int i=1;i<=n;++i) dis[i][i]=0;
    for(int i=1;i<=m;++i)
        for(auto &u:hv[i]) for(auto &v:hv[i]) dis[u.u][v.u]=min(dis[u.u][v.u],u.w+v.w);
    for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x==y){
            printf("0\n");
            continue;
        }
        ll ans=inf;
        for(auto u:hv[x]) for(auto v:hv[y]) ans=min(ans,dis[u.u][v.u]+u.w+v.w);
        printf("%lld\n",ans+rdis[x]+rdis[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}