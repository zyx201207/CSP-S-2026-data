#include<bits/stdc++.h>
using namespace std;
int n,c,k,t,ans,dis[15][15];
vector<int>v[15];
bool vis[15],flg[15];
void bfs(int s){
    memset(dis[s],0x3f,sizeof dis[s]);
    queue<int>q;q.push(s);dis[s][s]=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto son:v[x])
        if(dis[s][son]>dis[s][x]+1)dis[s][son]=dis[s][x]+1,q.push(son);
    }
    return;
}
void dfs(int x){
    vis[x]=0;
    for(auto son:v[x])
    if(vis[son])dfs(son);
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k,ans=n-1;
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<n;i++){
            int x,y;cin>>x>>y;
            v[x].push_back(y);v[y].push_back(x);
        }
        for(int i=1;i<=n;i++)bfs(i);
        for(int s=0;s<(1<<n);s++){
            int cnt=0;
            for(int j=1;j<=n;j++)
            if((s>>(j-1))&1)cnt++,flg[j]=vis[j]=1;
            else flg[j]=vis[j]=0;
            if(cnt!=k)continue;cnt=0;
            for(int i=1;i<=n;i++)
            if(vis[i])dfs(i),cnt++;
            if(cnt>2)continue;
            int ret=0;
            for(int i=1;i<=n;i++){
                int res=n+1;
                for(int j=1;j<=n;j++)
                if(flg[j])res=min(res,dis[i][j]);
                ret=max(ret,res);
            }
            ans=min(ans,ret);
        }
        cout<<ans<<'\n';
    }
    return 0;
}