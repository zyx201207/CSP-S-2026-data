#include<bits/stdc++.h>
using namespace std;

int dis[15];
bitset<15> vis;
vector<int> g[15];
int n,k;
int ans;

void bfs(int cur){
    bitset<15> vis1=0;
    queue<pair<int,int> > q;
    q.push({cur,0});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        if(vis1[temp.first])continue;
        vis1[temp.first]=1;
        dis[temp.first]=min(temp.second,dis[temp.first]);
        for(auto i:g[temp.first]){
            q.push({i,temp.second+1});
        }
    }
}

void check(){
    int ans_=-INT_MAX;
    for(int i=1;i<=n;i++){
        dis[i]=INT_MAX;
    }
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    for(int i=1;i<=n;i++){
        ans_=max(dis[i],ans_);
    }
    ans=min(ans,ans_);
}

void dfs(int step,int choose){
    if(step==n+1){
        if(choose==k)check();
        return;
    }
    dfs(step+1,choose);
    vis[step]=1;
    dfs(step+1,choose+1);
    vis[step]=0;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<n;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1,0);
        cout << ans << '\n';

        for(int i=0;i<=n;i++){
            g[i].clear();
        }
        vis=0;
        ans=INT_MAX;
    }
    return 0;
}
