#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7,M=507;
const ll INF=2e18;
int a[N];
int c,n,m,d,q;
ll dis[M][M];
vector<pair<int,int> >vec[N];
void Files(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}
int main(){
    Files();
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1,k;i<=n;i++){
        scanf("%d",&k);
        for(int j=1,x,y;j<=k;j++){
            scanf("%d%d",&x,&y);
            vec[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=INF;
    for(int i=1;i<=m;i++) for(int j=0;j<(int)vec[i].size();j++) for(int k=j+1;k<(int)vec[i].size();k++){
        int id1=vec[i][j].first,val1=vec[i][j].second;
        int id2=vec[i][k].first,val2=vec[i][k].second;
        dis[id1][id2]=min(dis[id1][id2],1ll*val1+1ll*val2);
        dis[id2][id1]=min(dis[id2][id1],1ll*val1+1ll*val2);
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1,u,v;i<=q;i++){
        scanf("%d%d",&u,&v);
        ll ans=INF;
        for(auto j: vec[u]) for(auto k: vec[v]){
            int id1=j.first,val1=j.second;
            int id2=k.first,val2=k.second;
            ans=min(ans,dis[id1][id2]+1ll*val1+1ll*val2);
        }
        ans+=1ll*a[u]+1ll*a[v];
        printf("%lld\n",ans);
    }
    return 0;
}
