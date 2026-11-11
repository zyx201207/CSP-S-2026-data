#include<bits/stdc++.h>
#define i32 signed
#define i64 long long
#define int i64
#define pii pair<int,int>
using namespace std;
const int N=505,M=5e5+5,D=25,inf=1e18;
int n,m,d,q;
int e[N][N];
int w[M];
int t[M][D];
int c[M][D];
int ct[M];
i32 main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)e[i][j]=inf;
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a;cin>>a;
            cin>>t[a][++ct[a]];
            c[a][ct[a]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=ct[i];j++){
            for(int k=1;k<=ct[i];k++){
                int u=c[i][j],v=c[i][k];
                if(u==v)e[u][v]=0;
                else e[u][v]=min(e[u][v],t[i][j]+t[i][k]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    while(q--){
        int u,v,ans=inf;
        cin>>u>>v;
        for(int i=1;i<=ct[u];i++){
            for(int j=1;j<=ct[v];j++){
                ans=min(ans,t[u][i]+t[v][j]+e[c[u][i]][c[v][j]]);   
            }
        }ans+=w[u]+w[v];
        cout<<ans<<"\n";
    }
    return 0;
}
//15：10