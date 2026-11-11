#define NDEBUG
#include<bits/stdc++.h>
#ifdef NDEBUG
#define print(...) void()
#else
#define print(...) void(fprintf(stderr, __VA_ARGS__))
#endif
#define up(i,l,r) for (int i=l; i<=r; ++i)
#define dn(i,r,l) for (int i=r; i>=l; --i)
using ll = long long; using namespace std;
namespace solve1{
    const int N = 2e6+5;
    int n, K; bool ch[N], vis[N];int dis[N];
    vector<int> G[N];
    void dfs(int u){
        vis[u]=1;
        for (auto v: G[u]) if (!vis[v]) dfs(v);
    }
    int ans;
    void check(){
        up (i, 1, n) vis[i]=!ch[i];
        print("check:");
        up (i, 1, n) if (ch[i]) print(" %d", i);
        print("\n");
        int cnt=0;
        up (i, 1, n) if (!vis[i]) ++cnt, dfs(i);
        if (cnt>2) return;
        up (i, 1, n) dis[i]=n+1;
        static int head, tail, q[N];
        head=0,tail=0;
        up (i, 1, n) if (ch[i]) dis[i]=0, q[++tail]=i;
        int res=0;
        while (head<tail){
            int u=q[++head]; res=max(res,dis[u]);
            for (auto v: G[u]) if (dis[v]>dis[u]+1) dis[v]=dis[u]+1, q[++tail]=v;
        }
        ans=min(ans,res);
    } 
    void choose(int ix, int k){
        if (k<0||k>n-ix+1) return;
        if (ix>n) return check();
        choose(ix+1,k);
        ch[ix]=1;
        choose(ix+1,k-1);
        ch[ix]=0;
    }
    void work(){
        cin >> n >> K;
        up (i, 1, n) G[i].clear();
        up (i, 2, n){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans=n+1;
        choose(1,K);
        cout << ans << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int C, T;
    cin >> C >> T;
    while (T--){
        /*if (C<=3) */solve1::work();
    }
    return 0;
}