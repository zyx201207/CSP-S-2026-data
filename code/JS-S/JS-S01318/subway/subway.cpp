#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+10,M=520,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,qq,w[N],k[N],a[N][M],t[N][M],dis[N][M];
bool vis[N][M];
struct node{
    int ds,lx,pe;
    bool operator < (node A) const{
        return A.ds<ds;
    }
};
struct bs{
    int xl,id;
};
vector<bs>f[N];
void dijkstra(int st){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=d;j++){
            dis[i][j]=INF;
            vis[i][j]=0;
        }
    }
    priority_queue<node>q;
    for(bs u:f[st]){
        int uxl=u.xl,uid=u.id;
        dis[st][uxl]=w[st]+t[uxl][st];
        q.push({dis[st][uxl],uxl,uid});
    }
    while(!q.empty()){
        node u=q.top();
        q.pop();
        int uds=u.ds,ulx=u.lx,upe=u.pe;
        int unw=a[ulx][upe];
        if(vis[unw][ulx])continue;
        vis[unw][ulx]=1;
        if(upe<k[ulx]){
            if(uds<dis[a[ulx][upe+1]][ulx]){
                dis[a[ulx][upe+1]][ulx]=uds;
                q.push({uds,ulx,upe+1});
            }
        }
        if(upe>1){
            if(uds<dis[a[ulx][upe-1]][ulx]){
                dis[a[ulx][upe-1]][ulx]=uds;
                q.push({uds,ulx,upe-1});
            }
        }
        for(bs v:f[unw]){
            int vlx=v.xl,vpe=v.id;
            if(vlx==ulx)continue;

            int vds=uds+t[ulx][unw]+t[vlx][unw];

            if(vds<dis[unw][vlx]){
                dis[unw][vlx]=vds;
                q.push({vds,vlx,vpe});
            }
        }
    }
    return ;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            f[a[i][j]].push_back({i,j});
        }
    }
    while(qq--){
        int st,ed;
        cin>>st>>ed;
        dijkstra(st);
        int mn=INF;
        for(bs ff:f[ed]){
            int i=ff.xl;
            mn=min(mn,dis[ed][i]+w[ed]+t[i][ed]);
        }
        cout<<mn<<"\n";
    }
    return 0;
}
