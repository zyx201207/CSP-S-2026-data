#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
#define mp make_pair
#define eb emplace_back
using namespace std;
const int maxn=5e5+500;
int c,n,m,d,q,dis[505][505],w[maxn];
vector<P>a[maxn];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(int i=1,len,x,y;i<=n;i++){
        scanf("%lld",&len);
        while(len--){
            scanf("%lld%lld",&x,&y);
            a[x].eb(mp(i,y));
        }
    }memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1,l;i<=m;i++){l=a[i].size();
        for(int x=0;x<l;x++)
            for(int y=0;y<l;y++)
                dis[a[i][x].first][a[i][y].first]=min(dis[a[i][x].first][a[i][y].first],a[i][x].second+a[i][y].second);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int k=1,x,y,ans;k<=q;k++){
        scanf("%lld%lld",&x,&y),ans=1e18;
        for(P i:a[x])
            for(P j:a[y])
                ans=min(ans,dis[i.first][j.first]+i.second+j.second);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}