#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
//tip 注意时间是会爆int的！！！

const int MAXN = 5e2+5;
const int MAXM = 5e5+5;
#define ll long long
#define pil pair<int,ll>
// #define pli pair<ll,int>

int c,n,m,d,q;
ll w[MAXM];
vector<pil> con[MAXN];//存 线路 连的 站点&时间
vector<pil> tim[MAXM];//存 站点 连的 线路&时间

int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}

ll dis[MAXN][MAXN];
void Floyd(){
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        for(auto j1:con[i]){
            int x=j1.first;ll t1=j1.second;
            for(auto j2:tim[x]){
                int v=j2.first;ll t2=j2.second;
                dis[i][v]=min(dis[i][v],t1+t2);
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
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int a=read(),t1=read();
            tim[a].push_back(make_pair(i,t1));
            con[i].push_back(make_pair(a,t1));
        }
    }

    memset(dis,0x3f,sizeof(dis));

    Floyd();

    while(q--){
        int x=read(),y=read();
        ll ans=dis[0][0];
        for(auto j1:tim[x]){
            int i1=j1.first;ll t1=j1.second;
            for(auto j2:tim[y]){
                int i2=j2.first;ll t2=j2.second;
                ans=min(ans,t1+t2+w[x]+w[y]+dis[i1][i2]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}