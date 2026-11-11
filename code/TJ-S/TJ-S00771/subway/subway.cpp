#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ulint=unsigned long long;
constexpr int MAXN=5e2+5,MAXM=5e5+5;
int c,n,m,d,q,x,y;
int k[MAXN];
int w[MAXM];
int a[MAXN][MAXM],t[MAXN][MAXM];
bitset<MAXM> vis;
std::priority_queue<pair<ulint,int>,vector<pair<ulint,int>>,greater<pair<ulint,int>>> que,q1;
vector<pair<int,int>> graph[MAXM];
ulint dis[MAXM];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=k[i];j++){
            for(int l=j+1;l<=k[i];l++){
                graph[a[i][j]].push_back({t[i][j]+t[i][l],a[i][l]});
                graph[a[i][l]].push_back({t[i][j]+t[i][l],a[i][j]});
            }
        }
    }
    while(q--){
        cin>>x>>y;
        for(int i=1;i<=m;i++){
            dis[i]=ULLONG_MAX;
        }
        dis[x]=0;
        que.push({dis[x],x});
        while(!que.empty()){
            ulint nowval=que.top().first,nowwhe=que.top().second;
            que.pop();
            if(vis[nowwhe]) continue;
            if(nowval>dis[nowwhe]) continue;
            vis[nowwhe]=1;
            for(int i=0;i<graph[nowwhe].size();i++){
                ulint nextval=graph[nowwhe][i].first,nextwhe=graph[nowwhe][i].second;
                if(dis[nowwhe]+nextval<dis[nextwhe]){
                    dis[nextwhe]=dis[nowwhe]+nextval;
                    que.push({dis[nextwhe],nextwhe});
                }
            }
        }
        cout<<dis[y]+w[x]+w[y]<<'\n';
        que=q1;
        vis.reset();
    }
    return 0;
}
