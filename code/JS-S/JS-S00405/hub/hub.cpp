#include <bits/stdc++.h>
using namespace std;
vector<int>v(15);
vector<int>g[35];
int n,k;
int minn=1e9;
bool vis[35];
int dis[35];
bool ccc(int now){
    for(int i=1;i<=k;i++)if(v[i]==now)return 1;
    return 0;
}
void dfs(int now){
    vis[now]=1;
    for(int it:g[now]){
        if(vis[it])continue;
        if(ccc(it)==0)continue;
        dfs(it);
    }
}
bool check(){
    int cnt=0;
    for(int i=1;i<=k;i++){
        if(vis[v[i]]==0){
            cnt++;
            dfs(v[i]);
        }
        if(cnt>2)return 0;
    }
    return 1;
}
void dij(){
    for(int i=1;i<=n;i++)dis[i]=1e9;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    for(int i=1;i<=k;i++){
        dis[v[i]]=0;
        q.push({0,v[i]});
    }
    while(q.size()){
        int now=q.top().second;
        q.pop();
        for(int it:g[now]){
            if(dis[it]<=dis[now]+1)continue;
            dis[it]=dis[now]+1;
            q.push({dis[it],it});
        }
    }
}
void dfs(int now,int x){
    if(x==k){
        memset(vis,0,sizeof(vis));
        if(check()){
            //for(int i=1;i<=k;i++)cout<<v[i]<<" ";
            //cout<<":";
            dij();
            int maxn=0;
            for(int i=1;i<=n;i++)maxn=max(maxn,dis[i]);
            minn=min(minn,maxn);
            //cout<<maxn<<"\n";
        }
        return;
    }
    for(int i=now+1;i<=n;i++){
        v[x+1]=i;
        dfs(i,x+1);
    }
}
void solve(){
    minn=1e9;
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    cin>>n>>k;
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0,0);
    cout<<minn<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
