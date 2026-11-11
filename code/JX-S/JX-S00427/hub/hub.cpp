#include<bits/stdc++.h>
using namespace std;
const int N=103,inf=1e9;
int c,t,n,k,u,v,res;
bool a[N][N];
vector<int> g[N];
int sz[N],fa[N],dep[N],wc[N];
void dfs(int u,int f){
    sz[u]=1;
    fa[u]=f;
    dep[u]=dep[f]+1;
    wc[u]=0;
    for(int y:g[u]){
        if(y==f)continue;
        dfs(y,u);
        if(sz[wc[u]]<sz[y])wc[u]=y;
        sz[u]+=sz[y];
    }
}
int top[N];
void dfs1(int u,int f,int to){
    top[u]=to;
    if(wc[u])dfs1(wc[u],u,to);
    for(int y:g[u]){
        if(y==f||y==wc[u])continue;
        dfs1(y,u,y);
    }
}
int lca(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]])swap(a,b);
        a=fa[top[a]];
    }
    return dep[a]<dep[b]?a:b;
}
int dist(int a,int b){
    int LCA=lca(a,b);
    return dep[a]+dep[b]-2*dep[LCA];
}
int s[N];
bool flg[N];
int d(int i){
    int res=inf;
    for(int j=1;j<=k;j++)res=min(res,dist(i,s[j]));
    return res;
}
int fat[N],siz[N];
int get(int x){
    if(x==fat[x])return x;
    return fat[x]=get(fat[x]);
}
void merge(int x,int y){
    x=get(x),y=get(y);
    if(x==y)return ;
    if(siz[x]>siz[y])swap(x,y);
    fat[x]=y;
    siz[y]+=siz[x];
}
bool chk(){
    for(int i=1;i<=k;i++)fat[s[i]]=s[i],siz[s[i]]=1;
    for(int i=1;i<=k;i++){
        for(int j=i+1;j<=k;j++){
            if(a[s[i]][s[j]])merge(s[i],s[j]);
        }
    }
    int tmp=0;
    for(int i=1;i<=k;i++){
        if(s[i]==get(s[i]))tmp++;
    }
    return tmp<=2;
}
void solve(int e){
    if(e>k){
        if(!chk())return ;
        int tmp=0;
        for(int i=1;i<=n;i++)tmp=max(tmp,d(i));
        res=min(res,tmp);
    }
    else{
        for(int i=1;i<=n;i++){
            if(!flg[i]){
                flg[i]=1;
                s[e]=i;
                solve(e+1);
                flg[i]=0;
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].clear();
            for(int j=1;j<=n;j++)a[i][j]=0;
        }
        for(int i=1;i<n;i++){
            cin>>u>>v;
            a[u][v]=a[v][u]=1;
            g[u].push_back(v),g[v].push_back(u);
        }
        dfs(1,0);
        dfs1(1,0,1);
        res=inf;
        for(int i=1;i<=n;i++)flg[i]=0;
        solve(1);
        cout<<res<<"\n";
    }
    return 0;
}