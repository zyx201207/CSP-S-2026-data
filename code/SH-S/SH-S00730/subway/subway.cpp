#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=1e15+7;
int read(){
    int x=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar_unlocked();
    }
    while('0'<=c&&c<='9'){
        x=x*10+c-'0';
        c=getchar_unlocked();
    }
    return x*f;
}
inline int min(int a,int b){
    return a>b?b:a; 
}
constexpr int maxn=505;
constexpr int maxm=5e5+5;
bool DEBUG=false;
int c,n,m,d,q,w[maxm];
struct metro{
    int to,w;
};
metro met[maxm][205];
// zhantai -> xianlu
int tot[maxm];
int dis[maxn][maxn];
void in(){
    c=read();n=read();
    m=read();d=read();
    q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        int ki=read();
        for(int j=1;j<=ki;j++){
            int to,w;
            to=read();w=read();
            met[to][++tot[to]]={i,w};
            // met[to].push_back({i,w});
        }
    }
    
}
void debug_dis(){
    if(DEBUG){
        cout<<"================="<<endl;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(dis[i][j]==inf)
                    cout<<"INF ";
                else cout<<dis[i][j]<<" ";
                if(j==n)cout<<endl;
            }
        cout<<"================="<<endl;
    }
}
void init(){
    for(int i=1;i<=m;i++){
        int xls=tot[i];
        for(int j=1;j<xls;j++){
            for(int k=j+1;k<=xls;k++){
                int u=met[i][j].to,v=met[i][k].to;
                dis[u][v]=min(dis[u][v],met[i][j].w+met[i][k].w);
                dis[v][u]=min(dis[v][u],met[i][j].w+met[i][k].w);
            }
        }
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    debug_dis();
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    in();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=inf;
    init();
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    debug_dis();
    while(q--){
        int x,y;
        x=read(),y=read();
        int ans=inf;
        int xlsx=tot[x];
        int xlsy=tot[y];
        for(int i=1;i<=xlsx;i++)
            for(int j=1;j<=xlsy;j++){
                auto u=met[x][i];
                auto v=met[y][j];
                ans=min(ans,w[x]+w[y]+dis[u.to][v.to]+u.w+v.w);
            }
        // for(auto u:met[x])
        //     for(auto v:met[y])
        //         ans=min(ans,w[x]+w[y]+dis[u.to][v.to]+u.w+v.w);
        printf("%lld\n",ans);
    }
    return 0;
}