#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,k,d[(int)1e6+5],f[(int)1e6+5][20],ans;
vector<int>q[(int)1e6+5];
void dfs(int x,int fa){
    d[x]=d[fa]+1;
    f[x][0]=fa;
    for(int i = 1;i<20;i++){
        f[x][i] = f[f[x][i-1]][i-1];
    }
    for(int y:q[x]){
        if(y==fa) continue;
        dfs(y,x);
    }
}
int lca(int x,int y){
    if(d[x]<d[y]) swap(x,y);
    for(int i = 19;i>=0;i--){
        if(d[f[x][i]]>=d[y]) x=f[x][i];
    }
    if(x==y) return x;
    for(int i = 19;i>=0;i--){
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}

bool t[(int)1e6+5];
pair<int,int>e[(int)1e6+5];
int fa[(int)1e6+5];
int findset(int x){
    if(fa[x]==x) return x;
    return fa[x] = findset(fa[x]);
}
void merge(int x,int y){
    x = findset(x);
    y = findset(y);
    fa[x]=y;
}
void check(){
    for(int i =1 ;i<=n;i++) fa[i]=i;
    for(int i = 1;i<n;i++){
        if(t[e[i].first]&&t[e[i].second]){
            merge(e[i].first,e[i].second);
        }
    }
    set<int>mo;
    for(int i = 1;i<=n;i++){
        mo.insert(findset(i));
    }
    if(mo.size()==n-k+2){
        int res = 0;
        for(int i = 1;i<=n;i++){
            if(!t[i]){
                int r = 1e18;
                for(int j = 1;j<=n;j++){
                    if(t[j])r = min(r,d[i]+d[j]-2*d[lca(i,j)]);
                }
                res = max(res,r);
            }
        }
        ans = min(ans,res);
    }
}
void dfs1(int pos,int kk){
    if(pos>n){
        if(!kk)check();
        return;
    }
    if(kk){
        t[pos]=1;
        dfs1(pos+1,kk-1);
        t[pos]=0;
    }
    dfs1(pos+1,kk);
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1;i<=n;i++) {q[i].clear(),d[i]=0; for(int j= 0;j<20;j++)f[i][j]=0;}
        for(int i = 1;i<n;i++){
            int u,v;
            cin >>u >> v;
            q[u].push_back(v);
            q[v].push_back(u);
            e[i]={u,v};
        }
        dfs(1,0);
        ans=1e18;
        if(n==k) ans=0;
        dfs1(1,k);
        cout << ans << '\n';
    }
    return 0;
}
