#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define fir first
#define sec second
using namespace std;
const int N=5e2+7,M=5e5+7,Q=1e5+5;
int testcase;
int n/*地铁线路*/,m/*站台数*/,d,q;
vector<pair<int,int>> g[2*M+N];

int dis[2*M+N];
int ans[Q];
vector<pair<int,int>> ask[M];
void bfs(int s){
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pair<int,int>> q;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().sec;q.pop();
        for(auto vw:g[u]){
            int v=vw.fir,w=vw.sec;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push({-dis[v],v});
            }
        }
    }
}
void mian(){
    cin>>testcase;
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        int w;cin>>w;
        g[i].push_back({m+i,w});
        g[m+i].push_back({i,w});
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x,w;cin>>x>>w;
            g[2*m+i].push_back({x+m,w});
            g[x+m].push_back({2*m+i,w});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ask[x].push_back({y,i});
    }
    for(int i=1;i<=m;i++){
        if(!ask[i].size())continue;
        bfs(i);
        for(auto qu:ask[i]){
            int t=qu.fir,id=qu.sec;
            ans[id]=dis[t];
        }
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int _77231=1;
    // cin>>_77231;
    while(_77231--)mian();
    return 0;
}
// g[1~m]:地面
// g[m+1~2m]:站厅
// g[2m+1~2m+n]:路线
