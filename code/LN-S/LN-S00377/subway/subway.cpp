#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxm=5e5+5,mxn=505;
ll c,n,m,d,q;
ll dis[mxn][mxn];
ll w[mxm];
struct node{
    int idx;
    ll t;
};
vector<node> V[mxm];
void init(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int k=V[i].size()-1;
        for(int j=0;j<=k;j++){
            for(int r=j+1;r<=k;r++){
                int u=V[i][j].idx,v=V[i][r].idx;
                ll t=V[i][j].t+V[i][r].t;
                dis[u][v]=dis[v][u]=min(dis[u][v],t);
            }
        }
    }
}
void floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            for(int k=1;k<=n;k++){
                if(i==k || j==k) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll a,t;
            cin>>a>>t;
            V[a].push_back({i,t});
        }
    }
    /*
    for(int i=1;i<=m;i++){
        cout<<i<<": ";
        for(int j=0;j<V[i].size();j++){
            cout<<"a:"<<V[i][j].idx<<" t:"<<V[i][j].t<<" ";
        }
        cout<<"\n";
    }
    */
    init();
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    floyd();
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        ll ans=0x7f7f7f7f7f7f7f7f;
        for(int j=0;j<V[u].size();j++){
            ll uidx=V[u][j].idx,ut=V[u][j].t;
            for(int k=0;k<V[v].size();k++){
                ll vidx=V[v][k].idx,vt=V[v][k].t;
                //cout<<uidx<<" "<<ut<<" "<<vidx<<" "<<vt<<" "<<w[u]<<" "<<w[v]<<"\n";
                ans=min(ans,dis[uidx][vidx]+ut+vt+w[u]+w[v]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}