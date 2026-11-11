#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int maxn=505;
constexpr int maxm=5e5+5;
constexpr ll INF=1e17;
ll dis[maxn][maxn];
ll d[maxn][maxm];//xian ting
int w[maxm];
int c,n,m,D,q;
vector<int> nei[maxm];//xian
void floyd(){
    for (int i=1;i<=m;i++){
        for (int u:nei[i]){
            for (int v:nei[i]){
                if (u==v) continue;
                dis[u][v]=min(dis[u][v],d[u][i]+d[v][i]);
                //cout<<u<<' '<<v<<' '<<i<<'\n';
            }
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>D>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        for (int p=1;p<=k;p++){
            int a,t;
            cin>>a>>t;
            d[i][a]=t;
            nei[a].push_back(i);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dis[i][j]=INF;
        }
        dis[i][i]=0;
    }
    floyd();
    //cout<<dis[1][3]<<'\n';
    while (q--){
        int x,y;
        cin>>x>>y;
        ll ans=INF;
        for (int u:nei[x]){
            for (int v:nei[y]){
                ans=min(ans,dis[u][v]+d[u][x]+d[v][y]);
                //cout<<u<<' '<<v<<' '<<ans<<'\n';
            }
        }
        //cout<<ans<<'\n';
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
