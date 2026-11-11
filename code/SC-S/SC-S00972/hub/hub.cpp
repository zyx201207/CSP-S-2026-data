#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 15;
int c = 0,n,k;
vector<int> ed[N];
namespace subtask1{
    bool check(){
        return (c <= 3);
    }
    int far[N],rk[N];
    int find(int x){
        return x == far[x] ? x : far[x] = find(far[x]);
    }
    void merge(int u,int v){
        int fu = find(u),fv = find(v);
        if(rk[fu] <= rk[fv]) swap(fu,fv);
        far[fv] = fu;rk[fu] += rk[fv];
    }
    void dfs(int u,int fa){
        for(auto x : ed[u]) if(x != fa){
            if(far[x] && far[u]) merge(u,x);
            dfs(x,u);
        }
    }
    int dis[N];
    void dfs1(int u,int fa){
        for(auto x : ed[u]) if(x != fa){
            dis[x] = min(dis[x],dis[u] + 1);
            dfs1(x,u);
        }
    }
    void work(){
        int d = n;
        for(int s = 0;s < (1 << n);s ++){
            fill(rk + 1,rk + 1 + n,1);
            fill(far + 1,far + 1 + n,0);
            fill(dis + 1,dis + 1 + n,n + 1);
            int cnt = 0;
            for(int i = 1;i <= n;i ++) if((s >> (i - 1)) & 1){
                far[i] = i;cnt ++;
            }
            dfs(1,0);
            map<int,int> mp;
            for(int i = 1;i <= n;i ++) if(far[i]){
                mp[find(i)] ++;
            }
            if(mp.size() > 2 || cnt > k) continue;
            for(int i = 1;i <= n;i ++) if(far[i]){
                dis[i] = 0;
                dfs1(i,0);
            }
            int maxn = 0;
            for(int i = 1;i <= n;i ++) maxn = max(maxn,dis[i]);
            // cout << maxn << "\n";
            d = min(d,maxn);
        }
        cout << d << '\n';
    }
}
namespace subtask2{
    bool check(){
        return (c >= 13 && c <= 14);
    }
    void work(){
        if(k == n) return cout << "0\n",void(0);
        int m = (n - 1) / 2;
        int y = (m - 2) % 4;
        int p = (m + 1) / 4 + 1;
        // cout << p << '\n';
        k -= 2;
        if(k >= y){
            k -= y;p --;
        }
        p -= k / 4;
        p = max(p,1);
        cout << p << '\n';
    }
}
namespace subtask3{
    bool check(){
        return (c == 7 || c == 11 || c == 12);
    }
    int root;
    int dep[N],maxn[N],son[N];
    int dis[N],suf[N];
    int pt[N],idx = 0;
    void dfs(int u,int fa){
        dep[u] = dep[fa] + 1;
        maxn[u] = dep[u];son[u] = 0;
        if(dep[u] > dep[root]) root = u;
        for(auto x : ed[u]) if(x != fa){
            dfs(x,u);
            if(maxn[x] > maxn[son[u]])
                son[u] = x;
        }
    }
    void dfs2(int u,int fa){
        maxn[u] = dep[u];
        for(auto x : ed[u]) if(x != fa && x != son[u]){
            dfs2(x,u);
            maxn[u] = max(maxn[x],maxn[u]);
        }
        dis[u] = maxn[u] - dep[u];
        if(son[u]) dfs2(son[u],u);
    }
    void work(){
        idx = 0;
        for(int i = 1;i <= n;i ++) dis[i] = son[i] = 0;
        dfs(root = 1,0);
        dfs(root,0);
        int p = root;
        while(p){
            pt[++ idx] = p;
            p = son[p];
        }
        dfs2(root,0);
        suf[idx] = dis[pt[idx]];
        for(int i = idx - 1;i;i --){
            suf[i] = max(suf[i + 1] + 1,dis[pt[i]]);
        }
        int cnt = 1e9;
        for(int i = 1,s = dis[pt[1]];i <= idx;i ++){
            for(int j = i + 1,c = dis[pt[j]];j <= idx;j ++){
                int d = max({s,c,suf[j + 1]});
                cnt = min(cnt,d);
                c = max(c + 1,dis[pt[j + 1]]);
            }
            s = max(s + 1,dis[pt[i + 1]]);
        }
        cout << cnt << '\n';
    }
}
void solve(){
    cin >> n >> k;
    for(int i = 1;i <= n;i ++)
        ed[i].clear();
    for(int i = 1;i < n;i ++){
        int u,v;cin >> u >> v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    // cout << c << " " << "Tashkent\n";
    if(subtask1::check()) return subtask1::work();
    if(subtask2::check()) return subtask2::work();
    if(subtask3::check()) return subtask3::work();
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;cin >> c >> T;
    while(T --) solve();
    return 0;
}