#include<bits/stdc++.h>
using namespace std;
const int N=510,M=500010; int a[M];
struct Node { int v,t; };
vector<Node>g[N],vec[M]; long long dis[N][N];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        int k; cin>>k,g[i].resize(k);
        for(int j=0;j<k;j++) {
            cin>>g[i][j].v>>g[i][j].t;
            vec[g[i][j].v].push_back({i,g[i][j].t});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) dis[i][j]=1e18;
    for(int i=1;i<=n;i++)
        for(auto j:g[i]) {
            int v=j.v,t=j.t;
            for(auto k:vec[v]) dis[i][k.v]=min(dis[i][k.v],1ll*t+k.t);
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--) {
        int x,y; long long mn=1e18; cin>>x>>y;
        for(auto i:vec[x])
            for(auto j:vec[y])
                mn=min(mn,i.t+j.t+dis[i.v][j.v]);
        cout<<mn+a[x]+a[y]<<'\n';
    }
    return 0;
}
