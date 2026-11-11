#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,a,t,w[500005],dis[505][505],x,y,ans;
struct side{
    long long l,val;
};
vector<side>e[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            e[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            dis[i][j]=1000000000000000000;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<e[i].size();j++){
            for(int k=j+1;k<e[i].size();k++){
                dis[e[i][j].l][e[i][k].l]=min(dis[e[i][j].l][e[i][k].l],e[i][j].val+e[i][k].val);
                dis[e[i][k].l][e[i][j].l]=min(dis[e[i][k].l][e[i][j].l],e[i][j].val+e[i][k].val);
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
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=1000000000000000000;
        for(int i=0;i<e[x].size();i++){
            for(int j=0;j<e[y].size();j++){
                ans=min(ans,dis[e[x][i].l][e[y][j].l]+e[x][i].val+e[y][j].val);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<endl;
    }
    return 0;
}
