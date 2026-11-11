#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=1e6+10;
struct Edge{
    int v,w;
};
vector<Edge> g[N];
int t[50][N],a[50][N],fa[N],dis[N],h[N];
int w[N];
int c,n,m,d,Q;
priority_queue<PII> q;
void dij(int s) {
    memset(dis,0x3f3f3f3f,sizeof(dis));
    q.push(make_pair(w[s],s));
    dis[s]=w[s];
    for(int i=0;i<g[s].size();i++) {
        q.push(make_pair(g[s][i].w,g[s][i].v));
        dis[g[s][i].v]=g[s][i].w+w[s];
    }
    while(!q.empty()) {
        int u=q.top().second;
        q.pop();
        for(int i=0;i<g[u].size();i++) {
            int v=g[u][i].v,w=g[u][i].w;
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                q.push(make_pair(dis[v],v));
            }
        }
    }
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) {
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=k;j++) {
            for(int h=1;h<=k;h++) {
                if(j==h) continue;
                g[a[i][j]].push_back(Edge{a[i][h],t[i][j]+t[i][h]});
                g[a[i][h]].push_back(Edge{a[i][j],t[i][j]+t[i][h]});
            }
        }
    }
    for(int i=1;i<=Q;i++) {
        int a,b;
        cin>>a>>b;
        dij(a);
        cout<<dis[b]+w[b]<<'\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/