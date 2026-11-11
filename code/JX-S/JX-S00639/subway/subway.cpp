#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,D=25,M=5e5+100;
const ll Inf=0x3f3f3f3f'3f3f3f3f;
ll val[M];
struct Node{
    int u;
    ll w;
};
vector<Node> b[M];
// vector<Node> a[N];
ll dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for (int i=1;i<=m;i++) scanf("%lld",&val[i]);
    for (int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for (int j=1;j<=k;j++){
            int u;
            ll x;
            scanf("%d%lld",&u,&x);
            b[u].push_back({i,x});
        }
    }
    /*
    for (int i=1;i<=m;i++){
        for (auto j : b[i]){
            cerr << i << " " << j.u << " " << j.w << "\n";
        }
    }
    */
    memset(dis,0x3f,sizeof dis);
    for (int i=1;i<=n;i++) dis[i][i]=0;
    for (int u=1;u<=m;u++){
        for (auto i : b[u]){
            for (auto j : b[u]){
                dis[i.u][j.u]=dis[j.u][i.u]=min(dis[i.u][j.u],i.w+j.w);
            }
        }
    }
    /*
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j) continue;
            if (dis[i][j]==Inf) continue;
            a[i].push_back({j,dis[i][j]});
            a[j].push_back({i,dis[i][j]});
        }
    }
    */
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    /*
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cerr << dis[i][j] << " ";
        }
        cerr << "\n";
    }
    */
    while (q--){
        int u,v;
        scanf("%d%d",&u,&v);
        ll ans=Inf;
        for (auto i : b[u]){
            for (auto j : b[v]){
                ans=min(ans,i.w+j.w+dis[i.u][j.u]);
            }
        }
        // cerr << "! " << ans << "\n";
        ans+=val[u]+val[v];
        printf("%lld\n",ans);
    }
    return 0;
}
