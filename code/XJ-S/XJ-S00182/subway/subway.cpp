#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M],x,y;
vector<int> T[N];//存经过该点的线路
struct node{
    int to,w;
    bool operator<(const node &other) const{
        return w<other.w;
    }
};
int dist[M][M];//dist[i][j]:从i点出发到j点的最短路径长
void bfs(int start){
    priority_queue<node> q;
    q.push({start,0});
    dist[start][start]=0;
    while(!q.empty()){
        auto cur=q.top();
        q.pop();
        int u=cur.to,d=cur.w;
        for(auto j:T[u]){//遍历每一条线路 //j:第j条线路
            for(int nxt=1;nxt<=k[j];nxt++){//这里是每一条线路上能到达的点
                //这里计算的距离指的是站厅到站厅的距离
                int v=a[j][nxt];
                int w=/*u站厅到这条线路的站台+这条线路的站台到v站厅*/t[j][u]+t[j][v];
                if(dist[start][u]+w<dist[start][v]){
                    dist[start][v]=dist[start][u]+w;
                    q.push({v,dist[start][v]});
                    // cout<<"j:"<<j<<'\n';
                    // printf("%d->%d,w=%d,dist[%d]=%d\n",u,v,w,v,dist[start][v]);
                }
            }
        }
        // queue<node> q2;
        // while(!q.empty()){
        //     q2.push(q.front());
        //     cout<<"xxx:"<<q.front().to;
        //     q.pop();
        // }
        // while(!q2.empty()){
        //     q.push(q2.front());
        //     q2.pop();
        // }
        // cout<<'\n';
    }
}
int g[M][M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dist,0x3f,sizeof(dist));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][a[i][j]];
            T[a[i][j]].push_back(i);
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(int j:T[i]){
    //         for(int l=1;l<=k[j];l++){
    //             g[i][a[j][l]]=
    //         }
    //     }
    // }
    // for(int i=1;i<=m;i++){
    //     for(int j:T[i]){
    //         cout<<j<<' ';
    //     }
    //     cout<<'\n';
    // }
    for(int i=1;i<=m;i++){
        bfs(i);
    }

    // for(int k=1;k<=m;k++){
    //     for(int i=1;i<=m;i++){
    //         for(int j=1;j<=m;j++){

    //         }
    //     }
    // }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<setw(10)<<dist[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<dist[x][y]+w[x]+w[y]<<"\n";
    }
    
}