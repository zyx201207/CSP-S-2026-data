#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,k,fn,floyd[15][15];
bool have[15],vis[15];
void dfs2(int now,const vector<vector<int> >adj){
    if(vis[now] || !have[now])return;
    vis[now]=1;
    for(auto i:adj[now]){
        dfs2(i,adj);
    }
}
void check(const vector<vector<int> >adj){
    int cnt=0;
    for(int i=1;i<=n;i++)cnt+=have[i];
    if(cnt!=k)return;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++)if(have[j] && !vis[j]){dfs2(j,adj);break;}
    }
    for(int i=1;i<=n;i++)if(have[i] && !vis[i])return;
    int ans=0;
    for(int i=1;i<=n;i++){
        int sum=0x3f3f3f3f;
        for(int j=1;j<=n;j++){
            if(have[j])sum=min(sum,floyd[i][j]);
        }
        ans=max(ans,sum);
    }
    fn=min(fn,ans);
}
void dfs(int now,const vector<vector<int> >adj){
    if(now>n){
        for(int i=1;i<=n;i++)vis[i]=0;
        check(adj);
        return;
    }
    have[now]=0;
    dfs(now+1,adj);
    have[now]=1;
    dfs(now+1,adj);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;fn=0x3f3f3f3f;
        for(int i=1;i<=n;i++)have[i]=vis[i]=0;
        vector<vector<int> >adj;adj.resize(n+1);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)floyd[i][j]=0x3f3f3f3f*(i!=j);
        for(int i=1;i<=n;i++)for(auto j:adj[i])floyd[i][j]=floyd[j][i]=1;
        for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
        dfs(1,adj);
        cout<<fn<<"\n";
    }
    return 0;
}
