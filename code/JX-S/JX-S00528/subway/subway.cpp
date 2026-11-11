#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 5;
const long long INF = 1e18 + 7;
int c,n,m,d,q;
vector <pair<int,long long> > to[maxn];
int w[maxn];
vector <pair<int,int> > sub[maxn];
long long dis[maxn][maxn];
long long W[maxn][maxn];
inline void djk (int s) {
    priority_queue <pair<long long,int>  ,vector<pair<long long,int> >  ,greater<pair<long long,int> >> q;
    q.push({0,s});
    while(!q.empty()) {
        int u=q.top().second;
        int f=q.top().first;
        q.pop();
        if(f!=dis[s][u]) continue;
        for(int i=0;i<to[u].size();++i) {
            int v=to[u][i].first;
            int w=to[u][i].second;
            if(dis[s][u]+w < dis[s][v]) {
                dis[s][v]=dis[s][u]+w;
                q.push({dis[s][v],v});
            }
        }
    }
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i) {
        int k; cin>>k;
        for(int j=1;j<=k;++j) {
            int a,t; cin>>a>>t;
            sub[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(i==j) continue;
            dis[i][j]=W[i][j]=INF;
        }
    }
    for(int i=1;i<=m;++i) {
        for(int j=0;j<sub[i].size();++j) {
            for(int k=j+1;k<sub[i].size();++k) {
                int u=sub[i][j].first,wu=sub[i][j].second;
                int v=sub[i][k].first,wv=sub[i][k].second;
                W[u][v]=W[v][u]=min(dis[u][v],1ll*wu+1ll*wv);
            }
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(W[i][j]==INF) continue;
            to[i].push_back({j,W[i][j]});
            to[j].push_back({i,W[i][j]});
        }
    }
    for(int i=1;i<=n;++i) djk(i);
    while(q--) {
        int x,y;
        cin>>x>>y;
        long long res=INF;
        for(int i=0;i<sub[x].size();++i) {
            for(int j=0;j<sub[y].size();++j) {
                int u=sub[x][i].first,wu=sub[x][i].second;
                int v=sub[y][j].first,wv=sub[y][j].second;
                res=min(res,wu+wv+dis[u][v]);
            }
        }
        cout<<res+w[x]+w[y]<<'\n';
    }
    return 0;
}
