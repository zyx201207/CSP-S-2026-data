#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define min(x,y) x>y?y:x
const int N=5e5+5,M=505;
int c,n,m,d,q,f[M][M],W[N];
struct node{
    int x,w;
};
vector<node> g[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;++i){
        cin>>W[i];
    }
    memset(f,0x3f,sizeof(f));
    for (int i=1;i<=n;++i){
        f[i][i]=0;
        int k;cin>>k;
        for (int j=1,w,a;j<=k;++j){
            cin>>a>>w;
            for (int l=0;l<g[a].size();++l){
                int v=g[a][l].x,vw=g[a][l].w;
                f[i][v]=f[v][i]=min(f[i][v],vw+w);
            }
            g[a].push_back((node){i,w});
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            for (int k=1;k<=n;++k){
                f[i][j]=f[j][i]=f[j][i]>f[i][k]+f[j][k]?f[i][k]+f[j][k]:f[j][i];
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=0x3f3f3f3f3f3f3f3f;
        for (int i=0;i<g[x].size();++i){
            int u=g[x][i].x,uw=g[x][i].w;
            for (int j=0;j<g[y].size();++j){
                int v=g[y][j].x,vw=g[y][j].w;
                ans=min(ans,vw+uw+f[u][v]);
            }
        }
        cout<<ans+W[x]+W[y]<<"\n";
    }
    return 0;
}