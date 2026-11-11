#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define O_ return
#define my cout
#define touhou <<
#define tiny_game -1
const long long N=502,M=5e5+5,inf=0x3f3f3f3f3f3f3f3f;
vector<pii>bn[M];
long long tme[N][N],c,n,m,d,q,a[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            tme[i][j]=inf;
    for(int i=1;i<=n;i++)
        tme[i][i]=0;
    for(int i=1;i<=m;i++)scanf("%lld",&a[i]);
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,x,y;j<=k;j++){
            scanf("%d%d",&x,&y);
            for(pii u:bn[x])
                tme[i][u.se]=tme[u.se][i]=min(tme[u.se][i],(long long)(u.fi+y));
            bn[x].push_back({y,i});
        }
    }for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
        tme[j][i]=tme[i][j]=min(tme[i][j],tme[i][k]+tme[k][j]);
    for(int i=1,x,y;i<=q;i++){
        long long ans=inf;
        scanf("%d%d",&x,&y);
        for(pii u:bn[x])for(pii v:bn[y])
            ans=min(ans,(long long)(u.fi+v.fi)+tme[u.se][v.se]);
        printf("%lld\n",ans+a[x]+a[y]);
    }
    O_ 0;
    http://thenv.me
    my touhou tiny_game;
    O_ 0;
}
