#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N=505,M=5e5+5,INF=1e18;
int c,n,m,d,q;
int w[M],dis[N][N];
vector<pii> g[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin >> a >> t;
            g[a].pb({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        int sz=g[i].size();
        for(int j=0;j<sz-1;j++){
            int u=g[i][j].first,wu=g[i][j].second;
            for(int k=j+1;k<sz;k++){
                int v=g[i][k].first,wv=g[i][k].second;
                dis[u][v]=min(dis[u][v],wu+wv);
                dis[v][u]=min(dis[v][u],wu+wv);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,ans=INF;
        cin >> x >> y;
        int szx=g[x].size(),szy=g[y].size();
        for(int j=0;j<szx;j++){
            int u=g[x][j].first,wu=g[x][j].second;
            for(int k=0;k<szy;k++){
                int v=g[y][k].first,wv=g[y][k].second;
                ans=min(ans,wu+wv+dis[u][v]);
            }
        }
        ans+=w[x]+w[y];
        cout << ans << "\n";
    }
    return 0;
}