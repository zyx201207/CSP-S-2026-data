#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
struct st{
    int id,tp;
};
int u,v;
vector<st> g[N];
vector<int> t[N];
int w[N];
int vis[N];
int ans=1e18;
void dfs(int id,int tp,int sum){
    if(id==v){
        ans=min(ans,sum);
        return;
    }
    for(st nxt:g[id]){
        if(vis[nxt.id]) continue;
        vis[nxt.id]=1;
        dfs(nxt.id,nxt.tp,(nxt.tp==tp?sum:sum+(tp==0?0:t[nxt.id][tp-1])+t[nxt.id][nxt.tp-1]));
        vis[nxt.id]=0;
    }
    return;
}
signed main(void){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        int a1;
        cin>>a1;
        int time;
        cin>>time;
        t[a1].push_back(time);
        for(int j=2;j<=k;++j){
            int x;
            cin>>x;
            g[a1].push_back({x,i});
            g[x].push_back({a1,i});
            int ti;
            cin>>ti;
            t[x].push_back(ti);
        }
    }
    while(q--){
        cin>>u>>v;
        dfs(u,0,0);
        cout<<w[u]+w[v]+ans<<'\n';
    }
    return 0;
}
