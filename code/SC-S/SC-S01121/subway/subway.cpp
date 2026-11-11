#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
const long long inf=1e18;
int c,n,m,d,q;
long long w[M],dis[N][N];
struct edge{long long v,t;};
vector<edge> g[M];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1,k;i<=n;i++){
        cin >> k,dis[i][i]=0;
        while(k--){
            long long a,t;
            cin >> a >> t;
            g[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j:g[i]) for(auto k:g[i]) dis[j.v][k.v]=min(dis[j.v][k.v],j.t+k.t);
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        long long ans=inf;
        cin >> x >> y;
        for(auto i:g[x]) for(auto j:g[y]) ans=min(ans,dis[i.v][j.v]+i.t+j.t);
        cout << ans+w[x]+w[y] << "\n";
    }
    return 0;
}