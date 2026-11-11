#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;int ans;
int vis[15],flg[15];
int dis[15][15];
vector<int> node[15];
void dfs1(int u,int fa){
    flg[u]=1;
    for(int v:node[u]){
        if(v==fa) continue;
        if(!vis[v]) continue;
        dfs1(v,u);
    }
}
void dfs(int now){
    if(now>k){
        memset(flg,0,sizeof flg);
        int sz=0;
        for(int i=1;i<=n;i++){
            if(!flg[i]&&vis[i]){
                dfs1(i,0);
                sz++;
            }
            if(sz>2) return ;
        }
        vector<int> aa;
        for(int i=1;i<=n;i++)
            if(vis[i])
                aa.push_back(i);
        int rr=0;
        for(int i=1;i<=n;i++){
            int res=100000000;
            for(int v=1;v<=n;v++){
                if(!vis[v]) continue;
                if(v==i) res=0;
                res=min(res,dis[i][v]);
                res=min(res,dis[v][i]);
            }
            rr=max(rr,res);
        }
        ans=min(ans,rr);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(now+1);
            vis[i]=0;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            node[i].clear();
        memset(dis,0x3f,sizeof dis); 
        for(int i=1;i<=n;i++)
               dis[i][i]=0;
               
            
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            node[u].push_back(v);
            node[v].push_back(u);
            dis[u][v]=dis[v][u]=1;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            
                }
        ans=1000000000;
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}