#include <bits/stdc++.h>
using namespace std;
//本题答案需要开long long
const int CNT=1e6+5,N=1005,M=1e6+5;
struct edge{int v; long long c;};
vector<edge> g[M];//a 是地铁去地铁 g 是地铁站去线路
int n,m,d,q,cnt;
long long dis[N][N],w[M];//dis 是地铁去地铁的最短路 w 是口厅合并的长度
// struct B{
//     int u; long long c;
//     bool operator < (const B &ot) const{
//         return c>ot.c;
//     }
// }
// void dij(int s){
//     priority_queue<B> q;
//     for(int i=1;i<=n;i++){
//         dis[s][i]=1e15;
//     }
//     dis[s][s]=0; q.push(s);
//     while(q.size()){
//         B now=q.top(); q.pop();
//         if(dis[s][now.u]<now.c) continue;
//     }
//     return ;
// }
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int qgd; cin>>qgd;
    cin>>n>>m>>d>>q; cnt=n+m;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int X; cin>>X;
        for(int j=1;j<=X;j++){
            int tt; long long cc; cin>>tt>>cc;
            g[tt].push_back({i,cc});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) dis[i][j]=1e15;
        }
    }
    for(int id=1;id<=m;id++){
        for(edge e1:g[id]){
            for(edge e2:g[id]){
                int i=e1.v,j=e2.v;
                if(i!=j){
                    long long c=e1.c+e2.c;
                    dis[i][j]=dis[j][i]=min(dis[i][j],c);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        long long ans=1e15;
        int s,t; cin>>s>>t;
        for(edge e1:g[s]){
            for(edge e2:g[t]){
                int i=e1.v,j=e2.v;
                long long c=e1.c+e2.c;
                ans=min(ans,c+dis[i][j]);
            }
        }
        cout<<ans+w[s]+w[t]<<'\n';
    }
    return 0;
}
