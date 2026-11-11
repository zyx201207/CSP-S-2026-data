#include <bits/stdc++.h>

using pii=std::pair<long long, int>;

const int N(500);

const int M(500000);

int c, n, m, d, q;

long long w[M+5];

std::vector<pii> to[N+M+5];

long long g[N+5][N+5];

int main() {
    std::freopen("subway.in", "r", stdin);
    std::freopen("subway.out", "w", stdout);
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cin>>c>>n>>m>>d>>q;
    for(int i(1); i<=m; i++) std::cin>>w[i];
    for(int i(1); i<=n; i++) {
        int k; std::cin>>k;
        while(k--) {
            int a, t; std::cin>>a>>t;
            to[a].push_back({t, i});
        }
    }
    for(int i(1); i<=n; i++) {
        for(int j(1); j<=n; j++) g[i][j]=1ll<<60;
        g[i][i]=0;
    }
    for(int i(1); i<=m; i++) {
        int di(to[i].size());
        for(int j(0); j<di; j++) {
            for(int k(j+1); k<di; k++) {
                int u(to[i][j].second), v(to[i][k].second);
                g[u][v]=g[v][u]=std::min(g[u][v], to[i][j].first+to[i][k].first);
            }
        }
    }
    for(int k(1); k<=n; k++) {
        for(int i(1); i<=n; i++) {
            for(int j(1); j<=n; j++) g[i][j]=std::min(g[i][j], g[i][k]+g[k][j]);
        }
    }
    // for(int i(1); i<=n; i++) {
    //     for(int j(1); j<=n; j++) {
    //         std::cout<<g[i][j]<<" ";
    //     }
    // }
    while(q--) {
        int u, v; std::cin>>u>>v;
        long long ans(1ll<<62);
        for(auto i : to[u]) {
            for(auto j : to[v]) ans=std::min(ans, g[i.second][j.second]+i.first+j.first);
        }
        std::cout<<ans+w[u]+w[v]<<"\n";
    }
    return 0;
}

// 92pts at 51 min