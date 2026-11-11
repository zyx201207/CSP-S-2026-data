#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
struct Edge{
    int sta;int wa;bool vis;
};
int c,n,m,d,q,w[MAXN],ans;
vector<Edge>g[MAXN];//first:station|second:way
int t[505][1005];
//    way  station
void dfs(int u,int nd,int ti,int way,int &ans){
    if(u==nd){
        ans=min(ans,ti+t[way][u]+w[u]);
        return;
    }
    for(auto &ed:g[u]){
        if(ed.vis==true)continue;
        int station=ed.sta;
        int nway=ed.wa;
        ed.vis=1;
        if(nway==way)dfs(station,nd,ti,way,ans);
        else{
            dfs(station,nd,ti+t[way][u]+t[nway][u],nway,ans);
        }
        ed.vis=0;
    }
    return;
}
signed main()
{
//#ifndef ZYdeBuG
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
//#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;int last=0;
        for(int j=1;j<=k;j++){
            int sub,time;
            cin>>sub>>time;
            t[i][sub]=time;
            if(j!=1){
                g[sub].push_back({last,i,0});
                g[last].push_back({sub,i,0});
            }
            last=sub;
        }
    }
    while(q--){
        int x,y,ans=LLONG_MAX;
        cin>>x>>y;
        if(x==y){
            cout<<0<<'\n';
            continue;
        }
        dfs(x,y,w[x],0,ans);
        cout<<ans<<'\n';
    }
    return 0;
}




