#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[N];
long long G[N][N];
long long dis[N][N];
vector<pair<int,int> > e[M];
void dijkstra(int x){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;
    int vis[N]={};
    que.push({0,x});
    while(!que.empty()){
        int u=que.top().second,dd=que.top().first;
        que.pop();
        if(vis[u]==1) continue;
        vis[u]=1;
        for(int i=1;i<=n;i++){
            if(u==i||vis[i]) continue;
            if(G[u][i]==0) continue;
            if(dis[x][i]>dd+G[u][i]||dis[x][i]==0){
                dis[x][i]=dd+G[u][i];
                que.push({dis[x][i],i});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        for(int j=1;j<=t;j++){
            int a,b;
            cin>>a>>b;
            e[a].push_back({i,b});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j:e[i]){
            for(auto k:e[i]){
                if(j.first==k.first) continue;
                if(G[j.first][k.first]==0||G[j.first][k.first]>j.second+k.second) G[j.first][k.first]=j.second+k.second;
            }
        }
    }

    for(int i=1;i<=n;i++){
        dijkstra(i);
    }

    while(q--){
        int x,y;
        long long minn=-1;
        cin>>x>>y;
        for(auto j:e[x]){
            for(auto k:e[y]){
                if(minn==-1||minn>dis[j.first][k.first]+j.second+k.second+w[x]+w[y]) minn=dis[j.first][k.first]+j.second+k.second+w[x]+w[y];
            }
        }
        cout<<minn<<'\n';
    }
    return 0;
}
