#include<bits/stdc++.h>
using namespace std;
const int maxN = 1000+10;
int n,k;
vector<int> T[maxN];
int dfn[maxN],idx = 0;
int color[30];
void dfs1(int u){
    dfn[u] = ++idx;
    for(int v:T[u]){
        if(dfn[v]) continue;
        if(!color[v]) continue;
        dfs1(v);
    }
}
int dep[maxN],fa[maxN];
void dfs2(int u,int F){
    fa[u] = F;
    dep[u] = dep[F]+1;
    for(int v:T[u]){
        if(v == F) continue;
        dfs2(v,u);
    }
}
inline int lca1(int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    while(dep[x] > dep[y]) x = fa[x];
    if(x == y) return x;
    while(x != y) x=fa[x],y=fa[y];
    return x;
}
inline void solve1(){
    cin>>n>>k;
    int ans = n;
    for(int i = 1;i < n;i++){
        int u,v;cin>>u>>v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    for(int s = 1;s < (1<<n);s++){
        int tmp = 0;
        for(int i = 1;i <= n;i++){
            if(s&(1<<i-1)) tmp++;
        }
        if(tmp != k) continue;
        for(int i = 1;i <= n;i++){
            color[i] = 0;
            dfn[i] = 0;
        }
        idx = 0;
        for(int i = 1;i <= n;i++){
            if(s&(1<<i-1)) color[i]=1;
        }
        tmp = 0;
        for(int i = 1;i <= n;i++){
            if(color[i] && !dfn[i]){
                dfs1(i);
                tmp++;
            }
        }
        if(tmp > 2) continue;

        int awa = 0;
        dfs2(1,0);
        for(int i = 1;i <= n;i++){
            int d = n;
            for(int j = 1;j <= n;j++){
                if(color[j]){
                    int top = lca1(i,j);
                    d = min(d,dep[i]+dep[j]-2*dep[top]);
                }
            }
            awa = max(awa,d);
        }
        //if(awa == 1) cout<<s<<'\n';

        ans = min(ans,awa);
    }
    cout<<ans<<'\n';
    for(int i = 1;i <= n;i++) T[i].clear();
}
vector<int> G[maxN];
int dis_mx[maxN],now,awa[maxN],cnt;
void dfs3(int u,int F){
    for(int v:G[u]){
        if(v == F) continue;
        dfs3(v,u);
        if(!awa[v]) dis_mx[u] = max(dis_mx[u],dis_mx[v]+1);
    }
    if(dis_mx[u] > now){
        awa[u]=1;cnt++;
        //cout<<u<<' ';
    }
    //cout<<u<<' '<<dis_mx[u]<<'\n';
}
inline bool check(int x){
    now = x;cnt = 0;
    for(int i = 1;i <= n;i++) awa[i]=0;
    int mx1=0,mx2=0;
    dfs3(1,0);
    for(int v:G[1]){
        if(dis_mx[v]+1 >= mx1){
            mx2 = mx1;
            mx1 = dis_mx[v]+1;
        }
        else if(dis_mx[v]+1 > mx2) mx2 = dis_mx[v]+1;
    }
    if(mx1+mx2 > x) cnt++;
    //cout<<x<<' '<<cnt<<' ';
    return cnt <= k;
}
void solve2(){
    cin>>n>>k;
    for(int i = 1;i < n;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int l = 0,r = n;
    while(l < r){
        int mid = l+r>>1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout<<l<<'\n';
    for(int i = 1;i <= n;i++) G[i].clear();
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        if(1 <= c && c <= 3) solve1();
        else solve2();
    }
    return 0;
}
