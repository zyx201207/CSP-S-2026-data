#include <cstdio>
#include <vector>
using namespace std;
#define ll unsigned long long
#define MAXN 2e12
ll c,m,n,d,q,w[500003],k,a[500003],t[500003],dis[502][502],x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%llu %llu %llu %llu %llu",&c,&n,&m,&d,&q);
    for (int i=2;i<=m;i++){
        for (int j=1;j<i;j++){
            dis[i][j]=MAXN;
            dis[j][i]=MAXN;
        }
    }
    for (ll i=1;i<=m;i++){
        scanf("%llu",&w[i]);
    }
    for (ll i=1;i<=n;i++){
        scanf("%llu",&k);
        for (ll j=1;j<=k;j++){
            scanf("%llu %llu",&a[j],&t[j]);
        }
        for (ll u=2;u<=k;u++){
            for (ll v=1;v<u;v++){
                dis[a[u]][a[v]]=min(dis[a[u]][a[v]],t[u]+t[v]);
                dis[a[v]][a[u]]=min(dis[a[v]][a[u]],t[u]+t[v]);
            }
        }
    }
    for (ll k=1;k<=m;k++){
        for (ll i=1;i<=m;i++){
            for (ll j=1;j<=m;j++){
                if (j==k || i==k) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for (ll i=1;i<=q;i++){
        scanf("%llu %llu",&x,&y);
        ll ans=w[x]+w[y]+dis[x][y];
        printf("%llu\n",ans);
    }
    return 0;
}
