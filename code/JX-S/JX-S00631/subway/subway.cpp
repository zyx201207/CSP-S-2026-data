#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,p[(int)1e5*5+5],di[505][505],dist[505][505];
vector<pair<int,int>>nq[5*(int)1e5+5];
bool vis[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++){
        cin >> p[i];
    }
    memset(di,0x3f,sizeof(di));
    for(int i = 1;i<=n;i++){
        int k;
        cin >> k;
        for(int j = 1;j<=k;j++){
            int a,t;
            cin >> a >> t;
            for(pair<int,int> o:nq[a]){
                int y = o.first;
                int dis = o.second;
                di[i][y] = di[y][i] = min(di[i][y],dis+t);
            }
            nq[a].push_back({i,t});
        }
    }
    memset(dist,0x3f,sizeof(dist));
    for(int i = 1;i<=n;i++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>qp;
        qp.push({0,i});
        dist[i][i] = 0;
        while(!qp.empty()){
            pair<int,int>nw = qp.top();
            qp.pop();
            int x = nw.second;
            if(vis[i][x]) continue;
            vis[i][x]=1;
            int dis = nw.first;
            for(int j = 1;j<=n;j++){
                if(dist[i][j]>di[x][j]+dis){
                    dist[i][j]=di[x][j]+dis;
                    qp.push({dist[i][j],j});
                }
            }
        }
    }
    while(q--){
        int u,v;
        cin >> u >> v;
        int ans = 1e18;
        for(pair<int,int> x:nq[u]){
            for(pair<int,int>y:nq[v]){
                ans = min(ans,p[u]+p[v]+dist[x.first][y.first]+x.second+y.second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
