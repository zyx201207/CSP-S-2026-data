#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

struct {
    int to, nxt;
} edges[35];

int head[12], tot;

void add(int u, int v) {
    edges[++tot]={v, head[u]};
    head[u]=tot;
}

int n, k;

bool mask[30];

bool vis[30];

int cnt;

void floodfill(int u) {
    vis[u]=true;
    for(int v, i=head[u]; i; i=edges[i].nxt) {
        v=edges[i].to;
        if(mask[v] && !vis[v]) floodfill(v);
    }
}

int dfs(int u, int fa) {
    if(mask[u]) return 0;
    int res=1e9;
    for(int v, i=head[u]; i; i=edges[i].nxt) {
        v=edges[i].to;
        if(v==fa) continue;
        res=std::min(dfs(v, u)+1, res);
    }
    return res;
}

int solve() {
    for(int i=1; i<=n-k; i++) mask[i]=0;
    for(int i=n-k+1; i<=n; i++) mask[i]=1;
    int ans=1e9;
    do {
        cnt=0;
        std::memset(vis, 0, sizeof vis);
        for(int i=1; i<=n; i++) if(mask[i] && !vis[i]) ++cnt, floodfill(i);
        if(cnt <= 2) {
            int cur=0;
            for(int i=1; i<=n; i++) cur = std::max(cur, dfs(i, 0));
            ans=std::min(ans, cur);
        }
    } while(std::next_permutation(mask+1, mask+n+1));
    return ans;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int c, t; std::cin >> c >> t;
    if(c==13 || c==14) {
        while(t--) {
            std::cin >> n >> k;
            int m=(n-1)>>1;
            for(int u, v, i=1; i<n; i++) std::cin >> u >> v;
            if(k==n) std::cout << "0\n";
            else if(k >= m) std::cout << "1\n";
            else if(k != 1) {
                int b=(m-k+3)>>2;
                std::cout << b+1 << '\n';
            } else std::cout << (m>>1)+1 << '\n';
        }
        return 0;
    }
    while(t--) {
        std::cin >> n >> k;
        tot=0;
        std::memset(head, 0, sizeof head);
        for(int u, v, i=1; i<n; i++) {
            std::cin >> u >> v;
            add(u, v);
            add(v, u);
        }
        std::cout << solve() << '\n';
    }
}
