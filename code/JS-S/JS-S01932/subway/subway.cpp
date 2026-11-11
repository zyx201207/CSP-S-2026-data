#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=510;
typedef long long LL;
int c,n,m,d,q,w[M],a[N][M],t[N][M];
LL dis[N][N];
vector<int>pas[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&a[i][j]);
            scanf("%d",&t[i][a[i][j]]);
            pas[a[i][j]].push_back(i);
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=500;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<pas[i].size();j++){
            for(int k=0;k<pas[i].size();k++){
                dis[pas[i][j]][pas[i][k]]=min(dis[pas[i][j]][pas[i][k]],(LL)(t[pas[i][j]][i]+t[pas[i][k]][i]));
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        LL ans=0x3f3f3f3f3f3f3f3f;
        int x,y;
        cin>>x>>y;
        for(int i=0;i<pas[x].size();i++){
            for(int j=0;j<pas[y].size();j++){
                ans=min(ans,(LL)(dis[pas[x][i]][pas[y][j]]+w[x]+w[y]+t[pas[x][i]][x]+t[pas[y][j]][y]));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
