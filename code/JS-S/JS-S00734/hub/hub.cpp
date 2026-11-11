#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int c,t;
int n,k;
int u,v,tot;
int ver[N<<1],nxt[N<<1],head[N];
int depth[N],son[N],fa[N],siz[N];
int rnk[N],dfn[N],top[N];
int cnt;
int ans;
void dfs1(int u,int f){
    son[u] = -1;
    siz[u] = 1;
    int ma = 0;
    for(int i = head[u];i;i=nxt[i]){
        int v = ver[i];
        if(v==f) continue;
        depth[v] = depth[u]+1;
        fa[v] = u;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>ma){
            ma = siz[v];
            son[u] = v;
        }
    }
}
void dfs2(int u,int t){
    top[u] = t;
    dfn[u] = ++cnt;
    rnk[cnt] = u;
    if(son[u]==-1) return ;
    dfs2(son[u],t);
    for(int i = head[u];i;i=nxt[i]){
        int v = ver[i];
        if(v==son[u]||v==fa[u]) continue;
        dfs2(v,v);
    }
}
void add(int u,int v){
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
int a[15];
bool vis[15];
int col[15];
void dfs(int u,int w){
    col[u] = w;
    for(int i = head[u];i;i=nxt[i]){
        int v = ver[i];
        if(col[v]) continue;
        dfs(v,w);
    }
}
bool check(){
    memset(col,0,sizeof col);
    int cnt1 = 0;
    for(int i = 1;i<=k;i++){
        if(!col[a[i]]){
            cnt1++;
            dfs(a[i],cnt1);
        }
    }
    if(cnt1>2) return 0;
    else return 1;
}
int LCA(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    while(depth[u]>depth[v]){
        u = fa[u];
    }
    while(u!=v){
        u = fa[u],v = fa[v];
    }
    return u;
}
void dg(int x){
    if(x==k+1){
        if(check()){
            int ma = 0;
            for(int i = 1;i<=n;i++){
                if(vis[i]) continue;
                int mi = 1e9+10;
                for(int j = 1;j<=k;j++){
                    int f = LCA(a[j],i);
                    //cout << a[j] << " " << i << " " << f << "\n";
                    mi = min(mi,abs(depth[a[j]]+depth[i]-depth[f]*2));
                }
                ma = max(ma,mi);
            }
            ans = min(ans,ma);
        }
    }else{
        for(int i = 1;i<=n;i++){
            if(vis[i]) continue;
            a[x] = i;
            vis[i] = 1;
            dg(x+1);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        cnt = tot = 0;
        memset(head,0,sizeof head);
        memset(rnk,0,sizeof rnk);
        memset(dfn,0,sizeof dfn);
        memset(depth,0,sizeof depth);
        memset(siz,0,sizeof siz);
        memset(fa,0,sizeof fa);
        memset(son,0,sizeof son);
        memset(top,0,sizeof top);
        for(int i = 1;i<n;i++){
            cin >> u >> v;
            add(u,v);
            add(v,u);
        }
        //cout << 1;
        dfs1(1,0);
        //cout << 1;
        dfs2(1,1);
        ans = 1e9+10;
        //cout << 1;
        dg(1);
        cout << ans << "\n";
    }
}