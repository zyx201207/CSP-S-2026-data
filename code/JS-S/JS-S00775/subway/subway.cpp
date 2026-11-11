#include<bits/stdc++.h>
#define int long long
using namespace std;
int cc,n,m,d,q,out[500005],dis[505][505];
vector<pair<int,int> >v[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&cc,&m,&n,&d,&q);
    for(int i=1;i<=n;i++)scanf("%lld",&out[i]);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)dis[i][i]=0;
    for(int i=1,len;i<=m;i++){
        scanf("%lld",&len);
        for(int j=1,x,y;j<=len;j++){
            scanf("%lld%lld",&x,&y);
            v[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            for(int k=j+1;k<v[i].size();k++){
                int rt1=v[i][j].first,rt2=v[i][k].first,dis1=v[i][j].second,dis2=v[i][k].second;
                dis[rt1][rt2]=min(dis[rt1][rt2],dis1+dis2);
                dis[rt2][rt1]=min(dis[rt2][rt1],dis1+dis2);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y,res=1e18;
        scanf("%lld%lld",&x,&y);
        for(int i=0;i<v[x].size();i++){
            for(int j=0;j<v[y].size();j++){
                res=min(res,v[x][i].second+v[y][j].second+dis[v[x][i].first][v[y][j].first]);
            }
        }
        printf("%lld\n",out[x]+out[y]+res);
    }
    return 0;
}
