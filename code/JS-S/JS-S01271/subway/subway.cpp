#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
const int N=505;
const int M=5e5+10;
const int D=25;
int c,n,m,dd,q,d[N][N],w[M],vis[N];
vector<pi> e[M],g[N];
void dijk(int s){
    memset(vis,0,sizeof(vis));
    d[s][s]=0;
    priority_queue<pi,vector<pi>,greater<pi> >q;
    q.push({d[s][s],s});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].first,w=g[u][i].second;
            if(d[s][v]>d[s][u]+w){
                d[s][v]=d[s][u]+w;
                q.push({d[s][v],v});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)d[i][j]=1e17;
            else d[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            e[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<e[i].size();j++){
            for(int v=j+1;v<e[i].size();v++){
                int id1=e[i][j].first,id2=e[i][v].first;
                d[id2][id1]=min(d[id2][id1],e[i][j].second+e[i][v].second);
                d[id1][id2]=min(d[id1][id2],e[i][j].second+e[i][v].second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i].push_back({j,d[i][j]});
            g[j].push_back({i,d[i][j]});
            if(i!=j)d[i][j]=1e17;
            else d[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        dijk(i);
    }
    while(q--){
        int s,t,ans=1e18;
        cin>>s>>t;
        for(int i=0;i<e[s].size();i++){
            for(int j=0;j<e[t].size();j++){
                int id1=e[s][i].first,id2=e[t][j].first;
                ans=min(ans,e[s][i].second+w[s]+w[t]+e[t][j].second+d[id1][id2]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//14:56 too long......
//14:59 graph again?
//15:03 a little difficult
//15:50 start
//16:28 test
//16:43 debug......
//17:03 2 second......
//17:20 give up......hope test computer is good enough
