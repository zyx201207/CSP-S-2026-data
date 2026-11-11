#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool b1;
int n,m,d,q;
const int N=505,M=500005;
ll W[M];
vector<pair<int,ll>> vec[M];
ll dis[N][N];
bool b2;
signed main(){
    // cerr<<(&b2-&b1)/1024.0/1024;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%*d%d%d%d%d",&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&W[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x;
            ll y;
            scanf("%d%lld",&x,&y);
            vec[x].push_back({i,y});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        for(int j=1;j<(int)vec[i].size();j++){
            for(int k=0;k<j;k++){
                int J=vec[i][j].first,K=vec[i][k].first;
                dis[J][K]=min(dis[J][K],vec[i][j].second+vec[i][k].second);
                dis[K][J]=min(dis[K][J],vec[i][j].second+vec[i][k].second);
            }
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
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
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(auto prx:vec[x]){
            int a=prx.first;
            ll ca=prx.second;
            for(auto pry:vec[y]){
                int b=pry.first;
                ll cb=pry.second;
                ans=min(ans,ca+cb+dis[a][b]);
            }
        }
        printf("%lld\n",ans+W[x]+W[y]);
    }
    return 0;
}