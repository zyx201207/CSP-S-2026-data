#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU{
    int n;
    vector<int> fa;

    DSU(int _n) : n(_n){
        fa.resize(n + 1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x,int y){
        int rx = find(x),ry = find(y);
        if(rx == ry) return;
        fa[rx] = ry;
    }
};

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int _c,_t;
    cin>>_c>>_t;
    while(_t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> G(n + 1);
        for(int i = 1;i <= n - 1;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
            // cout<<n<<' '<<u<<' '<<v<<'\n';
        }
        vector<int> col(n + 1);
        int res = INT_MAX;
        auto f = [&](auto &&self,int u,int d,int fa) -> void {
            for(auto v : G[u]){
                if(v == fa) continue;
                if(col[v]){
                    res = min(res,d + 1);
                    break;
                    self(self,v,d + 1,u);
                }
            }
        };
        int ans = INT_MAX / 2;
        auto dfs = [&](auto &&self,int now,int cnt) -> void {
            if(now == n + 1){
                int tmp = 0;
                if(cnt != k) return;
                int sz = 0;
                vector<int> vis(n + 1);
                DSU dsu(n);
                for(int i = 1;i <= n;i++){
                    if(col[i]){
                        for(auto v : G[i]){
                            if(!col[v]) continue;
                            dsu.merge(i,v);
                        }
                    }
                }
                for(int i = 1;i <= n;i++){
                    if(col[i]){
                        if(!vis[dsu.find(i)]){
                            sz++;
                            vis[dsu.find(i)] = 1;
                        }
                    }
                }
                if(sz > 2) return;
                for(int i = 1;i <= n;i++){
                    res = INT_MAX / 2;
                    f(f,i,0,-1);
                    tmp = max(tmp,res);
                }
                ans = min(ans,tmp);
            }
            col[now] = 1;
            self(self,now + 1,cnt + 1);
            col[now] = 0;
            self(self,now + 1,cnt);
        };
        dfs(dfs,1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
// g++ hub.cpp -o hub -std=c++14

/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/