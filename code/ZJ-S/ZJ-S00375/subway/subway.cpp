#include <bits/stdc++.h>
// #define BIG
#define MID
#ifdef BIG
#define int __int128
#endif
#ifdef MID
#define int long long
#endif
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;
const int N=505,M=5e5+5;
int n,m,d,q,f[N][N],w[M];
vector<int> t[N];
vector<pii> G[M];
inline int read(){
    int ret=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
    while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
    return ret*f;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void writesp(int x){write(x),putchar(' ');}
inline void writeln(int x){write(x),putchar('\n');}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        int c=read();t[i].reserve(c+1);
        for(int j=1;j<=c;j++){
            int p=read();t[i][j]=read();
            G[p].emplace_back(i,t[i][j]);
        }
    }
    memset(f,63,sizeof f);
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<G[i].size();j++){
            for(int k=j+1;k<G[i].size();k++){
                int u=G[i][j].fi,v=G[i][k].fi,t=G[i][j].se,_t=G[i][k].se;
                f[u][v]=f[v][u]=min(f[u][v],t+_t);
            }
        }    
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x=read(),y=read(),ans=1e18;
        for(auto [p,t]:G[x])
            for(auto [_p,_t]:G[y])ans=min(ans,w[x]+t+w[y]+_t+f[p][_p]);
        writeln(ans);
    }
    return 0;
}