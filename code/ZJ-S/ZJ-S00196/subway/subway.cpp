#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    vector<int> w(m+1);
    for(int i=1;i<=m;++i) cin>>w[i];
    vector<vector<pair<int,int>>> gra(m+1);
    for(int i=1;i<=m;++i) gra[i].reserve(d);
    for(int i=1;i<=n;++i) {
        int k;
        cin>>k;
        while(k--) {
            int a,t;
            cin>>a>>t;
            gra[a].emplace_back(i,t);
        }
    }
    vector<vector<ll>> dis(n+1,vector<ll>(n+1,INF));
    for(int i=1;i<=n;++i) dis[i][i]=0;
    for(int i=1;i<=m;++i) {
        for(int a=0;a<gra[i].size();++a)
            for(int b=a+1;b<gra[i].size();++b) {
                auto& [u,d1]=gra[i][a];
                auto& [v,d2]=gra[i][b];
                ll nd=d1+d2;
                dis[u][v]=min(dis[u][v],nd);
                dis[v][u]=min(dis[v][u],nd);
            }
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i) {
            if(dis[i][k]==INF) continue;
            for(int j=1;j<=n;++j) {
                if(dis[k][j]==INF) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    while(q--) {
        int x,y;
        cin>>x>>y;
        ll nd=INF;
        for(auto& [u,d1]:gra[x])
            for(auto& [v,d2]:gra[y])
                nd=min(nd,d1+d2+dis[u][v]);
        cout<<nd+w[x]+w[y]<<'\n';
    }
}