#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int csd,T;
int n,k;
vector<int>g[N];
bool jd[N];
int ans;
bool vis[N];
int dis[N];
void co(int u){
    vis[u]=1;
    for(int i=0;i<(int)g[u].size();i++){
        int v=g[u][i];
        if(!vis[v] && jd[v])co(v);
    }
    return;
}
void bfs(){
    queue<int>q;
    for(int i=1;i<=n;i++)if(jd[i])q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<(int)g[u].size();i++){
            int v=g[u][i];
            if(dis[v]<=dis[u]+1)continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    return;
}
int check(){
    for(int i=1;i<=n;i++)vis[i]=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i] && jd[i]){
            cnt++;
            co(i);
        }
    }
    if(cnt>2)return 1e9;
    for(int i=1;i<=n;i++){
        if(jd[i])dis[i]=0;
        else dis[i]=1e9;
    }
    bfs();
    int maxn=0;
    for(int i=1;i<=n;i++)maxn=max(maxn,dis[i]);
    return maxn;
}
void dfs(int u,int now){
    if(n-u+1<now || now<0)return;
    if(u>n){
        ans=min(ans,check());
        return;
    }
    dfs(u+1,now);
    jd[u]=1;
    dfs(u+1,now-1);
    jd[u]=0;
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>csd>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=1e9;
        dfs(1,k);
        cout<<ans<<"\n";
    }
    return 0;
}