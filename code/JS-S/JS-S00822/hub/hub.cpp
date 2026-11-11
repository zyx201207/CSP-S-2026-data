#include <bits/stdc++.h>

int n, k;

std::vector<int> to[1000+5];

int dis[1000+5][1000+5];

void dfs(int now, int dep, int from) {
    if(dis[from][now]!=-1) return ;
    dis[from][now]=dep;
    for(auto next : to[now]) dfs(next, dep+1, from);
}

int calc(int st) {
    int edge(0);
    for(int i(1); i<=n; i++) {
        for(auto j : to[i]) {
            if((st&(1<<j)) && (st&(1<<i))) edge++;
        }
    }
    if(edge/2<k-2) return 1145141919;
    int max(-1);
    for(int i(1); i<=n; i++) {
        int min(n+1);
        for(int j(1); j<=n; j++) {
            // std::cout<<dis[i][j]<<" ";
            if(st&(1<<j)) min=std::min(min, dis[j][i]);
        }
        max=std::max(max, min);
    }
    return max;
}

void solve() {
    std::cin>>n>>k;
    for(int i(1); i<=n; i++) to[i].clear();
    for(int i(1); i<n; i++) {
        int u, v; std::cin>>u>>v;
        to[u].push_back(v); to[v].push_back(u);
    }
    for(int i(1); i<=n; i++) {
        for(int j(1); j<=n; j++) dis[i][j]=dis[j][i]=-1;
    }
    for(int i(1); i<=n; i++) dfs(i, 0, i);
    if(k==2) {
        int ans(1145141919);
        for(int i(1); i<=n; i++) {
            for(int j(i+1); j<=n; j++) ans=std::min(ans, calc((1<<i)+(1<<j)));
        }
        std::cout<<ans<<"\n";
    } else {
        int ans(1145141919);
        for(int i(0); i<(1<<n); i++) {
            if(__builtin_popcount(i)==k) {
                ans=std::min(ans, calc(i<<1));
            }
        }
        std::cout<<ans<<"\n";
    }
}

int main() {
    std::freopen("hub.in", "r", stdin);
    std::freopen("hub.out", "w", stdout);
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int _; std::cin>>_>>_;
    while(_--) solve();
    return 0;
}

// 10pts at 182 min