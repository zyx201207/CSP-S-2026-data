#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using piii=pair<pii,int>;
const int N=505,M=5e5+5,D=25,Q=1e5+5,inf=1e9+7;
int c,n,m,d,q,w[M],x,y,k[N],a[N][M],t[N][M],time[N][M];
ll ans;
vector<piii>adj[N][M];
void dfs(int ls,int u,int now){
    if(id==y){
        time[N][M]=min(ans,now+w[u]+t[ls][u]);
        return;
    }
    for(auto next:adj[is][id]){
        int iss=next.first.first,v=next.first.second,add=next.second;

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int aa,tt;
            cin>>aa>>tt;
            a[i][aa]=1;
            t[i][aa]=t;
        }
        for(int u=1;u<=m;u++){
            for(int v=1;v<=m;v++){
                if(u!=v&&a[i][u]&&a[i][v])adj[i][u].push_back({i,v,0});
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(u!=v&&a[u][i]&&a[v][i])adj[u][i].push_back({v,i,k[u][i]+k[v][i]});
            }
        }
    }
    while(q--){
        cin>>x>>y;
        dfs();
        cout<<ans<<"\n";
    }
    return 0;
}
