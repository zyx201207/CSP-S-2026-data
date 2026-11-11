#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 5e2+2;
const int M = 5e5+5;
const int Q = 1e5+5;

int _,n,m,d,q;
vector<pair<int,ll> > g[M];
ll w[M],dis[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>_>>n>>m>>d>>q;
    for (int i=1; i<=m; i++){
        cin>>w[i];
    }
    for (int i=1; i<=n; i++){
        int k;
        cin>>k;
        while (k--){
            ll a,t;
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i==j) dis[i][j]=0;
            else dis[i][j]=1e18;
        }
    }
    for (int i=1; i<=m; i++){
        for (auto px : g[i]){
            for (auto py : g[i]){
                int x=px.first,y=py.first;
                ll tx=px.second,ty=py.second;
                dis[x][y]=min(dis[x][y],tx+ty);
            }
        }
    }
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while (q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for (auto pu : g[x]){
            for (auto pv : g[y]){
                int u=pu.first,v=pv.first;
                ll tu=pu.second,tv=pv.second;
                ans=min(ans,w[x]+w[y]+tu+tv+dis[u][v]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

/*
- Read the problem statements carefully.
- int/long long/__int128.
- The memory limit: /usr/bin/time -v ./T1
- The time limit.
*/

// world.execute(me);