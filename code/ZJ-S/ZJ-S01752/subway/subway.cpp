#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int N = 520,M = 5e5+10,inf = 1e18;
int c,n,m,_,q,w[M],dis[N][N];
vector<pii> d[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> _ >> q;
    for(int i = 1;i <= m;i ++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i ++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j ++){
            int a,t;
            cin >> a >> t;
            d[a].pb({i,t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i = 1;i <= n;i ++)  dis[i][i]=0;
    for(int i = 1;i <= m;i ++){
        for(int j = 0;j < d[i].size();j ++){
            for(int k = j+1;k < d[i].size();k ++){
                dis[d[i][k].fi][d[i][j].fi]=dis[d[i][j].fi][d[i][k].fi]=min(dis[d[i][j].fi][d[i][k].fi],d[i][j].se+d[i][k].se);

            }
        }
    }
    for(int k = 1;k <= n;k ++){
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y,ans=inf;
        cin >> x >> y;
        for(int i = 0;i < d[x].size();i ++){
            for(int j = 0;j < d[y].size();j ++){
                ans=min(ans,dis[d[x][i].fi][d[y][j].fi]+d[x][i].se+d[y][j].se);
            }
        }
        cout << ans+w[x]+w[y] << '\n';
    }
    return 0;
}