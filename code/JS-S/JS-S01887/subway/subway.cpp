#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10,M=510;
ll c,n,m,d,q,x,y;
ll w[N],k[M],a,t;
ll dis[M][M];
ll minn=4e18;
vector<pair<int,int> >lp[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
      scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
            scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&a,&t);
            lp[a].push_back(make_pair(i,t));
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    //jianbian
    for(int i=1;i<=m;i++){
        for(int j=0;j<lp[i].size();j++)
            for(int p=0;p<lp[i].size();p++){
                if(j==p)continue;
                pair<int,int> u=lp[i][j];
                pair<int,int> v=lp[i][p];
                dis[u.first][v.first]=min(dis[u.first][v.first],(ll)(u.second+v.second));
                dis[v.first][u.first]=min(dis[v.first][u.first],(ll)(u.second+v.second));
            }
    }

    //zuiduanlu
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            for(int p=1;p<=n;p++){
                if(i==p||j==p)continue;
                if(dis[i][p]+dis[p][j]<dis[i][j])
                    dis[i][j]=dis[i][p]+dis[p][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%lld%lld",&x,&y);
        minn=4e18;
        for(int j=0;j<lp[x].size();j++)
            for(int p=0;p<lp[y].size();p++)
                minn=min(minn,(ll)(dis[lp[x][j].first][lp[y][p].first]+lp[x][j].second+lp[y][p].second));
        printf("%lld\n",(ll)(w[x]+w[y]+minn));
    }
    return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
