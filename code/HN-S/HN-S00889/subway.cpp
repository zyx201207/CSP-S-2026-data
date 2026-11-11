#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500010];
vector<pair<int,int> >lu[510];
vector<pair<int,int> >dian[500010];
int dis[510][510];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int id,n,m,d,q;
    cin>>id>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)dis[i][j]=1e18;
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int aa,t;
            cin>>aa>>t;
            lu[i].push_back({aa,t});
            dian[aa].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)lu[i].size();j++){
            pair<int,int>uu=lu[i][j];
            int u=uu.first;
            for(int k=0;k<(int)dian[u].size();k++){
                if(dian[u][k].first==i)continue;
                int dui=dian[u][k].first;
                dis[i][dui]=min(dis[i][dui],uu.second+dian[u][k].second);
                dis[dui][i]=min(dis[dui][i],uu.second+dian[u][k].second);
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
        cin>>x>>y;
        int minn=1e18;
        for(int i=0;i<(int)dian[x].size();i++){
            pair<int,int>AA=dian[x][i];
            for(int j=0;j<(int)dian[y].size();j++){
                pair<int,int>BB=dian[y][j];
                minn=min(minn,AA.second+BB.second+dis[AA.first][BB.first]);
            }
        }
        cout<<minn+w[x]+w[y]<<"\n";
    }
    return 0;
}