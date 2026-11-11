#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
typedef pair<int,int>PI;
priority_queue<PI,vector<PI >,greater<PI > >q;
int c,n,m,d,T,a[N][10005],dis[1000005],vis[1000005],w[M],k[N];
struct node{
    int v,w;
};
vector<node>e[M];
vector<int>jg[M];
inline int read(){
    int sum=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        sum=sum*10+ch-'0';
        ch=getchar();
    }
    return sum*f;
}
// void dij(int x){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             dis[i*(m-1)+j]=1e18;
//             vis[i*(m-1)+j]=0;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         dis[i*(m-1)+x]=0;
//         q.push({0,i*(m-1)+x});
//     }
//     while(!q.empty()){
//         int u=q.top().second;
//         q.pop();
//         if(vis[u])continue;
//         vis[u]=1;
//         for(int i=0;i<e[u].size();i++){
//             int v=e[u][i].v,w=e[u][i].w;
//             int new_dis=dis[u]+w;
//             if(dis[v]>new_dis){
//                 dis[v]=new_dis;
//                 q.push({dis[v],v});
//             }
//         }
//     }
//     return;
// }
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),T=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int u,w;
            cin>>u>>w;
            e[i].push_back({u,w});
        }
    }
    // for(int i=1;i<=m;i++){
    //     if(jg[i].size()==1)continue;
    //     int u=jg[i][0];//线路
    //     for(int j=1;j<jg[i].size();j++){
    //         int v=jg[i][j];
    //         e[i].push_back({v*(m-1)+i,a[u][i]+a[v][i]});
    //     }
    // }
    while(T--){
        int x,y,res=0;
        x=read(),y=read();
        //dij(x);
        for(int i=1;i<=n;i++){
            res=e[i][0].w;
            int f=0;
            for(int j=0;j<e[i].size();j++){
                int v=e[i][j].v,w=e[i][j].w;
                if(v==y){
                    res+=w;
                    f=1;
                    break;
                }
            }
            if(f)break;
        }
        cout<<res+w[x]+w[y]<<"\n";
    }
    return 0;
}