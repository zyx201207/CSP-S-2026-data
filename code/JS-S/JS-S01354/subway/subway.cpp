#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+5;
const int N=2505;
int c,m,n,d,q,w[M],k[N],kpre[N],x[M],y[M],dis1[N][N],dis2[M];
vector<int>line[N];
bool vis[M];
struct node{
    int v,w;
};
vector<node>g[M+N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int edge=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        kpre[i]=kpre[i-1]+k[i];
        for(int j=1;j<=k[i];j++){
            int sta;cin>>sta;
            int t;cin>>t;
            g[sta].push_back({kpre[i-1]+j+m,t});
            g[kpre[i-1]+j+m].push_back({sta,t});
            edge+=2;
            if(j>1){
                g[kpre[i-1]+j+m].push_back({kpre[i-1]+j-1+m,0});
                g[kpre[i-1]+j-1+m].push_back({kpre[i-1]+j+m,0});
                edge+=2;
            }
        }
    }
    // for(int u=1;u<=kpre[n]+m;u++){
    //     cout<<u<<":";
    //     for(auto v:g[u]){
    //         cout<<v.v<<' ';
    //         //dis1[u][v.v]=v.w;
    //     } 
    //     cout<<'\n';
    // }
    if(c<=11){
        memset(dis1,0x3f,sizeof(dis1));
        for(int i=1;i<=kpre[n]+m;i++){
            dis1[i][i]=0;
        }
        for(int u=1;u<=kpre[n]+m;u++){
            for(auto v:g[u]){
                dis1[u][v.v]=v.w;
            }
        }
        for(int k=1;k<=kpre[n]+m;k++){
            for(int i=1;i<=kpre[n]+m;i++){
                for(int j=1;j<=kpre[n]+m;j++){
                    dis1[i][j]=min(dis1[i][j],dis1[i][k]+dis1[k][j]);
                }
            }
        }
        // for(int i=1;i<=kpre[n]+m;i++){
        //     for(int j=1;j<=kpre[n]+m;j++){
        //         cout<<dis1[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<dis1[x][y]+w[x]+w[y]<<'\n';
        }
    }
    else if(c<=19){
        while(q--){
            int x,y;
            cin>>x>>y;
            deque<node>que;
            que.emplace_back(node{x,0});
            while(!que.empty()){
                auto u=que.front();
                que.pop_front();
                for(auto v:g[u.v]){
                    if(dis2[v.v]){
                        continue;
                    }
                    dis2[v.v]=dis2[u.v]+g[u.v][v.v].w;
                    if(g[u.v][v.v].w>0){
                        que.emplace_back(node{v.v,g[u.v][v.v].w});
                    }
                    else{
                        que.emplace_front(node{v.v,0});
                    }
                }
            }
            cout<<dis2[y]+w[x]+w[y]<<' ';
        }
    }
    return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/