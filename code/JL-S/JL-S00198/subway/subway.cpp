#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=1010;
int op,n,m,d,q,T,ans=1e18,w[N],k[N],t[M][M],vis[N];vector<int>v[M],e[N];
void dfs(int x,int e,int d){
    if(x==e){ans=min(ans,d);return;}
    if(d>=ans)return;
    for(auto y:v[x])if(!vis[y]){
        vis[y]=1;
        dfs(y,e,d+t[x][y]);
        vis[y]=0;
    }
}
void bfs(int x,int y){
    queue<pair<int,int> >q;
    q.push({x,0});vis[x]=1;
    while(!q.empty()){
        auto t=q.front().first,d=q.front().second;q.pop();
        if(t==y){ans=d;return;}
        for(auto y:e[t])for(auto z:v[y])if(!vis[z]){
            vis[z]=1;q.push({z,d+2});
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>op>>n>>m>>d>>q;
    if(op>=7&&op<=11){
        for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)t[i][j]=1e18;
        for(int i=1;i<=m;i++)cin>>w[i];
        for(int i=1;i<=n;i++){
            cin>>k[i];int x,y,z,zz;
            if(k[i]==1){cin>>x>>x;continue;}
            cin>>x>>z>>y>>zz;t[x][y]=min(t[x][y],z+zz);
            v[x].push_back(y);
        }
        while(q--){
            int x,y;ans=1e18;
            for(int i=1;i<=m;i++)vis[i]=0;
            cin>>x>>y;
            if(x>y)swap(x,y);
            dfs(x,y,0);
            cout<<ans+w[x]+w[y]<<'\n';
        }
        return 0;
    }
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];int x;
        for(int j=1;j<=k[i];j++)cin>>x,v[i].push_back(x),e[x].push_back(i),cin>>T;
    }
    while(q--){
        int x,y;
        for(int i=1;i<=m;i++)vis[i]=0;
        cin>>x>>y;
        if(x>y)swap(x,y);
        bfs(x,y);
        cout<<ans*T+w[x]+w[y]<<'\n';
    }
    return 0;
}
