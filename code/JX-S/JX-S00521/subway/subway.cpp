#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+10;
int c,n,m,d,q,w[M],f[N][N];
struct node{
    int u,w;
};
vector<node> g[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(f,0x3f,sizeof f);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    int aa,tt;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            cin>>aa>>tt;
            if(g[aa].size()){
                for(auto x:g[aa]){
                    int u=x.u,w=x.w;
                    f[u][i]=min(f[u][i],w+tt);
                    f[i][u]=min(f[u][i],w+tt);
                }
            }
            g[aa].push_back({i,tt});
        }
    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        int mins=LLONG_MAX;
        for(auto gx:g[x]){
            for(auto gy:g[y]){
                mins=min(mins,gx.w+gy.w+f[gx.u][gy.u]);
            }
        }
        cout<<mins+w[x]+w[y]<<'\n';
    }
    return 0;
}
