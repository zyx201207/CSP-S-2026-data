#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=5e2+10;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
#define x first
#define y second
int c,n,m,d,q,w[M],f[N][N];
vector<PII> G[M];
void build(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                f[i][j]=0;
                continue;
            }
            f[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<G[i].size();j++){
            for(int k=j+1;k<G[i].size();k++){
                f[G[i][j].x][G[i][k].x]=min(f[G[i][j].x][G[i][k].x],G[i][j].y+G[i][k].y);
                f[G[i][k].x][G[i][j].x]=min(f[G[i][k].x][G[i][j].x],G[i][j].y+G[i][k].y);
            }
        }
    }
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k,a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            G[a].push_back({i,t});
        }
    }
    build();
    floyd();
    while(q--){
        int u,v,ans=inf;
        cin>>u>>v;
        for(int i=0;i<G[u].size();i++){
            for(int j=0;j<G[v].size();j++){
                ans=min(ans,G[u][i].y+G[v][j].y+w[u]+w[v]+f[G[u][i].x][G[v][j].x]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
