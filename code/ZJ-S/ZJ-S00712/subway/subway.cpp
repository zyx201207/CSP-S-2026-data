#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node{
    int nsta;
    ll tim;
    ll nline;
};

ll c, n, m, d, q;
vector<ll> w, k;
vector<ll> g[5005];
ll mp[5005];
ll ti[5005][5005];
bool vis[5005][5005];

ll bfs(int sx, int fx){
    queue<Node> q;
    ll ans = 1e9;
    int sl = mp[sx];
    int z = 1;
    while(sl){
        if(sl % 2){
            q.push({sx, ti[z][sx], z});
            vis[sx][z] = 1;
        }
        z ++;
        sl >> 1;
    }
    while(!q.empty()){
        Node now = q.front();
        q.pop();
        if(now.nsta == fx){
            ans = min(ans, now.tim + ti[now.nline][fx]);
        }
        for(int i : g[now.nsta]){
            int l = mp[i];
            int x = 1;
            while(l){
                if(l % 2 && !vis[i][x]){
                    if(x == now.nline) q.push({i, now.tim, now.nline});
                    else q.push({i, now.tim + ti[now.nline][now.nsta] + ti[x][i], x});
                    vis[i][x] = 1;
                }
                x ++;
                l /= 2;
            }
        }
    }
    return ans;
}

void solve(int x, int y){
    ll ans = w[x] + w[y];
    memset(vis, 0, sizeof(vis));
    ans += bfs(x, y);
    cout << ans << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    w.resize(n + 1);
    k.resize(n + 1);
    for(int i = 1; i <= m; i ++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i ++){
        cin >> k[i];
        vector<ll> s(k[i] + 1);
        s.clear();
        for(int j = 1; j <= k[i]; j ++){
            int t;
            cin >> s[i] >> t;
            ti[i][s[i]] = t;
        }
        for(int u = 1; u <= k[i]; u ++){
            for(int v = u + 1; v <= k[i]; v ++){
                g[s[u]].push_back(s[v]);
                g[s[v]].push_back(s[u]);
                mp[s[u]] ^= (1 << (i - 1));
            }
        }
    }
    for(int i = 1; i <= q; i ++){
        int x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}

