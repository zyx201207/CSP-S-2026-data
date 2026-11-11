#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=500010;
const i64 INF=0x3f3f3f3f3f3f3f3fll;
i64 c,n,m,d,q;
int w[N];
vector<pair<int,int> >vec[N];
i64 G[510][510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int x,y;cin>>x>>y;
            vec[x].push_back(make_pair(i,y));
        }
    }
    memset(G,0x3f,sizeof(G));
    for(int i=1;i<=n;i++)G[i][i]=0;
    for(int i=1;i<=m;++i){
        int tot=(int)vec[i].size();
        for(int j=0;j<tot;++j){
            for(int k=j+1;k<tot;++k){
                int u=vec[i][j].first,v=vec[i][k].first,w=vec[i][j].second+vec[i][k].second;
                G[u][v]=min(G[u][v],(i64)w);
                G[v][u]=min(G[v][u],(i64)w);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    while(q--){
        int u,v;cin>>u>>v;
        int totu=(int)vec[u].size(),totv=(int)vec[v].size();
        i64 ans=INF;
        for(int i=0;i<totu;++i){
            for(int j=0;j<totv;++j){
                ans=min(ans,(i64)w[u]+vec[u][i].second+G[vec[u][i].first][vec[v][j].first]+vec[v][j].second+w[v]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*

*/