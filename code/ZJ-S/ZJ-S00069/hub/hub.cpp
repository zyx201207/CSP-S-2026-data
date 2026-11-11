#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
vector<int> g[100005];bool vis[10005];
void dfs(int u,int dep){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v])continue;
        vis[v]=1;
        dfs(v,dep%k);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        scanf("%d %d",&n,&k);
        for(int i=1,x,y;i<=n-1;i++){
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
        }
        cout<<n/(2*k)<<'\n';
    }
    return 0;
}