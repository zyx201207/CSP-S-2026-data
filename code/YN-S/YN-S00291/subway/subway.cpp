//I love Nagato Yuki forever!!!
//15:46
#include<bits/stdc++.h>
using namespace std;
namespace Z3k7223{
    #define ll long long
    const int N=5e5+10,M=510;
    const ll inf=1e18;
    int c,n,m,d,q;
    ll w[N],dis[M][M];
    struct node{
        int v;
        ll w;
    };
    vector<node>g[N];
    void solve(){
        scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
        for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            while(k--){
                int x;
                ll w;
                scanf("%d%lld",&x,&w);
                g[x].push_back({i,w});
            }
        }
        memset(dis,0x3f,sizeof dis);
        for(int i=1;i<=n;i++)dis[i][i]=0;
        for(int i=1;i<=m;i++){
            for(node x:g[i]){
                for(node y:g[i]){
                    dis[x.v][y.v]=min(dis[x.v][y.v],x.w+y.w);
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            ll res=inf;
            for(node u:g[x]){
                for(node v:g[y]){
                    res=min(res,u.w+dis[u.v][v.v]+v.w);
                }
            }
            printf("%lld\n",res+w[x]+w[y]);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    Z3k7223::solve();
    return 0;
}