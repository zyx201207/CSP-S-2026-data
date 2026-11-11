#include <bits/stdc++.h>
#define il inline
#define rg register
#define int ll
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
namespace XXI{
    const int maxn = 1e6+50;
    const char endl = '\n';
    vector<int> mp[maxn];
    int c,t;
    int dep[maxn];
    int f[maxn][22];
    il void dfs(int u,int fa){
        dep[u] = dep[fa]+1;
        f[u][0] = fa;
        for(int i = 1;i<=20;i++){
            f[u][i] = f[f[u][i-1]][i-1];
        }
        for(int v : mp[u]){
            if(v == fa) continue;
            dfs(v,u);
        }
    }
    il int lca(int u,int v){
        if(dep[u]<dep[v]) swap(u,v);
        for(int i = 20;i>=0;i--){
            if(dep[f[u][i]]<=dep[v]) u = f[u][i];
        }
        if(u == v) return u;
        for(int i = 20;i>=0;i--){
            if(f[u][i]!=f[v][i]){
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    }
    il int dis(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
    int n,k;
    int choose[maxn];
    int ans;
    int d[maxn];
    il void chkans(){
        int res = 0;
        for(int i = 1;i<=n;i++){
            d[i] = 0x7f7f7f7f;
            for(int j = 1;j<=k;j++){
                d[i] = min(d[i],dis(i,choose[j]));
            }
            res = max(res,d[i]);
        }
        ans = min(ans,res);
    }
    /*il void calc(int now,int chosen){
        if(chosen == k){
            if(choose[1] == 2)
            chkans();
            return ;
        }
        if(now>n) return ;
        calc(now+1,chosen);
        choose[chosen+1] = now;
        calc(now+1,chosen+1);
        choose[chosen+1] = 0;
    }*/
    il void work(){
        ans = 0x3f3f3f3f;
        cin >> n >> k;
        for(int i = 1;i<n;i++){
            int u,v;
            cin >> u >> v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        //dfs(1,0);
        //cout << ans << endl;
        cout << (n-1)/(k+1);
    }
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        cin >> c >> t;
        while(t--){
            work();
        }
        return 0;
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    XXI::main();
    return 0;
}
