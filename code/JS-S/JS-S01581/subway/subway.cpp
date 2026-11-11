#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+505;
int c,n,m,d,q;
int w[M],k[505];
int a,t;
int x,y;
struct node{
    int v,w;
};
vector<node> g[M];
int dis[505][505];
unordered_map<int,int> Dis[505];

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                dis[i][j]=4e18;
            }
        }
    }
    return ;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0),cout.tie(0)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            a+=n;
            Dis[i][a]=t;
            g[a].push_back({i,t});
        }
    }
    init();
    for(int i=n+1;i<=n+m;i++){
        for(int j=0;j<g[i].size()-1;j++){
            for(int k=j+1;k<g[i].size();k++){
                int u=g[i][j].v,v=g[i][k].v;
                int w1=g[i][j].w,w2=g[i][k].w;
                if(w1+w2<dis[u][v]){
                    dis[u][v]=dis[v][u]=w1+w2;
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]+dis[j][k]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[j][k];
                }
            }
        }
    }
    while(q--){
        cin>>x>>y;
        int sum=w[x]+w[y];
        x+=n,y+=n;
        int ans=4e18;
        for(int i=0;i<g[x].size();i++){
            for(int j=0;j<g[y].size();j++){
                int u=g[x][i].v,v=g[y][j].v;
                int num=dis[u][v]+Dis[u][x]+Dis[v][y];
                if(num<ans){
                    ans=num;
                }
            }
        }
        cout<<ans+sum<<"\n";
    }
    return 0;
}
