#include<bits/stdc++.h>
using namespace std;
int w[500003],k[500003],a[503][503],t[503][503];
vector<int> g[500003];
bool vis[500002];
int dis[20003][20004];
void bfs(int start,int di){
    queue<int> q;
    memset(dis,0x3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    q.push(start);
    dis[di][start]=0;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        if(vis[f]) continue;
        for(auto i:g[f]){
            if(dis[di][i]>dis[di][f]+1){
                dis[di][i]=dis[di][f]+1;
                vis[i]=1;
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            cin>>a[i][j]>>t[i][j];
            g[i+m].push_back(a[i][j]);
            g[a[i][j]].push_back(i+m);
        }
    }
    for(int j=1;j<=m;++j){
        bfs(j,j);
    }
    for(int i=1;i<=q;++i){
        int x,y;cin>>x>>y;
        long long ans=0;
        ans+=w[x]+w[y];
        ans+=dis[x][y];
        cout<<ans<<endl;
    }
    return 0;
}
