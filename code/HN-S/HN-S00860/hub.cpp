#include<bits/stdc++.h>
#define i32 signed
#define i64 long long
#define int i64
#define pii pair<int,int>
using namespace std;
const int N=2e6+5;
int T;
int n,k;
vector<int>e[N];
int dfn[N],dcnt=0;
int LCA[25][N];
int D[N];
void dfs(int u,int fa){
    D[u]=D[fa]+1;
    LCA[dfn[u]=++dcnt]=fa;
    for(int v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
}
int get(int u,int v){return dfn[u]<dfn[v]?u:v;}
int Lca(int u,int v){
    if(u==v)return u;
    if((u=dfn[u])>(v=dfn[v]))swap(u,v);
    int lg=__lg(v-u++);
    return get(LCA[lg][u],LCA[lg][v-(1<<lg)+1]);
}
int ans;
vector<int>v;
void dfs2(int nw,int m){
    if(nw==n+1){
        int tmp=0;
        for(int i=1;i<=n;i++){
            int temp=N;
            for(int j:v){
                int lca=Lca(i,j);
                int d=D[lca]-D[i]+D[lca]-D[j]+1;
                temp=min(temp,d);
            }tmp=max(temp,tmp);
        }ans=min(ans,tmp);
    }
    dfs2(nw+1,m);
    if(m<k){
        v.push_back(nw);
        dfs2(nw+1,m+1);
        v.pop_back();
    }
}
i32 main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>T>>T;
    while(T--){
        dcnt=0;
        ans=N;
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }dfs(1,0);
        for(int i=1;i<=20;i++)
            for(int j=1;j<=n-(1<<i)+1;j++)
                LCA[i][j]=get(LCA[i-1][j],LCA[i-1][j+(1<<i-1)]);
        dfs2(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
//15：10