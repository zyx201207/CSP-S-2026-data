#include<bits/stdc++.h>
using namespace std;
#define pil pair<int,ll>
typedef long long ll;
const int maxn=505;
const int maxm=5e5+5;
int c,n,m,d,q;
ll f[maxn][maxn],w[maxm];
vector<pil> g[maxm];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1; i<=m; i++){
        scanf("%lld",&w[i]);
    }
    memset(f,0x3f,sizeof f);
    for(int i=1; i<=n; i++){
        f[i][i]=0;
    }
    for(int i=1; i<=n; i++){
        int k;
        scanf("%d",&k);
        for(int j=1; j<=k; j++){
            int a;
            ll t;
            scanf("%d%lld",&a,&t);
            g[a].push_back({i,t});
        }
    }
    for(int i=1; i<=m; i++){
        int len=g[i].size();
        for(int x=0; x<len; x++){
            for(int y=x+1; y<len; y++){
                pil u=g[i][x],v=g[i][y];
                f[u.first][v.first]=f[v.first][u.first]=min(f[u.first][v.first],u.second+v.second);
            }
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int lenx=g[x].size(),leny=g[y].size();
        ll ans=1e18;
        for(int i=0; i<lenx; i++){
            for(int j=0; j<leny; j++){
                pil u=g[x][i],v=g[y][j];
                ans=min(ans,f[u.first][v.first]+w[x]+w[y]+u.second+v.second);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
