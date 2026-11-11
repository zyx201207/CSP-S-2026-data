#include<bits/stdc++.h>
#define int long long
#define gcu getchar_unlocked()
using namespace std;
const int N=505,M=5e5+5;
int w[M];
int n,m,d,q;
vector<int>g[M];
int dis[N][N];
int sub[N][M];
inline int read(){
    int f=1,x=0;
    char c=gcu;
    for(;!isdigit(c);c=gcu)if(c=='-')f=-1;
    for(;isdigit(c);c=gcu)x=x*10+(c^48);
    return x*f;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cont;
    cont=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        for(int j=1;j<=k;j++){
            int a,t;
            a=read(),t=read();
            g[a].push_back(i);
            sub[i][a]=t;
        }
    }
    for(int u=1;u<=m;u++){
        int len=g[u].size();
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(i==j)dis[g[u][i]][g[u][j]]=0;
                else dis[g[u][i]][g[u][j]]=min(dis[g[u][i]][g[u][j]],sub[g[u][i]][u]+sub[g[u][j]][u]);
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
        int x,y;
        x=read(),y=read();
        int lx=g[x].size(),ly=g[y].size();
        int ans=LONG_LONG_MAX;
        for(int i=0;i<lx;i++){
            for(int j=0;j<ly;j++){
                ans=min(ans,sub[g[x][i]][x]+dis[g[x][i]][g[y][j]]+sub[g[y][j]][y]);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
