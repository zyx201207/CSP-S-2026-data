#include<bits/stdc++.h>
// #define int long long
#define ll long long
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=505,M=5e5+5;const ll inf=1e18;
int n,m,d,q,cid,w[M],k[N];ll dis[N][N];bool vis[N];
struct stu{int to,w;};
vector<stu> g[M];
signed main(){
    freopen("subway.in" ,"r",stdin );
    freopen("subway.out","w",stdout);
    // freopen("1.in" ,"r",stdin );
    // freopen("1.out","w",stdout);
    cid=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++) {
        int k=read();
        for(int j=1;j<=k;j++) {
            int x=read(),t=read();
            g[x].push_back((stu){i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=m;k++) {
        vector<stu> &now=g[k];
        const int l=now.size();
        for(int i=0;i<l;i++) {
            const int u=now[i].to,c=now[i].w;
            for(int j=i+1;j<l;j++) {
                const int v=now[j].to,cost=c+now[j].w;
                if(dis[u][v]>cost) {dis[u][v]=dis[v][u]=cost;}
            }
        }
    }
    for(int i=1;i<=n;i++) for(int k=1;k<=n;k++) for(int j=1;j<=n;j++) {
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    while(q--) {
        int u=read(),v=read();ll mn=inf;
        vector<stu> &now=g[u];const int l=now.size();
        vector<stu> &p=g[v];const int len=p.size();
        for(int i=0;i<l;i++) {
            const int uu=now[i].to,c=now[i].w;
            for(int j=0;j<len;j++) {
                const int vv=p[j].to,cost=c+p[j].w;
                mn=min(mn,cost+dis[uu][vv]);
            }
        }
        printf("%lld\n",w[u]+w[v]+mn);
    }
    return 0;
}