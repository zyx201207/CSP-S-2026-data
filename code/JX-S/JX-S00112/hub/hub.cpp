#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,inf=0x3f3f3f3f,M=1e3+10;
int c,T,n,k,fa[N],dis[M][M],ans;
bool used[N];
vector<int> G[N];
int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
bool vis[N];
void solve(){
    for(int i=1;i<=n;i++) vis[i]=false,fa[i]=i;
    for(int i=1;i<=n;i++){
        if(used[i]){
            for(auto ne:G[i]){
                if(used[ne]){
                    int faa=find(i),fab=find(ne);
                    if(faa!=fab) fa[faa]=fab;
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(used[i]){
            int faa=find(i);
            if(!vis[faa]) vis[faa]=true,cnt++;
        }
    }
    if(cnt>2) return ;
    int maxx=0;
    for(int i=1;i<=n;i++){
        if(used[i]) continue;
        int minn=inf;
        for(int j=1;j<=n;j++){
            if(used[j]){
                minn=min(minn,dis[i][j]);
            }
        }
        maxx=max(maxx,minn);
    }
    ans=min(ans,maxx);
}
void dfs(int step){
    if(step==k+1){
        solve();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=true;
            dfs(step+1);
            used[i]=false;
        }
    }
}
void init(int u,int fa,int root){
    if(root==u) dis[u][u]=0;
    else dis[root][u]=dis[root][fa]+1;
    for(auto ne:G[u]) if(ne!=fa){
        init(ne,u,root);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
       cin>>n>>k;
       for(int i=1;i<=n;i++){
            G[i].clear();
            for(int j=1;j<=n;j++){
                dis[i][j]=inf;
            }
       }
       for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
       }
       for(int i=1;i<=n;i++){
            dis[i][i]=0;
            init(i,0,i);
       }
       ans=inf;
       dfs(1);
       cout<<ans<<'\n';
    }
    return 0;
}
