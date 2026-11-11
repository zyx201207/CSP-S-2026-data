#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,T;
const int N=2e4+10;
int w[N];
struct node{
    int y,val;
    bool friend operator <(node a,node b){
        return a.val>b.val;
    }
};
priority_queue<node>q;
vector<node>g[N];
int s,t;
int dis[N],vis[N];
priority_queue<node>q1;
int dis1[N],vis1[N];
int mp[N];
void dfs(){
    for(int i=1;i<=m;i++)dis[i]=1e9;
    q.push({s,0});
    dis[s]=0;
    while(!q.empty()){
        node ne=q.top();
        q.pop();
        if(vis[ne.y])continue;
        vis[ne.y]=1;
        for(int i=0;i<g[ne.y].size();i++){
            if(dis[i]>dis[ne.y]+g[ne.y][i].val){
                dis[i]=dis[ne.y]+g[ne.y][i].val;
                q.push({i,dis[i]});
                mp[ne.y]=1;
                mp[i]=0;
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>T;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,v;
            cin>>u>>v;
            g[i].push_back({u,v});
            g[u].push_back({i,v});
        }
    }
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        while(!q.empty())q.pop();
        while(!q1.empty())q1.pop();
        cin>>s>>t;
        dfs();
        mp[t]=0;
        int mx=0;

        cout<<w[s]+w[t]+dis[t]+g[s][s].val<<"\n";
    }
    return 0;
}
