#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
vector<int> g[200005];
int a[200005],dis[200005];
bool vis[200005];
int bfs(int s,int t){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(s);
    vis[s] = 1;dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            if(!vis[v]){
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return (dis[t] == 0x3f3f3f3f ? -1 : dis[t]);
}
set<vector<int> > _s;
vector<int> path;
void dfs(int s,int t,int dep,int maxd){
    //memset(vis,0,sizeof vis);
    if(dep > maxd)return;
    if(s == t){
        _s.insert(path);
        return;
    }
    for(int v : g[s]){
        path.push_back(v);
        dfs(v,t,dep+1,maxd);
        path.pop_back();
    }
}
void do_something(){
    cin >> n >> d;
    _s.clear();
    for(int i=1;i<=200005;i++)g[i].clear();
    for(int i=1;i<=n;i++){
        cin >> a[i];
        for(int j=1;j<=i;j++){
            if(abs(a[i] - a[j]) <= d){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    long long al = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int d_ = bfs(i,j);
            memset(vis,0,sizeof vis);
            dfs(i,j,0,d_);
            al += (_s.size() == 2);
        }
    }
    cout << al;
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t --)do_something();
}