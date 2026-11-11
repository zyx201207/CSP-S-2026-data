#include <bits/stdc++.h>
using namespace std;
const int nn=10005;
int cs,tes,n,k,vis[nn],sum,gs[nn];
vector<int>g[nn];
void dfs(int x,int fa,int vs){
    if(vis[x]){
        sum=min(sum,vs);
        return;
    }
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i];
        if(v==fa)continue;
        dfs(v,x,vs+1);
    }
}
void bfs(int x,int fa){
    gs[x]=1;
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i];
        if(v==fa || vis[v]==0)continue;
        bfs(v,x);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>cs>>tes;
    while(tes--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(cs<=3){
            int ans=1e9,cnt=0;
            for(int mk=0;mk<(1<<n);mk++){
                int is=0;
                for(int j=0;j<n;j++){
                    if((mk&(1<<j)))is++;
                }
                if(is!=k)continue;
                for(int i=1;i<=n;i++)vis[i]=0;
                for(int j=0;j<n;j++){
                    if((mk&(1<<j)))vis[j+1]=1;
                }
                int tot=0;
                for(int i=1;i<=n;i++)gs[i]=0;
                for(int i=1;i<=n;i++){
                    if(vis[i] && gs[i]==0)bfs(i,0),tot++;
                }
                if(tot>2)continue;
                cnt=0;
                for(int i=1;i<=n;i++){
                    sum=1e9;
                    dfs(i,0,0);
                    cnt=max(cnt,sum);
                }
                //cout<<"is\n";
                //for(int i=1;i<=n;i++){
                //    if(vis[i]==1)cout<<i<<" ";
                //}
                //cout<<cnt<<'\n';
                ans=min(ans,cnt);
            }
            cout<<ans<<'\n';
        }

    }
    return 0;
}
