#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10,M=510;
int c,n,m,d,q,w[N],k[N],t[M][N];
ll f[M][M];
vector<int> bel[N],way[M];
vector<int> edge[N];
void floyd(){
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>c>>n>>m>>d>>q;//xianlushu n zhanshu m
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=1e17;
        }
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a;
            cin>>a;cin>>t[i][a];
            bel[a].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(bel[i].size()>=2){
            for(auto u:bel[i]){
                for(auto v:bel[i]){
                    if(u==v) continue;
                    //edge[u].push_back({v,t[u][i]+t[v][i]});
                    //edge[v].push_back({u,t[u][i]+t[v][i]});
                    f[u][v]=f[v][u]=1ll*(t[u][i]+t[v][i]);
                }
            }
        }
    }
    floyd();
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<"i,j:"<<i<<" "<<j<<" "<<f[i][j]<<'\n';
        }
    }
    */
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        ll ans=w[x]+w[y],tot=1e18;
        for(auto u:bel[x]){
            for(auto v:bel[y]){
                if(u==v) tot=min(tot,1ll*(t[u][x]+t[v][y]));
                else tot=min(tot,1ll*(t[u][x]+t[v][y])+f[u][v]);
            }
        }
        cout<<ans+tot<<'\n';
    }
    return 0;
}