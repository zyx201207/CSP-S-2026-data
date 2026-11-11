#include <bits/stdc++.h>
using namespace std;
vector <int> g[15];
int c,T;
bool is[15],vis[15];
void dfs(int u){
    vis[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v]&&is[v]){
            dfs(v);
        }
    }
}
int dist[15];
queue <pair<int,int> > q,q1;
void bfs(int s){
    q=q1;
    q.push(make_pair(s,0));
    while(!q.empty()){
        pair <int,int> tmp=q.front();
        q.pop();
        int u=tmp.first,w=tmp.second;
        if(is[u]){
            dist[s]=w;
            return;
        }
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            q.push(make_pair(v,w+1));
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans=2e9;
        for(int s=0;s<(1<<n);s++){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(s&(1<<(i-1))){
                    cnt++;
                }
            }
            if(cnt!=k){
                continue;
            }
            for(int i=1;i<=n;i++){
                is[i]=vis[i]=0;
                if(s&(1<<(i-1))){
                    is[i]=1;
                }
            }
            cnt=0;
            for(int i=1;i<=n;i++){
                if(is[i]&&!vis[i]){
                    dfs(i);
                    cnt++;
                }
            }
            if(cnt>2){
                continue;
            }
            int maxn=0;
            for(int i=1;i<=n;i++){
                if(is[i]){
                    dist[i]=0;
                }
                bfs(i);
                maxn=max(dist[i],maxn);
            }
            ans=min(maxn,ans);
        }
        cout<<ans<<"\n";
    }

    return 0;
}
