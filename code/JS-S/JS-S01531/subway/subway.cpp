#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;
int _,n,m,d,q,cnt;
int w[M],dis[N][N],ans[Q],gs[N];
int nowval[M];
vector<pair<int,int> > g[N];
vector<pair<int,int> > query[M];
vector<pair<int,int> > lai[M];
int in(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9') x=(x<<1)+(x<<3)+(c-'0'),c=getchar();
    return x*f;
}
struct ask{int x,y,id;}qq[Q];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    _=in(),n=in(),m=in(),d=in(),q=in();
    for(int i=1;i<=q;i++) ans[i]=1e17;
    for(int i=1;i<=m;i++) w[i]=in();
    for(int i=1;i<=n;i++){
        gs[i]=in();
        for(int j=1;j<=gs[i];j++){
            int aa,tt; aa=in(),tt=in();
            g[i].push_back({aa,tt});
            lai[aa].push_back({i,tt});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y; x=in(),y=in();
        qq[i]={x,y,i};
        query[x].push_back({y,i});
        query[y].push_back({x,i});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<gs[i];j++){
            int aa=g[i][j].first,tt=g[i][j].second;
            nowval[aa]=tt;
            for(int k=0;k<query[aa].size();k++){
                int y=query[aa][k].first,id=query[aa][k].second;
                if(nowval[y]==0) continue;
                ans[id]=min(ans[id],w[y]+w[aa]+nowval[y]+tt);
            }
        }
        for(int j=0;j<gs[i];j++){
            int aa=g[i][j].first,tt=g[i][j].second;
            nowval[aa]=0;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dis[i][j]=1e17;
    for(int i=1;i<=m;i++){
        for(int j=0;j<lai[i].size();j++){
            for(int k=j+1;k<lai[i].size();k++){
                int x=lai[i][j].first,y=lai[i][k].first;
                int wx=lai[i][j].second,wy=lai[i][k].second;
                dis[x][y]=min(dis[x][y],wx+wy);
                dis[y][x]=min(dis[y][x],wx+wy);
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
    for(int i=1;i<=q;i++){
        int x=qq[i].x,y=qq[i].y,id=qq[i].id;
        int res=1e17;
        for(int j=0;j<lai[x].size();j++){
            for(int k=0;k<lai[y].size();k++){
                int idx=lai[x][j].first,wx=lai[x][j].second;
                int idy=lai[y][k].first,wy=lai[y][k].second;
                res=min(res,w[x]+w[y]+wx+wy+dis[idx][idy]);
            }
        }
        ans[id]=min(ans[id],res);
    }
    for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    return 0;
}
