#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500,M=5e5;
int c,n,m,d,q;
int w[M+5];
int k[N+5];
int dis[N+5][N+5];
struct ifmt{
    int k;
    vector<int>a,t;
}e[N+5]; //xianlu
struct pt{
    int dd;
    vector<int>xx,yy; //xx:which xianlu yy:which point
}p[M+5]; //zhandian
void pre(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dis[i][j]=1e15;
        }
    }
    for(int i=1;i<=n;++i) dis[i][i]=0;
    return ;
}
void sol1(){ //solve dis zhandian to zhandian
    for(int i=1;i<=m;++i){ //total jing guo xianlu
        p[i].dd=p[i].yy.size();
    }
    for(int l=1;l<=m;++l){
        for(int i=0;i<p[l].dd;++i){
            for(int j=0;j<i;++j){
                int tix=p[l].xx[i],tjx=p[l].xx[j];
                int tiy=p[l].yy[i],tjy=p[l].yy[j];
                dis[tix][tjx]=dis[tjx][tix]=min(dis[tix][tjx],e[tix].t[tiy]+e[tjx].t[tjy]);
            }
        }
    }
    for(int l=1;l<=n;++l){
        for(int i=1;i<=n;++i){
            if(dis[i][l]>=1e15) continue;
            for(int j=1;j<=i;++j){
                dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][l]+dis[j][l]);
            }
        }
    }
    return ;
}
int ans;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>e[i].k;
        for(int j=0;j<e[i].k;++j){
            int x,y;
            cin>>x>>y;
            e[i].a.push_back(x);
            e[i].t.push_back(y);
            p[x].xx.push_back(i);
            p[x].yy.push_back(j);
        }
    }
    pre();
    sol1();
    int x,y;
    int ux,vx;
    int uy,vy;
    while(q--){
        ans=1e14;
        cin>>x>>y;
        for(int i=0;i<p[x].dd;++i){
            uy=p[x].yy[i]; ux=p[x].xx[i];
            for(int j=0;j<p[y].dd;++j){
                vx=p[y].xx[j]; vy=p[y].yy[j];
                ans=min(ans,dis[ux][vx]+e[ux].t[uy]+e[vx].t[vy]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}