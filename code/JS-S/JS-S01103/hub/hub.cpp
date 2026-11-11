#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 307, Inf = 1e18;
ll c, T, n, k;
ll vis[N];
vector<int> e[N];

void dfs(int u, int fa){
    vis[u] = 1;
    for(auto v : e[u]){
        if(v != fa && vis[v] == 0) dfs(v, u);
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) e[i].clear();
        for(int i = 1, u, v; i < n; i++){
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ll mx = n;
        for(int msk = 0; msk < (1<<n); msk++){
            ll cnt = 0;
            for(int i = 0; i < n; i++){
                if((msk>>i)&1) cnt++;
            }
            if(cnt != k) continue;
            for(int i = 1; i <= n; i++) vis[i] = -1;
            for(int i = 0; i < n; i++){
                if((msk>>i)&1) vis[i+1] = 0;
            }
            cnt = 0;
            for(int i = 1; i <= n; i++){
                if(vis[i] == 0){
                    dfs(i, 0);
                    cnt++;
                }
            }
            if(cnt > 2) continue;
            queue<ll> q;
            for(int i = 1; i <= n; i++){
                if(vis[i] == 1) q.push(i);
            }
            ll ans = 0;
            while(!q.empty()){
                ll u = q.front(); q.pop();
                ans = max(ans, vis[u]-1);
                for(auto v : e[u]){
                    if(vis[v] == -1){
                        vis[v] = vis[u]+1;
                        q.push(v);
                    }
                }
            }
            mx = min(mx, ans);
            /*
            for(int i = 1; i <= n; i++){
                if(vis[i] == 1) cout << i << " ";
            }
            cout << endl;
            cout << ans << endl;
            */
        }
        cout << mx << endl;
    }
    return 0;
}
