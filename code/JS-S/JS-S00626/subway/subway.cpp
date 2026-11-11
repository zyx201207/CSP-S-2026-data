#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+2,N=5e2+2,INF=1e18;
int c,n,m,d,q;
int w[M],vis[N][N],road[N][N];
bool guo[N];
vector<pair<int,int> > vec[M];
priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > que;
inline void dij(int start){
    memset(guo,0,sizeof(guo));
    vis[start][start]=0;
    que.push({0,start});
    while(!que.empty()){
        auto root=que.top();
        que.pop();
        if(guo[root.second]){
            continue;
        }
        guo[root.second]=1;
        for(int i=1;i<=n;i++){
            if((road[root.second][i]!=0)&&(!guo[i])&&((vis[start][i]==0)||(vis[start][i]>vis[start][root.second]+road[root.second][i]))){
                vis[start][i]=vis[i][start]=vis[start][root.second]+road[root.second][i];
                que.push({vis[start][i],i});
            }
        }
    }
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        for(int j=1;j<=t;j++){
            int x,y;
            cin>>x>>y;
            for(auto to:vec[x]){
                if(road[i][to.first]==0){
                    road[i][to.first]=road[to.first][i]=to.second+y;
                }
                else{
                    road[i][to.first]=road[to.first][i]=min(vis[i][to.first],to.second+y);
                }
            }
            vec[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        dij(i);
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=INF;
        for(auto from:vec[x]){
            for(auto to:vec[y]){
                ans=min(ans,vis[from.first][to.first]+from.second+to.second+w[x]+w[y]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
