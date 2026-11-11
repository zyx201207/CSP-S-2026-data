#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],f[510][510],u,v;
vector<int>a[510],t[510];
vector<pair<int,int>>node[500010];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(f,127,sizeof f);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].resize(k[i]+1);
        t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            node[a[i][j]].push_back({i,j});
        }
    }
    for(int i=0;i<=500;i++)f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<node[i].size();j++){
            for(int k=j;k<node[i].size();k++){
                int x=node[i][j].second,y=node[i][k].second;
                f[node[i][j].first][node[i][k].first]=min(f[node[i][j].first][node[i][k].first],t[node[i][j].first][x]+t[node[i][k].first][y]);
                f[node[i][k].first][node[i][j].first]=min(f[node[i][k].first][node[i][j].first],t[node[i][j].first][x]+t[node[i][k].first][y]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][k]>1<<30||f[k][j]>1<<30)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(;q--;){
        cin>>u>>v;
        int ans=INT_MAX;
        for(int j=0;j<node[u].size();j++){
            for(int k=0;k<node[v].size();k++){
                ans=min(ans,f[node[u][j].first][node[v][k].first]);
            }
        }
        cout<<w[u]+w[v]+ans<<'\n';
    }
    return 0;
}
