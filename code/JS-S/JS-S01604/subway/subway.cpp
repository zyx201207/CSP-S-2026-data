#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=550;
constexpr int M=5e5+10;
constexpr int D=22;
constexpr int Q=1e5+10;
constexpr int subM=2e4+10;
int c,n,m,d,q;
int w[M];
struct edge{
    int from,to,val;
};
struct node{
    int num,dis;
    bool operator < (const node& o) const{
        return dis>o.dis;
    }
};
/*
void solve_sub(){
    vector<vector<edge>> e(n*m+m+10);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        int pre=0;
        for(int j=1;j<=k;j++){
            int a,t; cin>>a>>t;
            e[a].emplace_back(edge{a,i*m+a,t});
            e[i*m+a].emplace_back(edge{i*m+a,a,t});
            if(j==1){
                pre=a;
                continue;
            }
            e[i*m+a].emplace_back(edge{i*m+a,i*m+pre,0});
            e[i*m+pre].emplace_back(edge{i*m+pre,i*m+a,0});
            pre=a;
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        vector<int> dist(n*m+m+10,1e14);
        vector<int> done(n*m+m+10,0);
        priority_queue<node> qwq;
        qwq.push({s,dist[s]=0});
        while(!qwq.empty()){
            node fn=qwq.top(); int u=fn.num;
            qwq.pop();
            if(done[u]) continue;
            done[u]=1;
            for(edge ee:e[u]){
                int v=ee.to;
                int w=ee.val;
                if(done[v]) continue;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    qwq.push({v,dist[v]});
                }
            }
        }
        cout<<dist[t]+w[s]+w[t]<<'\n';
    }
}*/
void solve_sub(){
    vector<vector<edge>> e(n*m+m+10);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        int pre=0;
        for(int j=1;j<=k;j++){
            int a,t; cin>>a>>t;
            e[a].emplace_back(edge{a,i*m+a,t});
            e[i*m+a].emplace_back(edge{i*m+a,a,t});
            if(j==1){
                pre=a;
                continue;
            }
            e[i*m+a].emplace_back(edge{i*m+a,i*m+pre,0});
            e[i*m+pre].emplace_back(edge{i*m+pre,i*m+a,0});
            pre=a;
        }
    }
    vector<vector<int>> res(m+10,vector<int>(m+10,0));
    for(int i=1;i<=m;i++){
        vector<int> dist(n*m+m+10,1e14);
        vector<int> done(n*m+m+10,0);
        priority_queue<node> qwq;
        qwq.push({i,dist[i]=0});
        while(!qwq.empty()){
            node fn=qwq.top(); int u=fn.num;
            qwq.pop();
            if(done[u]) continue;
            done[u]=1;
            for(edge ee:e[u]){
                int v=ee.to;
                int w=ee.val;
                if(done[v]) continue;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    qwq.push({v,dist[v]});
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(i!=j){
                res[i][j]=dist[j]+w[i]+w[j];
            }
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        cout<<res[s][t]<<'\n';
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    if(m<=1000){
        solve_sub(); //O(m*n*m*log(n*m))
    }else{
        solve_sub();
    }
    return 0;
}
/*
RP++
16:04 24pts
16:44 now 100+24+24+0=148,need solve more subs
16:55 32pts
16:58 subway4 local 1.6s,now 44pts
17:32 now 100+44+24+15=183
*/
