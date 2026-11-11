#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxN=5e5+20;
ll w[maxN];
vector<pair<int,ll>> edg[maxN];
ll edge[520][520];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(edge,0x3f,sizeof edge);
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++) {
            ll u,w;
            cin>>u>>w;
            edg[u].push_back({i,w});
        }
    }
    for (int i=1;i<=m;i++) {
        int siz=edg[i].size();
        for (int j=0;j<siz;j++) {
            for (int k=j+1;k<siz;k++) {
                int _u=edg[i][j].first;
                int _v=edg[i][k].first;
                int u=min(_u,_v);
                int v=max(_u,_v);
                ll wu=edg[i][j].second;
                ll wv=edg[i][k].second;
                edge[u][v]=min(edge[u][v],wu+wv);
            }
        }
    }
    for (int i=1;i<=n;i++) edge[i][i]=0;
    for (int i=1;i<=n;i++) {
        for (int u=1;u<=n;u++) {
            for (int v=u+1;v<=n;v++) {
                edge[u][v]=min(edge[u][v],edge[min(u,i)][max(u,i)]+edge[min(v,i)][max(v,i)]);
            }
        }
    }
    while (q--) {
        int x,y;
        cin>>x>>y;
        int sizx=edg[x].size();
        int sizy=edg[y].size();
        ll ans=0x3f3f3f3f3f3f3f3f;
        for (int j=0;j<sizx;j++) {
            for (int k=0;k<sizy;k++) {
                int _u=edg[x][j].first;
                int _v=edg[y][k].first;
                int u=min(_u,_v);
                int v=max(_u,_v);
                ll wu=edg[x][j].second;
                ll wv=edg[y][k].second;
                ans=min(edge[u][v]+wu+wv,ans);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
