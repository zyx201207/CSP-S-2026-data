#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using ll=long long;

struct {
    int to;
    ll w;
    int nxt;
} edges[(int)3e5+10];

int head[305], tot;

void add(int u, int v, ll w) {
    edges[++tot]={v, w, head[u]};
    head[u]=tot;
}

int n; ll d;

ll x[305];

ll dis[305], cnt[305];
bool vis[305];

#include <queue>

void Dijkstra(int start) {
    std::memset(dis, 0x7f, sizeof dis);
    std::memset(vis, 0, sizeof vis);
    std::memset(cnt, 0, sizeof cnt);
    dis[start]=0;
    std::priority_queue<
        std::pair<
            ll
        , int>
    > q;
    q.push({0, start});
    cnt[start]=1;
    while(!q.empty()) {
        int u=q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int v, i=head[u]; i; i=edges[i].nxt) {
            v=edges[i].to;
            if(dis[v] > dis[u]+edges[i].w) {
                dis[v]=dis[u]+edges[i].w;
                cnt[v]=cnt[u];
                q.push({-dis[v], v});
            }else if(dis[v]==dis[u]+edges[i].w) cnt[v] += cnt[u];
        }
    }
}

std::vector<ll> wwwans[15];

bool vvis[14];

void dfs(int u, ll w) {
    wwwans[u].push_back(w);
    vvis[u]=true;
    for(int v, i=head[u]; i; i=edges[i].nxt) {
        v=edges[i].to;
        if(!vvis[v]) dfs(v, w+edges[i].w);
    }
    vvis[u]=false;
}

ll solve() {
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) 
            if(std::abs(x[i]-x[j]) <= d && i != j) add(i, j, 1);
    ll ans=0;
    if(true) {
        for(int i=1; i<=n; i++) {
            Dijkstra(i);
            for(int j=1; j<=n; j++) if(cnt[j]==2) ++ans;
            // std::cerr << "\ni=" << i << '\n';
            // for(int j=1; j<=n; j++) std::cerr << cnt[j] << ' ';
            // std::cerr << '\n';
        }
    }else {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) wwwans[j].clear();
            dfs(i, 0);
            for(int j=1; j<=n; j++) {
                std::sort(
                    wwwans[j].begin(), wwwans[j].end()
                );
                if(wwwans[j].size() >= 2 && wwwans[j][0]==wwwans[j][1] && (wwwans[j].size()==2 || wwwans[j][0] != wwwans[j][2])) ++ans;
            }
            // std::cerr << "\n\ni=" << i << '\n';
            // for(int j=1; j<=n; j++) {
            //     std::cerr << j << ": ";
            //     for(ll c : wwwans[j]) std::cerr << c << ' ';
            //     std::cerr << '\n';
            // }
            // std::cerr << '\n';
        }
    }
    return ans>>1;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t, c; std::cin >> c >> t;
    while(t--) {
        std::cin >> n >> d;
        for(int i=1; i<=n; i++) std::cin >> x[i];
        tot=0;
        std::memset(head, 0, sizeof(head));
        std::cout << solve() << '\n';
    }
}

/*
i=1
1: 0 
2: 1 3 5 
3: 2 2 4 
4: 3 3 3 5 

i=2
1: 1 3 5 
2: 0 
3: 1 3 3 
4: 2 2 4 

i=3
1: 2 2 4 
2: 1 3 3 
3: 0 
4: 1 3 5 

i=4
1: 3 3 3 5 
2: 2 2 4 
3: 1 3 5 
4: 0 
*/
