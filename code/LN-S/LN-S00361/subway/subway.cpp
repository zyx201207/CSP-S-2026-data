#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN=507,MAXM=5e5+7,INF=1e17+7;
long long g[MAXN][MAXN];
vector<pair<int,long long> >sta[MAXM];
long long w[MAXM];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(g,0x3f,sizeof(g));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        g[i][i]=0;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            long long v,t;
            cin>>v>>t;
            sta[v].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto x:sta[i]){
            for(auto y:sta[i]){
                if(x.first!=y.first){
                    g[x.first][y.first]=min(g[x.first][y.first],x.second+y.second);
                    g[y.first][x.first]=min(g[y.first][x.first],x.second+y.second);
                }
            }
        }      
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=k&&j!=k){
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        long long ans=INF;
        for(auto x:sta[u]){
            for(auto y:sta[v]){
                ans=min(ans,g[x.first][y.first]+x.second+y.second);
            }
        }
        ans+=w[u]+w[v];
        cout<<ans<<endl;
    }
    return 0;
}