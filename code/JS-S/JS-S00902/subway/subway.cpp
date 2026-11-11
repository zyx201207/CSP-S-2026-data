#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M],dis[N][N];
vector<pii> vec[M];
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)  w[i]=read();
    for(int i=1,k;i<=n;i++){
        k=read();
        while(k--){
            int a=read(),t=read();
            vec[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int k=1;k<=m;k++){
        int l=vec[k].size();
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                int u=vec[k][i].fi,v=vec[k][j].fi;
                int w=vec[k][i].se+vec[k][j].se;
                dis[u][v]=dis[v][u]=min(dis[u][v],w);
            }
        }
    }
    for(int i=1;i<=n;i++)  dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)  dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    for(int i=1;i<=n;i++)  dis[i][i]=0;
    while(q--){
        int x=read(),y=read(),ans=0x3f3f3f3f3f3f3f3f;
        int l1=vec[x].size(),l2=vec[y].size();
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                int u=vec[x][i].fi,v=vec[y][j].fi;
                int w=vec[x][i].se+vec[y][j].se;
                ans=min(ans,dis[u][v]+w);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
/*
O(md^2+n^3+qd^2)
wish CCF let this 3.65e8 algorithm pass
*/
